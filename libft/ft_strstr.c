/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osokoliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 16:18:18 by osokoliu          #+#    #+#             */
/*   Updated: 2017/12/03 19:32:17 by osokoliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str_a, const char *str_b)
{
	int c;

	c = ft_strlen(str_b);
	if (*str_b == '\0')
		return ((char*)str_a);
	while (*str_a)
	{
		if (*str_a == *str_b)
			if (ft_strncmp(str_a, str_b, c) == 0)
				return ((char*)str_a);
		str_a++;
	}
	return (0);
}
