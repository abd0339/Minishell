/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzebian <kzebian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 19:40:51 by kzebian           #+#    #+#             */
/*   Updated: 2025/05/26 19:02:49 by kzebian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*temp;
	unsigned char	a;

	temp = (unsigned char *)s;
	i = 0;
	a = (unsigned char)c;
	while (i < n)
	{
		if (temp[i] == a)
			return ((void *) &temp[i]);
		i++;
	}
	return (NULL);
}

// #include<stdio.h>

// int	main(void)
// {
// 	char	*c = "Bonjour koko";
// 	int		s = 'k';
// 	char	*result;
// 	result = ft_memchr(c, s, 10);
// 	if (result)
// 		printf("%c\n", *result);
// 	return (0);
// }