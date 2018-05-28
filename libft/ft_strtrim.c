/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osokoliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 11:20:27 by osokoliu          #+#    #+#             */
/*   Updated: 2017/12/03 19:43:31 by osokoliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_len_buff(char const **s)
{
	int		len;

	len = 0;
	while (**s == ' ' || **s == '\n' || **s == '\t')
		(*s)++;
	while (**s != '\0')
	{
		(*s)++;
		len++;
	}
	(*s)--;
	while (**s == ' ' || **s == '\n' || **s == '\t')
	{
		(*s)--;
		len--;
	}
	if (len < 0)
		len = '\0';
	return (len);
}

char			*ft_strtrim(char const *s)
{
	char	*buff;
	char	*buff_start;
	int		len;

	if (s)
		len = ft_len_buff(&s);
	if (s == NULL)
		return (NULL);
	buff = ft_strnew(len);
	if (buff)
	{
		buff_start = buff;
		s = s - len;
		s++;
		while (len-- > 0)
			*buff++ = *s++;
		return (buff_start);
	}
	return (NULL);
}
