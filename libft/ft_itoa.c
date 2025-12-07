/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzebian <kzebian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 23:17:14 by kzebian           #+#    #+#             */
/*   Updated: 2025/05/26 18:43:13 by kzebian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static int	lens(int nbr)
{
	long	n;
	int		i;

	n = nbr;
	i = 0;
	if (n < 0)
	{
		i++;
	}
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 10;
		i++;
	}	
	return (i);
}

char	*ft_itoa(int n)
{
	char	*s;
	int		i;
	long	nb;
	int		len;

	nb = n;
	len = lens(nb);
	s = malloc(len + 1);
	if (!s)
		return (NULL);
	s[len] = '\0';
	if (nb < 0)
	{
		s[0] = '-';
		nb = -nb;
	}
	if (nb == 0)
		s[0] = '0';
	i = len -1;
	while (nb > 0)
	{
		s[i--] = (nb % 10) + '0';
		nb = nb / 10;
	}
	return (s);
}

// #include <stdio.h>

// int main(void)
// {
// 	printf("%s", ft_itoa(2147483647));
// }