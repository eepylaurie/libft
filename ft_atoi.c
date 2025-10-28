/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatthes <lmatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 13:59:58 by lmatthes          #+#    #+#             */
/*   Updated: 2025/10/28 15:45:50 by lmatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	sign;
	int	result;

	while ((*nptr == ' ') || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	sign = 1;
	if ((*nptr == '+') || (*nptr == '-'))
		if (*nptr++ == '-')
			sign *= -1;
	result = 0;
	while (*nptr >= '0' && *nptr <= '9')
		result = result * 10 + (*nptr++ - '0');
	return (sign * result);
}
