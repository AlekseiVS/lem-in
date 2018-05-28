/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osokoliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 15:44:02 by osokoliu          #+#    #+#             */
/*   Updated: 2017/12/03 17:35:51 by osokoliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dst, const char *app)
{
	int dstln;
	int appln;

	dstln = 0;
	appln = 0;
	while (dst[dstln] != '\0')
		dstln++;
	while (app[appln] != '\0')
	{
		dst[dstln] = app[appln];
		dstln++;
		appln++;
	}
	dst[dstln] = '\0';
	return (dst);
}
