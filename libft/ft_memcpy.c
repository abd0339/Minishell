/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzebian <kzebian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 21:45:18 by kzebian           #+#    #+#             */
/*   Updated: 2025/05/26 19:23:20 by kzebian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t					i;
	unsigned char			*temp;
	unsigned const char		*temp1;

	temp = (unsigned char *)dest;
	temp1 = (unsigned const char *)src;
	i = 0;
	while (i < n)
	{
		temp[i] = temp1[i];
		i++;
	}
	return (dest);
}

// #include"stdio.h"
// #include <string.h>

// int main(void)
// {
// 	char S1[10] = "12"; 
// 	const char *S2 = "zebian"; 
// 	char *res = ft_memcpy(S1, S2, 3);
// 	printf("%s\n", res);
// 	return 0;
// }