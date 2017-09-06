#include "lem_in.h"

static void print_path(t_lem *lem)
{
	t_list	*path;
	t_room	*r;
	int		*p;
	size_t 	i;

	path = lem->path;
	while (path)
	{
		i = 0;
		p = (int*)path->content;
		while (i < path->content_size)
		{
			r = (t_room*)lem->hash[p[i]]->content;
			ft_printf("%s", r->name);
			if (i + 1 != path->content_size)
				ft_printf(" -> ");
			i++;
		}
		ft_printf(" | %zu\n", path->content_size);
		path = path->next;
	}
}

void		lem_errors(int errnum)
{
	if (errnum == ANT_ERR)
		ft_printf("{fd}ERROR: Invalid number of ants\n", 2);
	else if (errnum == INPUT_ERR)
		ft_printf("{fd}ERROR\n", 2);
	else if (errnum == MLC_ERR)
		ft_printf("{fd}ERROR: Can't allocate memory\n", 2);
	else
		ft_printf("{fd}ERROR %d\n", 2, errnum);
	exit(errnum);
}

static void	lem_struct_init(t_lem *lem)
{
	lem->ants_count = 0;
	lem->path_count = 0;
	lem->start = -1;
	lem->end = -1;
	lem->room = 0;
	lem->room_end = 0;
	lem->opt = NULL;
	lem->ants = NULL;
	lem->output = NULL;
	lem->rooms = NULL;
	lem->path = NULL;
	lem->hash = NULL;
	lem->p_hash = NULL;
}

int			main()
{
	t_lem	lem;

	lem_struct_init(&lem);
	lem_read(&lem);
	lem_path_prepare(&lem);
	print_path(&lem);
//	lem_find_options(&lem);
	return 0;
}