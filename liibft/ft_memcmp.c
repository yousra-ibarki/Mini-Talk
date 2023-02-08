/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoibarki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 15:36:00 by yoibarki          #+#    #+#             */
/*   Updated: 2022/10/24 11:14:13 by yoibarki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*ss;
	const unsigned char	*sss;
	size_t				i;
	int					result;

	i = 0;
	ss = (unsigned char *)s1;
	sss = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (i < n - 1 && ss[i] == sss[i])
		i++;
	result = ss[i] - sss[i];
	return (result);
}
