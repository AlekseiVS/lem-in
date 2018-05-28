/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osokoliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 18:57:20 by osokoliu          #+#    #+#             */
/*   Updated: 2017/12/03 18:57:22 by osokoliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
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
				buff[i] = f(i, s[i]);
				i++;
			}
		}
		return (buff);
	}
	return (0);
}
