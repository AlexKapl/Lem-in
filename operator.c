#include "lem_in.h"


void			check(t_lem *lem)
{
	t_room		*room;
	t_list		*list;
	static int	i = 0;

	if (lem->rooms)
	{
		list = lem->rooms;
		while (list->next)
		{
			room = (t_room *)list->content;
			ft_printf("%d -|- %s\n", i++, room->name);
		}
	}
}

void		lem_comments_operate(t_lem *lem, char *buff)
{
	if (!ft_strcmp(buff, "##start"))
		lem->start = lem->room;
	else if (!ft_strcmp(buff, "##end"))
		lem->end = lem->room;
}

static void	lem_links_prepare(t_lem *lem)
{
	t_list	*list;
	t_room	*room;
	int		i;

	if (lem->room < lem->end || lem->room < lem->start)
		lem_errors(5);//INPUT_ERR);
	lem->room_end = 1;
	list = lem->rooms;
	while (list)
	{
		room = list->content;
		room->links = (int*)malloc(sizeof(int) * lem->room);
		i = 0;
		while (i < lem->room)
		{
			room->links[i] = -1;
			i++;
		}
		list = list->next;
	}
}

static void	lem_add_link(t_lem *lem, int **links, char *name)
{
	int		i;
	int		*tmp;
	t_list	*node;
	t_room	*room;

	i = 0;
	node = lem->rooms;
	tmp = *links;
	while (node)
	{
		room = (t_room*)node->content;
		if (!ft_strcmp(room->name, name))
		{
			while (tmp[i] >= 0)
			{
				ft_printf("%d - %d\n", i, tmp[i]);
				i++;
			}
			tmp[i] = (int)node->content_size;
			*links = tmp;
			return;
		}
		node = node->next;
	}
	lem_errors(4);//INPUT_ERR);
}

void		lem_links_operate(t_lem *lem, char *buff)
{
	char	**tab;
	t_list	*list;
	t_room	*room;

	if (!lem->room_end)
		lem_links_prepare(lem);
	tab = ft_strsplit(buff, '-');
	if (ft_tabcount(tab) != 2)
		lem_errors(3);//INPUT_ERR);
	list = lem->rooms;
	while (list)
	{
		room = (t_room*)list->content;
		if (!ft_strcmp(room->name, tab[0]))
		{
			lem_add_link(lem, &room->links, tab[1]);
			list->content = room;
			ft_tabdel(tab, -1);
			return ;
		}
		list = list->next;
	}
	lem_errors(4);//INPUT_ERR);
}


void		lem_rooms_operate(t_lem *lem, char *buff)
{
	char	**tab;
	t_room	room;
	t_list	*node;

	tab = ft_strsplit(buff, ' ');
	lem_check_room(tab, lem->room_end);
	room.name = tab[0];
	room.links = NULL;
	node = ft_lstnew_struct((void*)&room, (size_t)lem->room++, &lem_new_node);
	if (!node)
		lem_errors(MLC_ERR);
	ft_lst_push_back(&lem->rooms, node);
	ft_tabdel(tab, -1);
}