/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoibarki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 15:31:04 by yoibarki          #+#    #+#             */
/*   Updated: 2022/10/24 12:03:54 by yoibarki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int				i;
	unsigned char	ca;

	ca = (unsigned char)c;
	i = 0;
	if (!c)
		return ((char *)s + ft_strlen(s));
	while (s[i])
	{
		if (s[i] == ca)
		{
			return ((char *)s + i);
		}
		i++;
	}
	return (0);
}
