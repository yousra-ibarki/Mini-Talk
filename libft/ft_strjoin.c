/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoibarki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 15:49:19 by yoibarki          #+#    #+#             */
/*   Updated: 2022/10/24 12:53:53 by yoibarki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*mystrcpy(char *ss, const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		ss[i] = s[i];
		i++;
	}
	ss[i] = '\0';
	return (ss);
}

static char	*ft_strcat(char *ss, const char *s)
{
	int	len;
	int	i;

	len = ft_strlen(ss);
	i = 0;
	while (s[i])
	{
		ss[len + i] = s[i];
		i++;
	}
	ss[i + len] = '\0';
	return (ss);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	char	*new;

	i = 0;
	if (!s1 || !s2)
		return (0);
	new = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!new)
		return (0);
	mystrcpy(new, s1);
	ft_strcat(new, s2);
	return (new);
}
