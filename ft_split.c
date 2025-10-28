/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatthes <lmatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 15:57:41 by lmatthes          #+#    #+#             */
/*   Updated: 2025/10/28 13:41:06 by lmatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_parts(const char *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

static char	*part_split(const char *s, char c)
{
	char	*part;
	int		i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	part = (char *)malloc(sizeof(char) * (i + 1));
	if (!part)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != c)
	{
		part[i] = s[i];
		i++;
	}
	part[i] = '\0';
	return (part);
}

static void	free_arr(char **arr, int j)
{
	while (j > 0)
	{
		j--;
		free(arr[j]);
	}
	free(arr);
}

static int	split_fill(char **arr, const char *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			arr[j] = part_split(&s[i], c);
			if (!arr[j])
			{
				free_arr(arr, j);
				return (0);
			}
			while (s[i] && s[i] != c)
				i++;
			j++;
		}
		else
			i++;
	}
	arr[j] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;

	if (!s)
		return (NULL);
	arr = malloc(sizeof(char *) * (count_parts(s, c) + 1));
	if (!arr)
		return (NULL);
	if (!split_fill(arr, s, c))
		return (NULL);
	return (arr);
}
