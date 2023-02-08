/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoibarki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 15:55:47 by yoibarki          #+#    #+#             */
/*   Updated: 2022/10/24 11:15:24 by yoibarki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*dest;
	char	*sr;
	int		i;

	i = 0;
	dest = (char *)dst;
	sr = (char *)src;
	if (dst == src)
		return (dst);
	while (n > 0)
	{
		dest[i] = sr[i];
		i++;
		n--;
	}
	return (dest);
}
