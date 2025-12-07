/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzebian <kzebian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 18:54:06 by kzebian           #+#    #+#             */
/*   Updated: 2025/05/26 19:37:08 by kzebian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*temp;

	temp = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		temp[i] = (unsigned char)c;
		i++;
	}
	return (s);
}

// #include"stdio.h"

// int	main(void)
// {
// 	unsigned char	str[10] = {"abchyg"};

// 	ft_memset(str, 2, 6);
// 	for (int i = 0; i < 5; i++)
// 		printf("%d", str[i]);
// 	printf("%s\n", "");
// }