/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzebian <kzebian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 20:01:47 by kzebian           #+#    #+#             */
/*   Updated: 2025/06/10 20:38:53 by kzebian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

static int	handle_ptr(unsigned long nb)
{
	int	cnt;

	cnt = 0;
	if (!nb)
		return (write(1, "(nil)", 5));
	else
	{
		cnt += write(1, "0x", 2);
		cnt += ft_putptr(nb);
	}
	return (cnt);
}

static int	ft_format(char specifier, va_list args)
{
	if (specifier == 'c')
		return (ft_putchar_fd((char)va_arg(args, int), 1));
	if (specifier == 's')
		return (ft_putstr(va_arg(args, char *)));
	if (specifier == 'p')
		return (handle_ptr(va_arg(args, unsigned long)));
	if (specifier == 'd' || specifier == 'i')
		return (ft_putnbr_fd(va_arg(args, int), 1));
	if (specifier == 'u')
		return (ft_pt_bs(va_arg(args, unsigned int), "0123456789"));
	if (specifier == 'x')
		return (ft_pt_bs(va_arg(args, unsigned int), "0123456789abcdef"));
	if (specifier == 'X')
		return (ft_pt_bs(va_arg(args, unsigned int), "0123456789ABCDEF"));
	if (specifier == '%')
		return (ft_putchar_fd('%', 1));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			count += ft_format(format[i + 1], args);
			i++;
		}
		else
			count += ft_putchar_fd(format[i], 1);
		i++;
	}
	va_end(args);
	return (count);
}

// #include <stdio.h>
// #include <limits.h>
// #include <stdlib.h>
// int main(void)
// {
// 	ft_printf("  Positive: %%d: %d | %%i: %i\n", 42, 42);
// 	ft_printf("  Negative: %%d: %d | %%i: %i\n", -42, -42);
// 	ft_printf("  Zero    : %%d: %d | %%i: %i\n", 0, 0);
// 	ft_printf("  INT_MAX : %d\n", INT_MAX);
// 	ft_printf("  INT_MIN : %d\n\n", INT_MIN);

// 	int a = 123;
// 	int *ptr = &a;
// 	ft_printf("  Valid pointer : %p\n", (void *)ptr);
// 	ft_printf("  NULL pointer  : %p\n\n", (void *)NULL);

// 	ft_printf("  Decimal 255 in hex : %%x = %x | %%X = %X\n", 255, 255);
// 	ft_printf("  Zero              : %%x = %x | %%X = %X\n", 0, 0);

// 	ft_printf("  Letter A : %c\n", 'A');
// 	ft_printf("  Number 0 : %c\n", '0');
// 	ft_printf("  NULL char (as int 0): %c (may not print)\n\n", 0);

// 	ft_printf("  Normal string : %s\n", "Hello, world!");
// 	ft_printf("  Empty string  : %s\n", "");
// 	ft_printf("  NULL string   : %s\n\n", (char *)NULL);

// 	ft_printf("  Just a percent sign: %%\n");

// 	ft_printf("\n \n %d", ft_printf("hello\n"));
// 	return 0;
// }