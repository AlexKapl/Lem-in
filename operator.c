#include "lem_in.h"

void		lem_comments_operate(t_lem *lem, char *buff)
{
	if (!ft_strcmp(buff, "##start"))
		lem->start = lem->room + 1;
	else if (!ft_strcmp(buff, "##end"))
		lem->end = lem->room + 1;
}

static int	lem_link_index(int **links)
{
	int		i;
	int		len;
	int		*tmp;

	if (links)
	{
		i = -1;
		len = 0;
		while (*(*(links + len)) != -1)
			len++;
		tmp = (int*)malloc(sizeof(int) * len + 1);
		while (++i < len)
			tmp[i] = *(*(links + i));
		tmp[len + 1] = -1;
		free(*links);
		*links = tmp;
		return (i);
	}
	else
	{
		*links = (int *)malloc(sizeof(int) * 2);
		*(*(links + 1)) = -1;
		return (0);
	}
}

static void	lem_add_link(t_lem *lem, int *links, char *name)
{
	int		i;
	t_list	*node;
	t_room	*room;

	i = lem_link_index(&links);
	node = lem->rooms;
	while (node->next)
	{
		room = node->content;
		if (!ft_strcmp(room->name, name))
		{
			links[i] = (int)node->content_size;
			return;
		}
		node = node->next;
	}
	lem_errors(INPUT_ERR);
}

void		lem_links_operate(t_lem *lem, char *buff)
{
	char	**tab;
	t_list	*list;
	t_room	*room;

	if (lem->room_end)
		lem_errors(INPUT_ERR);
	tab = ft_strsplit(buff, '-');
	if (ft_tabcount(tab) != 2)
		lem_errors(INPUT_ERR);
	list = lem->rooms;
	while (list->next)
	{
		room = list->content;
		if (!ft_strcmp(room->name, tab[0]))
		{
			lem_add_link(lem, room->links, tab[1]);
			ft_tabdel(tab, -1);
			return ;
		}
		list = list->next;
	}
	lem_errors(INPUT_ERR);
}

void		lem_rooms_operate(t_lem *lem, char *buff)
{
	char	**tab;
	t_room	room;
	t_list	*node;

	tab = ft_strsplit(buff, ' ');
	lem_check_room(tab);
	room.name = tab[0];
	room.links = NULL;
	node = ft_lstnew((void*)&room, sizeof(t_room));
	node->content_size = (size_t)lem->room++;
	ft_lst_push_back(&lem->rooms, node);
	ft_tabdel(tab, -1);
}