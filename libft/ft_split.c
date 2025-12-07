/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzebian <kzebian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 18:24:30 by kzebian           #+#    #+#             */
/*   Updated: 2025/06/03 22:59:55 by kzebian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static int	seperator(char c, char a)
{
	if (c == a || c == '\0')
		return (1);
	return (0);
}

static void	write_word(char *str, char const *from, char c)
{
	int	i;

	i = 0;
	while (!seperator(from[i], c))
	{
		str[i] = from[i];
		i++;
	}
	str[i] = '\0';
}

static void	*create_word(char **split, int word, int j)
{
	split[word] = (char *)malloc(sizeof(char) * (j + 1));
	if (!split[word])
	{
		while (word > 0)
			free(split[--word]);
		return (NULL);
	}
	return ((void *)1);
}

static int	*write_split(char **split, char const *str, char c)
{
	int	i;
	int	j;
	int	words;

	words = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			i++;
		else
		{
			j = 0;
			while (!seperator(str[i + j], c))
				j++;
			if (!create_word(split, words, j))
				return (NULL);
			write_word(split[words], str + i, c);
			i += j;
			words++;
		}
	}
	return ((void *)1);
}

char	**ft_split(char const *s, char c)
{
	char	**final;
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	str = (char *)s;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (!seperator(s[i], c) && seperator(s[i + 1], c))
			j++;
		i++;
	}
	final = (char **)malloc(sizeof(char *) * (j + 1));
	if (!final)
		return (NULL);
	final[j] = 0;
	if (!write_split(final, str, c))
		return (NULL);
	return (final);
}

// #include <stdio.h>
// #include <stdlib.h>

// char **ft_split(char const *s, char c);

// int	main(void)
// {
// 	char const *str = "salut,comment,tu,vas";
// 	char **res = ft_split(str, ',');

// 	int i = 0;
// 	while (res[i])
// 	{
// 		printf("Mot %d: %s\n", i + 1, res[i]);
// 		free(res[i]);
// 		i++;
// 	}
// 	free(res);
// 	return 0;
// }