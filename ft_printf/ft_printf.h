/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzebian <kzebian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 19:18:32 by kzebian           #+#    #+#             */
/*   Updated: 2025/05/28 00:53:51 by kzebian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include<stdlib.h>
# include<unistd.h>
# include<stdarg.h>
# include<stdio.h>

size_t	ft_strlen(const char *s);
int		ft_putchar_fd(char c, int fd);
int		ft_putstr(char *s);
int		ft_putnbr_fd(int n, int fd);
int		ft_putptr(unsigned long nb);
int		ft_pt_bs(unsigned int nb, char *base);
int		ft_printf(const char *format, ...);

#endif
