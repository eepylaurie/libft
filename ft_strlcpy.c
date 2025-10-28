/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatthes <lmatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 14:09:04 by lmatthes          #+#    #+#             */
/*   Updated: 2025/10/28 16:24:33 by lmatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t		len;
	char		*d;
	const char	*s;

	d = dst;
	s = src;
	len = ft_strlen(src);
	if (size == 0)
		return (len);
	while (*s && (size-- > 1))
		*d++ = *s++;
	*d = '\0';
	return (len);
}
