/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osokoliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 16:13:44 by osokoliu          #+#    #+#             */
/*   Updated: 2017/12/03 18:59:36 by osokoliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strncat(char *dst, const char *app, size_t n)
{
	size_t dstln;
	size_t appln;

	dstln = 0;
	appln = 0;
	while (dst[dstln] != '\0')
		dstln++;
	while (app[appln] != '\0' && appln < n)
	{
		dst[dstln] = app[appln];
		dstln++;
		appln++;
	}
	dst[dstln] = '\0';
	return (dst);
}
