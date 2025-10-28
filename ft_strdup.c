/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatthes <lmatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 11:50:30 by lmatthes          #+#    #+#             */
/*   Updated: 2025/10/28 16:10:33 by lmatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*dest;
	char	*d;

	len = ft_strlen(s);
	dest = malloc(len + 1);
	if (!dest)
		return (NULL);
	d = dest;
	while (*s)
		*d++ = *s++;
	*d = '\0';
	return (dest);
}
