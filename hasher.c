/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hasher.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaplyar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 21:21:16 by akaplyar          #+#    #+#             */
/*   Updated: 2017/09/07 21:21:29 by akaplyar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	lem_room_hash(t_lem *lem)
{
	int		i;
	t_list	*list;

	lem->rooms = (t_room**)malloc(sizeof(t_room*) * lem->room);
	i = 0;
	list = lem->tmp;
	while (i < lem->room)
	{
		lem->rooms[i] = (t_room*)list->content;
		i++;
		list = list->next;
	}
	ft_lstdel(&lem->tmp, lem_del_tmp);
}

void	lem_path_hash(t_lem *lem)
{
	int		i;
	t_list	*list;

	lem->path_count = (int)ft_lstcount(lem->tmp);
	if (!lem->path_count)
		lem_errors(INPUT_ERR);
	lem->paths = (t_path**)malloc(sizeof(t_path*) * lem->path_count);
	i = 0;
	list = lem->tmp;
	while (i < lem->path_count)
	{
		lem->paths[i] = (t_path*)list->content;
		i++;
		list = list->next;
	}
	ft_lstdel(&lem->tmp, lem_del_tmp);
}

void	lem_opt_hash(t_lem *lem)
{
	int		i;
	t_list	*list;

	lem->opt_count = (int)ft_lstcount(lem->tmp);
	lem->opts = (t_opt**)malloc(sizeof(t_opt*) * lem->opt_count);
	i = 0;
	list = lem->tmp;
	while (i < lem->opt_count)
	{
		lem->opts[i] = (t_opt*)list->content;
		i++;
		list = list->next;
	}
	ft_lstdel(&lem->tmp, lem_del_tmp);
}
