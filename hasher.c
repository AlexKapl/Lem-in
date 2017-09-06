#include "lem_in.h"

static void	lem_make_hash(t_lem *lem)
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

static void	lem_path_hash(t_lem *lem)
{
	int 	i;
	t_list	*list;

	lem->p_hash = (t_list**)malloc(sizeof(t_list*) * ft_lstcount(lem->path));
	i = 0;
	list = lem->path;
	while (list)
	{
		lem->p_hash[i] = list;
		i++;
		list = list->next;
	}
	lem->path_count = i;
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
	copy = (int*)malloc(sizeof(int) * end);
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
	int 	i;
	int		*path;
	t_room	*r;
	t_list	*node;

	if (!(path = lem_copy_path(start, room, lem->room)))
		return ;
	len++;
	if (room == lem->end)
	{
		node = ft_lstnew(path, sizeof(int) * len);
		node->content_size = (size_t)len;
		ft_lst_push_back(&lem->path, node);
		free(path);
		return ;
	}
	r = (t_room*)lem->hash[room]->content;
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
	lem_make_hash(lem);
	path = (int*)malloc(sizeof(int) * lem->room);
	while (i < lem->room)
		path[i++] = -1;
	lem_find_paths(lem, lem->start, path, 0);
	free(path);
	ft_lst_sort_size(&lem->path, lem_path_sort, 0, (int)ft_lstcount(lem->path));
	lem_path_hash(lem);
}