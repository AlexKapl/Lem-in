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

void 		lem_find_paths(t_lem *lem, int room, int *path, int len)
{
	int 	i;
	t_room	*r;
	t_list	*node;

	i = 0;
	while (path[i] > 0 && i < lem->room)
		if (path[i++] == room)
			return ;
	path[i] = room;
	len++;
	if (room == lem->end)
	{
		node = ft_lstnew(path, sizeof(int) * len);
		node->content_size = (size_t)len;
		ft_lst_push_back(&lem->path, node);
	}
	r = (t_room*)lem->hash[i]->content;
	i = 0;
	while (r->links[i] > 0 && i < lem->room)
	{
		lem_find_paths(lem, r->links[i], path, len);
		i++;
	}
}