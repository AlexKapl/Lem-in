#include "lem_in.h"

int			lem_path_sort(size_t size1, size_t size2)
{
	return (size1 > size2 ? 1 : 0);
}
//видалити

void		lem_del_tmp(void *data, size_t size)
{
	(void) data;
	(void) size;
}

int			lem_new_opt(void const *data, size_t size, t_list **node)
{
	t_opt	*opt;
	int		*tmp;
	int		i;

	if (!(opt = (t_opt*)malloc(sizeof(t_opt))))
		return (0);
	if (!(opt->paths = (int*)malloc(sizeof(int) * size)))
		return (0);
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
		return (0);
	path->path = (int*)data;
	path->ants = 0;
	path->len = (int)size;
	(*node)->content = (void*)path;
	(*node)->content_size = size;
	return (1);
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
	(*node)->content = (void*)room;
	(*node)->content_size = size;
	return (1);
}
