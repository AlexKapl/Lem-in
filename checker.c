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
	list = lem->rooms;
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

int			lem_new_node(void const *name, size_t size, t_list **node)
{
	t_room	*room;
	t_room	*tmp;

	tmp = (t_room*)name;
	if (!(room = (t_room*)malloc(sizeof(t_room))))
		return (0);
	if (!(room->name = ft_strdup(tmp->name)))
	{
		free(room);
		return (0);
	}
	room->links = NULL;
	(*node)->content = room;
	(*node)->content_size = size;
	return (1);
}

void		lem_check_room(char **tab, int room_end)
{
	if (room_end)
		lem_errors(6);//INPUT_ERR);
	if (ft_tabcount(tab) != 3)
		lem_errors(6);//INPUT_ERR);
	if (tab[0][0] == 'L')
		lem_errors(6);
	if (!ft_strisdigit(tab[1]))
		lem_errors(6);
	if (!ft_strisdigit(tab[2]))
		lem_errors(6);
}