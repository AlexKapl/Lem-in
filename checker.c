/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaplyar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 21:20:29 by akaplyar          #+#    #+#             */
/*   Updated: 2017/09/07 21:20:46 by akaplyar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		lem_check_links(t_lem *lem)
{
	t_list	*list;
	t_room	*room;
	int		i;

	if (lem->start < 0 || lem->end < 0)
		lem_errors(COMM_ERR);
	if (lem->room < lem->end || lem->room < lem->start)
		lem_errors(COMM_ERR);
	lem->room_end = 1;
	list = lem->tmp;
	while (list)
	{
		room = (t_room*)list->content;
		if (!(room->links = (int*)malloc(sizeof(int) * lem->room)))
			lem_errors(MLC_ERR);
		i = 0;
		while (i < lem->room)
		{
			room->links[i] = -1;
			i++;
		}
		list = list->next;
	}
}

int			lem_check_room(t_lem *lem, char **tab)
{
	t_room	*room;
	t_list	*list;
	int		cords[2];

	if (lem->room_end || ft_tabcount(tab) != 3 || tab[0][0] == 'L' ||
		!ft_strisdigit(tab[1]) || !ft_strisdigit(tab[2]))
		return (0);
	list = lem->tmp;
	cords[0] = ft_atoi(tab[1]);
	cords[1] = ft_atoi(tab[2]);
	while (list)
	{
		room = (t_room*)list->content;
		if (ft_strequ(tab[0], room->name) || (room->cords[0] == cords[0] &&
				room->cords[1] == cords[1]))
			return (0);
		list = list->next;
	}
	return (1);
}
