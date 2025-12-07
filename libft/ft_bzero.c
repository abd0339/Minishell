/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzebian <kzebian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 19:10:20 by kzebian           #+#    #+#             */
/*   Updated: 2025/05/26 18:20:14 by kzebian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	char			*temp;

	temp = (char *)s;
	i = 0;
	while (i < n)
	{
		temp[i] = 0;
		i++;
	}
}

// #include<stdio.h>
// int main(void)
// {
//     char    str[3] = {"abc"};

//     ft_bzero(str, 7);

//     for (int i = 0; i < 3; i++)
//         printf("%c", str[i]);

//     return (0);
// }