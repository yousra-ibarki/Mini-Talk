/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoibarki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 15:35:06 by yoibarki          #+#    #+#             */
/*   Updated: 2022/11/01 04:05:19 by yoibarki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ss;
	unsigned char	ch;

	i = 0;
	ss = (unsigned char *)s;
	ch = (unsigned char)c;
	while (i < n)
	{
		if (ss[i] == ch)
			return (ss + i);
		i++;
	}
	return (0);
}
