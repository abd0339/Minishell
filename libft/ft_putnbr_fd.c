/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzebian <kzebian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 22:56:15 by kzebian           #+#    #+#             */
/*   Updated: 2025/05/24 20:36:25 by kzebian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	nb;
	char	x;

	nb = n;
	if (nb < 0)
	{
		write(fd, "-", 1);
		nb = -nb;
	}
	if ((nb / 10) <= 0)
	{
		x = nb + '0';
		write(fd, &x, 1);
	}
	else
	{
		x = (nb % 10) + '0';
		ft_putnbr_fd(nb / 10, fd);
		write(fd, &x, 1);
	}
}
