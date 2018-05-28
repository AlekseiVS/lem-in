/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osokoliu <osokoliu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 11:04:43 by osokoliu          #+#    #+#             */
/*   Updated: 2018/05/05 12:57:01 by osokoliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_free_buff(char **buff)
{
	free(*buff);
	return (1);
}

int		ft_read(char **buff_str, int fd)
{
	int			result_read;
	char		*buff;
	char		*tmp;

	if (ft_strchr(*buff_str, '\n'))
		return (1);
	buff = ft_strnew(BUFF_SIZE);
	while ((result_read = read(fd, buff, BUFF_SIZE)))
	{
		if (result_read == -1 && ft_free_buff(&buff))
			return (-1);
		tmp = *buff_str;
		buff[result_read] = '\0';
		*buff_str = ft_strjoin(*buff_str, buff);
		free(tmp);
		if (ft_strchr(*buff_str, '\n'))
			break ;
	}
	free(buff);
	if (**buff_str == 0)
		return (0);
	if (!ft_strchr(*buff_str, '\n'))
		return (-2);
	return (1);
}

void	ft_write(char **buff_str, char **line, int result_read)
{
	int			ln_line;
	char		*tmp;

	tmp = *buff_str;
	if (result_read == -2)
	{
		ln_line = ft_strlen(*buff_str);
		*line = ft_strsub(*buff_str, 0, ln_line);
		*buff_str = ft_strdup((*buff_str) + ln_line);
		free(tmp);
	}
	if (result_read == 1)
	{
		ln_line = ft_strchr(*buff_str, '\n') - *buff_str;
		*line = ft_strsub(*buff_str, 0, ln_line);
		*buff_str = ft_strdup(++(*buff_str) + ln_line);
		free(tmp);
	}
}

t_list	*ft_multi_fd(int fd, t_list *head)
{
	t_list		*tmp_last;
	t_list		*new_node;
	char		*buff;

	buff = ft_strnew(BUFF_SIZE);
	while (head)
	{
		if (head->content_size == (size_t)fd)
		{
			free(buff);
			return (head);
		}
		tmp_last = head;
		head = head->next;
	}
	new_node = ft_lstnew(buff, 1);
	new_node->content_size = fd;
	tmp_last->next = new_node;
	free(buff);
	return (new_node);
}

int		get_next_line(const int fd, char **line)
{
	int				result_read;
	static t_list	*head;
	t_list			*file;
	char			*buff;

	if (fd < 0 || line == 0)
		return (-1);
	if (!head)
	{
		buff = ft_strnew(BUFF_SIZE);
		head = ft_lstnew(buff, 1);
		head->content_size = fd;
		file = head;
		free(buff);
	}
	else
		file = ft_multi_fd(fd, head);
	result_read = ft_read(((char**)&file->content), fd);
	ft_write(((char**)&file->content), line, result_read);
	if (result_read == -1)
		return (-1);
	if (result_read == 1 || result_read == -2)
		return (1);
	return (0);
}
