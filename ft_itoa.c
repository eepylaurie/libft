/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatthes <lmatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 11:11:18 by lmatthes          #+#    #+#             */
/*   Updated: 2025/10/28 15:51:54 by lmatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intlen(long n)
{
	int	len;

	len = 0;
	if (n < 0)
	{
		n *= -1;
		len++;
	}
	else if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	long	nb;
	int		i;
	char	*s;

	nb = n;
	i = ft_intlen(nb);
	s = (char *)malloc(i + 1);
	if (!s)
		return (NULL);
	s[i--] = '\0';
	if (nb == 0)
		s[i] = '0';
	else if (nb < 0)
	{
		s[0] = '-';
		nb *= -1;
	}
	while (nb > 0)
	{
		s[i] = '0' + (nb % 10);
		nb /= 10;
		i--;
	}
	return (s);
}
