/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoibarki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 15:18:07 by yoibarki          #+#    #+#             */
/*   Updated: 2022/11/19 15:18:11 by yoibarki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *s, ...);
int		ft_putchar(int a);
int		ft_prints(char *str);
int		ft_printp(unsigned long long p);
int		ft_printnb(int nb);
char	*ft_itoa(int n);
char	*ft_strdup(const char *s1);
int		ft_printunsigned(unsigned int nb);
int		ft_printhex(unsigned int h, char type);
int		ft_count(unsigned int h);

#endif
