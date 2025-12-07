/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzebian <kzebian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 21:48:59 by kzebian           #+#    #+#             */
/*   Updated: 2025/05/24 23:41:37 by kzebian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	srclen;

	i = 0;
	j = 0;
	srclen = ft_strlen(src);
	while (dest[i])
		i++;
	if (i >= size)
		return (srclen + size);
	if (size == 0)
		return (srclen);
	while (src[j] && (i + j < size - 1))
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (i + srclen);
}

// int main(void)
// {
// 	char dest[30];
// 	memset(dest, 0, 30);
// 	char * src = (char *)"AAAAAAAAA";

// 	memset(dest, 'B', 4);
// 	int x = ft_strlcat(dest, src, 6);
// 	printf("S%sS\n", dest);
// 	printf("D%dD\n", x);
// }