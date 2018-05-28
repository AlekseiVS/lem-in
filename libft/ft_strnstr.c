/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osokoliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 12:20:16 by osokoliu          #+#    #+#             */
/*   Updated: 2017/12/03 19:11:37 by osokoliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strnstr(const char *str_a, const char *str_b, size_t len)
{
	size_t c;

	c = ft_strlen(str_b);
	if (*str_b == '\0')
		return ((char*)str_a);
	while (*str_a && len >= c)
	{
		if (*str_a == *str_b)
			if (ft_strncmp(str_a, str_b, c) == 0)
				return ((char *)str_a);
		str_a++;
		len--;
	}
	return (0);
}
