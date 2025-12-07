/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzebian <kzebian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 22:03:57 by kzebian           #+#    #+#             */
/*   Updated: 2025/05/24 17:38:26 by kzebian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strdup(char *src)
{
	int		i;
	int		j;
	char	*c;

	i = 0;
	j = 0;
	while (src[i])
		i++;
	c = (char *)malloc(sizeof(char) * (i + 1));
	if (!c)
		return (NULL);
	while (src[j])
	{
		c[j] = src[j];
		j++;
	}
	c[i] = '\0';
	return (c);
}
