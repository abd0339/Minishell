/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzebian <kzebian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 18:19:16 by kzebian           #+#    #+#             */
/*   Updated: 2025/05/26 19:44:36 by kzebian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	a;

	i = 0;
	a = (char)c;
	while (s[i] && (s[i] != a))
		i++;
	if (s[i] == a)
		return ((char *) & s[i]);
	return (NULL);
}

// #include<stdio.h>
// int main() {
//     char *large = "oito zg bom com voce";
//     char *prt = ft_strchr(large, 'z');
//     printf("%s", prt);
//     return 0;
// }