/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoibarki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 14:47:40 by yoibarki          #+#    #+#             */
/*   Updated: 2022/10/24 14:32:08 by yoibarki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strcpy(const char *src, char *dst)
{
	size_t	i;

	i = 0;
	while (i < ft_strlen(src))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

static char	*ft_mystrdup(const char *s1)
{
	int		len;
	char	*arr;

	len = ft_strlen(s1);
	arr = malloc(sizeof(char) * (len + 1));
	if (!arr)
		return (0);
	ft_strcpy(s1, arr);
	return (arr);
}

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*ptr;

	i = 0;
	if (!s)
		return (0);
	else if (!f)
		return (ft_mystrdup(s));
	ptr = ft_mystrdup(s);
	if (!ptr)
		return (0);
	while (s[i])
	{
		ptr[i] = (*f)(i, s[i]);
		i++;
	}
	return (ptr);
}
