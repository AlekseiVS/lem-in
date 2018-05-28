/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osokoliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 15:03:39 by osokoliu          #+#    #+#             */
/*   Updated: 2017/12/03 20:07:49 by osokoliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *arr1, const void *arr2, size_t n)
{
	size_t			i;
	unsigned char	*dst;
	unsigned char	*src;

	dst = (unsigned char*)arr1;
	src = (unsigned char*)arr2;
	i = 0;
	while (i < n)
	{
		if (dst[i] == src[i])
			i++;
		else
			return (dst[i] - src[i]);
	}
	return (0);
}
