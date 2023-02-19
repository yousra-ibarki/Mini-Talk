/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoibarki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 15:42:15 by yoibarki          #+#    #+#             */
/*   Updated: 2022/10/24 12:09:31 by yoibarki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*strrcpy(const char *src, char *dst)
{
	size_t	i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_strdup(const char *s1)
{
	int		len;
	char	*arr;

	len = ft_strlen(s1);
	arr = malloc(len * sizeof(char) + 1);
	if (arr == NULL)
		return (NULL);
	arr = strrcpy(s1, arr);
	return (arr);
}
