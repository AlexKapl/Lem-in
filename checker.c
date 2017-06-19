#include "lem_in.h"

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
	char *tmp;

	if (room_end)
		lem_errors(INPUT_ERR);
	if (ft_tabcount(tab) != 3)
		lem_errors(INPUT_ERR);
	tmp = tab[1];
	while (*tmp)
	{
		if (!ft_isdigit(*tmp))
			lem_errors(INPUT_ERR);
		tmp++;
	}
	tmp = tab[2];
	while (*tmp)
	{
		if (!ft_isdigit(*tmp))
			lem_errors(INPUT_ERR);
		tmp++;
	}
}