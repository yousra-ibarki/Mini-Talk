/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoibarki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 15:56:23 by yoibarki          #+#    #+#             */
/*   Updated: 2022/10/24 11:17:32 by yoibarki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*dest;
	const char	*sr;

	dest = (char *)dst;
	sr = (const char *)src;
	if (dst == src)
	{
		return (dst);
	}
	else if (dst > src)
	{
		while (len--)
		{
			dest[len] = sr[len];
		}
		return (dst);
	}
	while (len--)
		*dest++ = *sr++;
	return (dst);
}
