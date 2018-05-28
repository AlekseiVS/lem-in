/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osokoliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 17:57:20 by osokoliu          #+#    #+#             */
/*   Updated: 2017/12/05 18:11:21 by osokoliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static	int		ft_count_word(char const *s, char c)
{
	int		count_word;

	count_word = 0;
	if (!s)
		return (0);
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			count_word++;
			while (*s && *s != c)
				s++;
		}
	}
	return (count_word);
}

static t_split	ft_len_word(char const **s, char c)
{
	t_split	word;

	word.start = NULL;
	word.len = 0;
	while (**s && **s == c)
		(*s)++;
	word.start = *s;
	while (**s != c && **s)
	{
		word.len++;
		(*s)++;
	}
	return (word);
}

static	char	*ft_new_word(char const **s, char c)
{
	t_split	word;
	char	*buff;
	char	*buff_start;

	if (!s)
		return (0);
	word = ft_len_word(s, c);
	buff = ft_strnew(word.len);
	if (!buff)
		return (NULL);
	buff_start = buff;
	while (word.len > 0)
	{
		*buff++ = *(word.start)++;
		word.len--;
	}
	return (buff_start);
}

char			**ft_strsplit(char const *s, char c)
{
	int		n;
	int		c_w;
	char	**buff;
	char	*n_w;

	n = 0;
	c_w = ft_count_word(s, c);
	if (!s)
		return (0);
	buff = (char**)malloc(sizeof(char*) * (c_w + 1));
	if (!buff)
		return (NULL);
	while (c_w > 0)
	{
		n_w = ft_new_word(&s, c);
		buff[n] = n_w;
		c_w--;
		n++;
	}
	buff[n] = NULL;
	return (buff);
}
