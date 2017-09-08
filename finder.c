/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finder.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaplyar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 21:20:57 by akaplyar          #+#    #+#             */
/*   Updated: 2017/09/07 21:21:08 by akaplyar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			lem_sort_path(size_t s1, size_t s2)
{
	return (s1 > s2 ? 1 : 0);
}

static int	*lem_copy_path(int *path, int room, int end)
{
	int		*copy;
	int		i;
	int		j;

	i = 0;
	while (path[i] >= 0 && i < end)
		if (path[i++] == room)
			return (NULL);
	if (!(copy = (int*)malloc(sizeof(int) * end)))
		lem_errors(MLC_ERR);
	j = 0;
	while (j < end)
	{
		copy[j] = path[j];
		j++;
	}
	copy[i] = room;
	return (copy);
}

static void	lem_find_paths(t_lem *lem, int room, int *start, int len)
{
	int		i;
	int		*path;
	t_room	*r;
	t_list	*node;

	if (!(path = lem_copy_path(start, room, lem->room)))
		return ;
	len++;
	if (room == lem->end)
	{
		node = ft_lstnew_struct(path, (size_t)len, lem_new_path);
		ft_lst_push_back(&lem->tmp, node);
		return ;
	}
	r = lem->rooms[room];
	i = 0;
	while (r->links[i] >= 0 && i < lem->room)
	{
		lem_find_paths(lem, r->links[i], path, len);
		i++;
	}
	free(path);
}

void		lem_path_prepare(t_lem *lem)
{
	int		*path;
	int		i;

	i = 0;
	if (!lem->room_end)
		lem_errors(INPUT_ERR);
	lem_room_hash(lem);
	if (!(path = (int*)malloc(sizeof(int) * lem->room)))
		lem_errors(MLC_ERR);
	while (i < lem->room)
		path[i++] = -1;
	lem_find_paths(lem, lem->start, path, 0);
	free(path);
	lem_path_hash(lem);
}
