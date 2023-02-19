/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoibarki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 08:24:25 by yoibarki          #+#    #+#             */
/*   Updated: 2022/10/24 12:21:48 by yoibarki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;
	unsigned int	len;

	i = 0;
	if (!s || !f)
		return ;
	len = ft_strlen(s);
	while (i < len)
	{
		(*f)(i, s);
		s++;
		i++;
	}
}
