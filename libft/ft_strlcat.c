/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osokoliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 10:36:47 by osokoliu          #+#    #+#             */
/*   Updated: 2017/12/03 18:19:07 by osokoliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t dst_ln;
	size_t src_ln;
	size_t buff_dstsize;

	dst_ln = ft_strlen(dst);
	src_ln = ft_strlen(src);
	buff_dstsize = dstsize;
	if (dstsize > dst_ln)
	{
		dst = (dst + dst_ln);
		dstsize = (dstsize - dst_ln) - 1;
		while (dstsize && ((*dst++) = *src++))
			dstsize--;
		*dst = '\0';
	}
	if (buff_dstsize < dst_ln)
		return (buff_dstsize + src_ln);
	else
		return (dst_ln + src_ln);
}
