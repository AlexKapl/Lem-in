/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaplyar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 21:28:49 by akaplyar          #+#    #+#             */
/*   Updated: 2017/09/07 21:29:07 by akaplyar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		lem_desolate_paths(t_lem *lem)
{
	int		i;

	i = 0;
	while (i < lem->path_count)
	{
		lem->paths[i]->ants = 0;
		i++;
	}
}

void		lem_del_tmp(void *data, size_t size)
{
	(void)data;
	(void)size;
}

int			lem_new_opt(void const *data, size_t size, t_list **node)
{
	t_opt	*opt;
	int		*tmp;
	int		i;

	if (!(opt = (t_opt*)malloc(sizeof(t_opt))))
		lem_errors(MLC_ERR);
	if (!(opt->paths = (int*)malloc(sizeof(int) * size)))
		lem_errors(MLC_ERR);
	i = -1;
	tmp = (int*)data;
	while (++i < size)
		opt->paths[i] = tmp[i];
	opt->count = (int)size;
	(*node)->content = (void*)opt;
	(*node)->content_size = size;
	return (1);
}

int			lem_new_path(void const *data, size_t size, t_list **node)
{
	t_path	*path;

	if (!(path = (t_path*)malloc(sizeof(t_path))))
		lem_errors(MLC_ERR);
	path->path = (int*)data;
	path->ants = 0;
	path->len = (int)size;
	(*node)->content = (void*)path;
	(*node)->content_size = size;
	return (1);
}

int			lem_new_room(void const *name, size_t size, t_list **node)
{
	t_room	*room;
	char	**tab;

	tab = (char**)name;
	if (!(room = (t_room*)malloc(sizeof(t_room))) ||
		!(room->cords = (int*)malloc(sizeof(int) * 2)))
		lem_errors(MLC_ERR);
	if (!(room->name = ft_strdup(tab[0])))
	{
		free(room);
		return (0);
	}
	room->cords[0] = ft_atoi(tab[1]);
	room->cords[1] = ft_atoi(tab[2]);
	room->links = NULL;
	(*node)->content = (void*)room;
	(*node)->content_size = size;
	return (1);
}
