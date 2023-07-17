/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmolenaa <jmolenaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/07 12:45:48 by jmolenaa      #+#    #+#                 */
/*   Updated: 2023/07/17 09:31:22 by jmolenaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

/**
 * Copies 'n' bytes from memory 'src' to 'dst'
 * Memory overlap is undefined
 * Returns the original value of 'dst'
*/

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (dst == src)
		return (dst);
	while (i < n)
	{
		*((char *) dst + i) = *((char *) src + i);
		i++;
	}
	return (dst);
}
