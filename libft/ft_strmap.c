/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osokoliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 17:06:22 by osokoliu          #+#    #+#             */
/*   Updated: 2017/12/03 18:26:26 by osokoliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*buff;
	size_t	i;
	size_t	len;

	buff = NULL;
	i = 0;
	if ((s) && (f))
	{
		len = ft_strlen(s);
		buff = ft_strnew(len);
		if (buff)
		{
			while (s[i] != '\0')
			{
				buff[i] = f(s[i]);
				i++;
			}
		}
		return (buff);
	}
	return (0);
}
