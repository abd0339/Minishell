/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzebian <kzebian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 22:12:07 by kzebian           #+#    #+#             */
/*   Updated: 2025/05/26 19:31:47 by kzebian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*temp;
	unsigned char	*temp1;

	temp = (unsigned char *)dest;
	temp1 = (unsigned char *)src;
	i = 0;
	if (temp1 < temp)
	{
		while (0 < n)
		{
			temp[n - 1] = temp1[n - 1];
			n--;
		}
	}
	else
	{
		while (i < n)
		{
			temp[i] = temp1[i];
			i++;
		}
	}
	return (dest);
}

// #include"stdio.h"
// #include <string.h>

// int main(void)
// {
// 	char S1[10] = "kari"; 
// 	const char *S2 = "zebian"; 
// 	char *res = ft_memmove(S1, S2, 5);
// 	printf("%s\n", res);
// 	return 0;
// }