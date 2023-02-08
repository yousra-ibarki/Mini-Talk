/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoibarki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 15:57:05 by yoibarki          #+#    #+#             */
/*   Updated: 2022/10/24 14:15:35 by yoibarki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	lend;
	size_t	lens;

	i = 0;
	lend = ft_strlen(dst);
	lens = ft_strlen(src);
	if (!dst)
		return (0);
	if (dstsize == 0)
		return (lens);
	else if (lend >= dstsize)
		return (lens + dstsize);
	if (lens >= dstsize - lend)
	{
		ft_memcpy(dst + lend, src, lens + 1);
		dst[dstsize - 1] = 0;
	}
	else
		ft_memcpy(dst + lend, src, lens + 1);
	return (lend + lens);
}
