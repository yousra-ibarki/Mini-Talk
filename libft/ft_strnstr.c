/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoibarki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 15:36:39 by yoibarki          #+#    #+#             */
/*   Updated: 2022/10/24 14:42:34 by yoibarki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	char	*find;

	i = 0;
	find = (char *)haystack;
	if (*needle == '\0')
		return (find);
	while (i < len && haystack[i])
	{
		j = 0;
		while (haystack[i + j] && needle[j] && haystack[i + j] == needle[j] && i
			+ j < len)
		{
			j++;
			if (needle[j] == '\0')
				return (find + i);
		}
		i++;
	}
	return (0);
}
