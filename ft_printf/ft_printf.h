/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoibarki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 15:18:07 by yoibarki          #+#    #+#             */
/*   Updated: 2023/02/27 15:58:48 by yoibarki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <signal.h>
# include <stdarg.h>
# include <stdlib.h>
# include <sys/types.h>
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
int		ft_atoi(const char *str);
size_t	ft_strlen(const char *s);

#endif
