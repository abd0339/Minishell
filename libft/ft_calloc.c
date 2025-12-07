/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzebian <kzebian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 21:42:46 by kzebian           #+#    #+#             */
/*   Updated: 2025/05/26 18:37:40 by kzebian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t			i;
	unsigned char	*temp;

	i = 0;
	if (size != 0 && (nmemb * size) / size != nmemb)
		return (NULL);
	temp = malloc(nmemb * size);
	if (!temp)
		return (NULL);
	while (i < nmemb * size)
	{
		temp[i] = 0;
		i++;
	}
	return (temp);
}

// #include<stdio.h>

// int	main(void)
// {
// 	int		*arr;
// 	size_t	n;

// 	n = 8;
// 	arr = (int	*)ft_calloc(8, sizeof(int));
// 	for (size_t i = 0; i < n; i++)
// 	{
// 		printf("%d\n", i, arr[i]);
// 	}
// 	free(arr);
// 	return 0;
// }
