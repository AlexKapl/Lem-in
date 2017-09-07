/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaplyar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 21:23:55 by akaplyar          #+#    #+#             */
/*   Updated: 2017/09/07 21:25:14 by akaplyar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		lem_comments_operate(t_lem *lem, char *buff)
{
	if (!ft_strcmp(buff, "##start"))
	{
		if (lem->start >= 0)
			lem_errors(COMM_ERR);
		else
			lem->start = lem->room;
	}
	else if (!ft_strcmp(buff, "##end"))
	{
		if (lem->end >= 0)
			lem_errors(COMM_ERR);
		else
			lem->end = lem->room;
	}
}

static void	lem_add_link(t_list **room1, t_list **room2)
{
	int		i;
	int		*tmp;
	int		num;
	t_room	*room;

	room = (t_room*)(*room1)->content;
	tmp = room->links;
	num = (int)(*room2)->content_size;
	i = 0;
	while (tmp[i] >= 0)
	{
		if (tmp[i] == num)
			return ;
		i++;
	}
	tmp[i] = num;
	room->links = tmp;
	(*room1)->content = (void*)room;
}

static void	lem_find_links(t_lem *lem, t_list **room1, t_list **room2,
							char **tab)
{
	t_list	*list;
	t_room	*room;

	list = lem->tmp;
	while (list && (!*room1 || !*room2))
	{
		room = (t_room*)list->content;
		if (!*room1 && !ft_strcmp(room->name, tab[0]))
			*room1 = list;
		else if (!*room2 && !ft_strcmp(room->name, tab[1]))
			*room2 = list;
		list = list->next;
	}
	if (!*room1 || !*room2)
		lem->err = 1;
}

void		lem_links_operate(t_lem *lem, char *buff)
{
	char	**tab;
	t_list	*room1;
	t_list	*room2;

	if (!lem->room_end)
		lem_check_links(lem);
	tab = ft_strsplit(buff, '-');
	if (ft_tabcount(tab) != 2)
	{
		ft_tabdel(tab, -1);
		lem->err = 1;
		return ;
	}
	room1 = NULL;
	room2 = NULL;
	lem_find_links(lem, &room1, &room2, tab);
	ft_tabdel(tab, -1);
	if (!room1 || !room2)
		return ;
	lem_add_link(&room1, &room2);
	lem_add_link(&room2, &room1);
}

void		lem_rooms_operate(t_lem *lem, char *buff)
{
	char	**tab;
	t_list	*node;

	tab = ft_strsplit(buff, ' ');
	if (!lem_check_room(lem, tab))
	{
		lem->err = 1;
		ft_tabdel(tab, -1);
		return ;
	}
	node = ft_lstnew_struct((void*)tab, (size_t)lem->room++, &lem_new_room);
	if (!node)
		lem_errors(MLC_ERR);
	ft_lst_push_back(&lem->tmp, node);
	ft_tabdel(tab, -1);
}
