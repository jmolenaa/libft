/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmolenaa <jmolenaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/11 12:15:34 by jmolenaa      #+#    #+#                 */
/*   Updated: 2023/07/17 09:31:35 by jmolenaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

/**
 * Copies 'n' bytes from memory 'src' to 'dst'
 * The memory may overlap
 * Returns the original value of 'dst'
*/

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t		i;

	i = 0;
	while (i < len)
	{
		if (dst > src)
			*((char *)dst + len - i - 1) = *((char *)src + len - i - 1);
		else if (dst < src)
			*((char *)dst + i) = *((char *)src + i);
		else
			return (dst);
		i++;
	}
	return (dst);
}
