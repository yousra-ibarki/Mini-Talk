/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoibarki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 15:17:53 by yoibarki          #+#    #+#             */
/*   Updated: 2022/11/19 15:17:58 by yoibarki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	checkformat(const char c, va_list *varin)
{
	int	len;

	len = 0;
	if (c == 'c')
		len += ft_putchar(va_arg(*varin, int));
	else if (c == 's')
		len += ft_prints(va_arg(*varin, char *));
	else if (c == 'p')
		len += ft_printp(va_arg(*varin, unsigned long long));
	else if (c == 'd' || c == 'i')
		len += ft_printnb(va_arg(*varin, int));
	else if (c == 'u')
		len += ft_printunsigned(va_arg(*varin, unsigned int));
	else if (c == 'x' || c == 'X')
		len += ft_printhex(va_arg(*varin, unsigned int), c);
	else if (c == '%')
		len += ft_putchar('%');
	return (len);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	va_list	varin;
	int		len;

	i = 0;
	len = 0;
	va_start(varin, s);
	while (s[i])
	{
		if (s[i] == '%' && s[i + 1] == '\0')
			return (0);
		if (s[i] == '%')
		{
			len += checkformat(s[i + 1], &varin);
			i++;
		}
		else
			len += ft_putchar(s[i]);
		i++;
	}
	va_end(varin);
	return (len);
}
