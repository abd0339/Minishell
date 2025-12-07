/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzebian <kzebian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 18:58:09 by kzebian           #+#    #+#             */
/*   Updated: 2025/05/24 17:37:59 by kzebian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	a;

	i = 0;
	a = (char)c;
	while (s[i])
	{
		i++;
	}
	while (i >= 0)
	{
		if (s[i] == a)
			return ((char *) & s[i]);
		i--;
	}
	return (NULL);
}

// int main() {
//     char *large = "oio udo baom com voce";
//     char *prt = ft_strrchr(large, 'a');
//     printf("%s", prt);
//     return 0;

// }