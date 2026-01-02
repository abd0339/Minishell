/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afahs <afahs@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 19:12:42 by afahs             #+#    #+#             */
/*   Updated: 2025/06/05 06:41:58 by afahs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t			i;
	size_t			j;

	i = 0;
	if (!little[i])
		return ((char *)big);
	while (big[i] && i < len)
	{
		j = 0;
		while (big[i + j] == little[j] && i + j < len && little[j])
			j++;
		if (little[j] == 0)
			return ((char *)big + i);
		i++;
	}
	return (0);
}

// #include <stdio.h>
// int main(void)
// {
// 	char c[4] ;
// 	char c1[4];

// 	*c = NULL;
// 	c1[0] = 's';
// 	printf("%s \n", ft_strnstr(c, c1, 5));
	
// 	return (0);
// }
