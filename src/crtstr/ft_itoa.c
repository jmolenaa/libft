/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmolenaa <jmolenaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/17 07:27:05 by jmolenaa      #+#    #+#                 */
/*   Updated: 2023/07/17 09:34:27 by jmolenaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/**
 * Converts the given integer to a string
 * Returns an allocated string or NULL on malloc failure
*/

static int	countdigits(int n)
{
	int	digits;

	digits = 0;
	if (n / 10)
	{
		n = n / 10;
		digits = countdigits(n);
	}
	digits++;
	return (digits);
}

static void	makestring(char *s, long int nbr, int sign, int digit)
{
	char	c;

	if (digit)
	{
		digit--;
		c = nbr % 10 + '0';
		*(s + sign + digit) = c;
		nbr = nbr / 10;
		makestring(s, nbr, sign, digit);
	}
}

char	*ft_itoa(int n)
{
	int			digit;
	char		*s;
	int			sign;
	long int	nbr;

	nbr = n;
	digit = countdigits(nbr);
	sign = 0;
	if (n < 0)
	{
		sign = 1;
		nbr = nbr * -1;
	}
	s = (char *)malloc((digit + 1 + sign) * sizeof(char));
	if (!s)
		return (NULL);
	if (sign == 1)
		*s = '-';
	makestring(s, nbr, sign, digit);
	*(s + sign + digit) = '\0';
	return (s);
}
