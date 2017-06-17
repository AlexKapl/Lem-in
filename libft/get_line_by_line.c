/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line_by_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isolomak <isolomak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 19:10:11 by isolomak          #+#    #+#             */
/*   Updated: 2017/03/08 19:25:50 by isolomak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	cut_rest(char **line, char *rest)
{
	char	*end;

	end = ft_strchr(rest, '\n');
	if (end)
	{
		*end = '\0';
		*line = ft_strdup(rest);
		ft_memmove(rest, &end[1], ft_strlen(&end[1]) + 1);
		return (1);
	}
	if (ft_strlen(rest) > 0)
	{
		*line = ft_strdup(rest);
		*rest = '\0';
		return (1);
	}
	return (0);
}

int			get_line_by_line(int const fd, char **line)
{
	static char	*rest = NULL;
	char		buff[BUFF_SIZE + 1];
	char		*temp;
	int			ret;

	if (!line || 0 > fd || BUFF_SIZE <= 0)
		return (-1);
	if (!rest)
		rest = ft_strnew(0);
	while (!ft_strchr(rest, '\n'))
	{
		if ((ret = read(fd, buff, BUFF_SIZE)) < 0)
			return (-1);
		if (!ret)
			return (cut_rest(line, rest));
		buff[ret] = '\0';
		temp = ft_strjoin(rest, buff);
		free(rest);
		rest = temp;
	}
	return (cut_rest(line, rest));
}
