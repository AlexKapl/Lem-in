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

/**
 ** Додати перевірку на координати кімнат
 **/
