/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzebian <kzebian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 02:48:03 by kzebian           #+#    #+#             */
/*   Updated: 2025/05/26 20:12:06 by kzebian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static int	trim(char const *s1, char c)
{
	int	i;

	i = 0;
	while (s1[i])
	{
		if (s1[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*st;
	size_t	i;
	size_t	newlen;

	i = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		st = malloc(1);
		st[0] = '\0';
		return (st);
	}
	newlen = ft_strlen(s + start);
	if (len > newlen)
		len = newlen;
	st = (char *)malloc(sizeof(char) * (len + 1));
	if (!st)
		return (NULL);
	while (s[start] && i < len)
	{
		st[i++] = s[start++];
	}
	st[i] = '\0';
	return (st);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*st;
	int		i;
	int		j;

	i = 0;
	j = ft_strlen(s1) - 1;
	if (!s1)
		return (NULL);
	if (ft_strlen(s1) == 0)
	{
		st = malloc(1);
		st[0] = '\0';
		return (st);
	}
	while (trim(set, s1[i]))
		i++;
	while (trim(set, s1[j]))
		j--;
	return (ft_substr(s1, i, j - (i - 1)));
}

// #include <stdio.h>

// int main(void)
// {
// 	char *s = "   \t\nHello, world! \n\t ";
// 	char *set = " \n\t";
// 	char *trimmed;

// 	trimmed = ft_strtrim(s, set);
// 	if (trimmed)
// 	{
// 		printf("Original: [%s]\n", s);
// 		printf("Trimmed:  [%s]\n", trimmed);
// 		free(trimmed);
// 	}
// 	return 0;
// }