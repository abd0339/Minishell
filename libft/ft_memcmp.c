/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzebian <kzebian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 20:08:08 by kzebian           #+#    #+#             */
/*   Updated: 2025/06/03 22:52:43 by kzebian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*temp;
	unsigned char	*temp1;

	i = 0;
	temp = (unsigned char *)s1;
	temp1 = (unsigned char *)s2;
	while (i < n)
	{
		if (temp[i] != temp1[i])
			return ((temp[i] - temp1[i]));
		i++;
	}
	return (0);
}

// #include"stdio.h"
// #include <string.h>

// int main(void)
// {
// 	const char *S1 = "karine";
// 	const char *S2 = "zebian";

// 	int result = ft_memcmp(S1, S2, 3);
// 	printf("%d\n", result);
// 	return 0;
// }