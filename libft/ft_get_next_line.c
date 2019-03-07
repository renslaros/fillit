/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: rlaros <rlaros@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/07 14:39:49 by rlaros         #+#    #+#                */
/*   Updated: 2019/03/05 18:04:46 by rlaros        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
** @desc Retrieves index of \n if present. If not it retrieves index of \0.
** @param char *stack_item - item of the static stack array
** @var unsigned int i - Iterator used to loop over stack_item characters.
** @return unsigned int - Either Index Pos. of \n or \0 if no \n can be found
*/

/*
** - Loop over char *stack_item until \n or \0 has been found.
** - Increase iterator while doing so.
** - Return iterator which will be the index equalling the position of \n or \0
*/

static unsigned int	ft_get_endl_or_null_pos(char *stack_item)
{
	unsigned int i;

	i = 0;
	while (stack_item[i] != '\n' && stack_item[i] != '\0')
		i++;
	return (i);
}

/*
** @desc Joins the current stack_item string with the newly read buff string
** @param char *stack_item - item of the static stack array
** @param char *buff - string read from fd based on dynamic buff size
** @param size_t len - length of second string. len + strlen(stack_item) = total
** @var char *fresh - fresh char* to store and return joined string
** @var char *tmp - temporary char* used to store first index of fresh char*
** @return char * - first index of fresh char array stored as tmp
*/

/*
** - Allocate the required memory for the fresh string using ft_strnew()
** - Pass the result of ft_strlen(stack_item) + len + 1 to ft_strnew()
** - Store adress of first index from char *fresh in tmp
** - As long as there are chars in stack_item, iterate over the indexes
** - Store the values in fresh and increase that index while looping as well
** - Once stack_item has been put into fresh, we loop while (*buff && len > 0)
** - We put the contents of *buff in *fresh after the contents of *stack_item
** - We increase both the index of fresh and buff while decreasing length
** - After stack_item & buff have been joined into fresh, we add a \0 at the end
** - We return the first index of the fresh char array currently stored in tmp
*/

static char			*ft_joiner(char *stack_item, char *buff, size_t len)
{
	char		*fresh;
	char		*tmp;

	fresh = ft_strnew(((ft_strlen(stack_item) + len) + 1));
	tmp = fresh;
	while (*stack_item)
	{
		*fresh = *stack_item;
		fresh++;
		stack_item++;
	}
	while (*buff && len > 0)
	{
		*fresh = *buff;
		fresh++;
		buff++;
		len--;
	}
	*fresh = '\0';
	return (tmp);
}

/*
** @desc Checks whether there's a \n or if there's something in stack_item.
** @desc If one of the conditions match, it uses ft_strcpy() accordingly.
** @param char *stack_item - item of the static stack array
** @return char *stack_item - adress of first char in stack_item string
** @return NULL if there is no \n in the stack_item string && index of \0 != > 0
*/

/*
** - Check if there is a \n in stack_item
** -	If so: Override stack_item with everything after the \n
** - 	Return first position of ''fixed'' stack_item
** - Check if there's an index with \0 > 0
** - 	If so: Override stack_item with everything starting @ \0
** - In case both conditions aren't met, we return NULL
*/

static char			*ft_check_and_copy(char *stack_item)
{
	if (ft_strchr(stack_item, ENDL))
	{
		ft_strcpy(stack_item, ft_strchr(stack_item, ENDL) + 1);
		return (stack_item);
	}
	if (ft_get_endl_or_null_pos(stack_item) > 0)
	{
		ft_strcpy(stack_item, ft_strchr(stack_item, '\0'));
		return (stack_item);
	}
	return (NULL);
}

/*
** @desc Gets next line from given file descriptor and stores it in received ptr
** @param int const fd - Filedescriptor
** @param char **line - Line pointer
** @var static char* stack[MAX_FD] - 2d array used to store strings on FD index
** @var char *ptr - Points to a certain stack[fd]
** @var char buff[BUFF_SIZE + 1] - Stores buffer read from the read function.
** @var int retval - Stores return value of standard read function.
** @return int -1 on unsuccessfull read of line / invalid input
** @return int 1 on successfull read of line without it being the last line
** @return int 0 on successfull read of last line in filedescriptor
*/

/*
** - set retval to 1; making sure we can go in the loop the first time
** - Validate input & memory allocation attempt. If invalid return -1
** - Loop until there's a \n in stack[fd] as long as retval > 0
** - 	Set retval to the return value of read(fd, buff, BUFF_SIZE)
** -	Set a \0 at buff[retval]
** - 	point ptr to adress of stack[fd]
** - 	Set stack[fd] to the return value of ft_joiner(ptr, buff, retval)
** - 	free ptr adress since ft_joiner returned a new adress for stack[fd]
** - Set line pointer to the return value of ft_strsub()
** - This will be a substring of stack[fd] starting at 0 until \n or \0
** - Return 0 or 1 based on the return value of ft_check_and_copy(stack[fd])
*/

int					ft_get_next_line(int const fd, char **line)
{
	static char		*stack[MAX_FD];
	char			*ptr;
	char			buff[BUFF_SIZE + 1];
	int				retval;

	retval = 1;
	if (fd < 0 || BUFF_SIZE < 1 || !line || read(fd, buff, 0) < 0)
		return (-1);
	if (!(stack[fd]))
	{
		stack[fd] = ft_strnew(0);
		if (stack[fd] == NULL)
			return (-1);
	}
	while (!(ft_strchr(stack[fd], ENDL)) && retval > 0)
	{
		retval = read(fd, buff, BUFF_SIZE);
		buff[retval] = '\0';
		ptr = stack[fd];
		stack[fd] = ft_joiner(ptr, buff, retval);
		free(ptr);
	}
	*line = ft_strsub(stack[fd], 0, ft_get_endl_or_null_pos(stack[fd]));
	return (ft_check_and_copy(stack[fd]) == NULL ? 0 : 1);
}
