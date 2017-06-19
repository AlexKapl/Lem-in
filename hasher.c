#include "lem_in.h"

void		lem_make_hash(t_lem *lem)
{
	int		i;
	t_list	*list;

	lem->hash = (t_list**)malloc(sizeof(t_list*) * lem->room);
	i = 0;
	list = lem->rooms;
	while (i < lem->room)
	{
		lem->hash[i] = list;
		i++;
		list = list->next;
	}
}