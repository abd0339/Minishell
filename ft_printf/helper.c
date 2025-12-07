/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzebian <kzebian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 19:19:14 by kzebian           #+#    #+#             */
/*   Updated: 2025/05/28 01:09:30 by kzebian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_fd(char c, int fd)
{
	return (write (fd, &c, 1));
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
	{
		return ((write(1, "(null)", 6)));
	}
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

int	ft_putnbr_fd(int n, int fd)
{
	long	nb;
	int		i;

	i = 0;
	nb = n;
	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		nb = -nb;
		i++;
	}
	if (nb >= 10)
		i += ft_putnbr_fd(nb / 10, fd);
	i += ft_putchar_fd(nb % 10 + '0', fd);
	return (i);
}

int	ft_putptr(unsigned long nb)
{
	int		i;

	i = 0;
	if (nb >= 16)
		i += ft_putptr(nb / 16);
	i += ft_putchar_fd("0123456789abcdef"[nb % 16], 1);
	return (i);
}

int	ft_pt_bs(unsigned int nb, char *base)
{
	int		i;

	i = 0;
	if (nb >= ft_strlen(base))
		i += ft_pt_bs(nb / ft_strlen(base), base);
	i += ft_putchar_fd(base[nb % ft_strlen(base)], 1);
	return (i);
}
