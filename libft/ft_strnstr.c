/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzebian <kzebian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 22:38:44 by kzebian           #+#    #+#             */
/*   Updated: 2025/05/24 23:52:52 by kzebian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t a)
{
	size_t	i;
	size_t	j;
	size_t	n;

	i = 0;
	if (*to_find == '\0')
	{
		return ((char *)str);
	}
	while (str[i] && i < a)
	{
		j = 0;
		n = i;
		while (to_find[j] == str[i + j] && i + j < a && to_find[j])
			j++;
		if (to_find[j] == '\0')
			return ((char *)&str[n]);
		i++;
	}
	return (NULL);
}
