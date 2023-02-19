/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoibarki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 15:31:49 by yoibarki          #+#    #+#             */
/*   Updated: 2022/10/24 14:44:50 by yoibarki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		lens;
	char	ca;

	lens = ft_strlen(s);
	ca = (unsigned char)c;
	if (!s)
		return (0);
	if (!c)
		return ((char *)s + lens);
	while (lens >= 0)
	{
		if (s[lens] == ca)
			return ((char *)s + lens);
		lens--;
	}
	return (0);
}
