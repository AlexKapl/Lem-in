#include "lem_in.h"

static void print_path(t_lem *lem)
{
	t_room	*r;
	t_path	*p;
	size_t 	i;
	int		j;

	j = 0;
	while (j < lem->path_count)
	{
		i = 0;
		p = lem->path[j];
		while (i < p->len)
		{
			r = lem->rooms[p->path[i]];
			ft_printf("%s", r->name);
			if (i + 1 != p->len)
				ft_printf(" -> ");
			i++;
		}
		ft_printf(" | %zu\n", p->len);
		j++;
	}
	ft_printf("\n\n");
}

static void print_opt(t_lem *lem)
{
	t_path	*p;
	size_t	i;
	int		*opt;
	int		j;
	int		x;

	j = 0;
	while(j < lem->opt_count)
	{
		i = 0;
		opt = lem->opt[j]->paths;
		ft_printf("{\n");
		while (i < lem->opt[j]->count)
		{
			x = 0;
			p = lem->path[opt[i]];
			ft_printf("\t");
			while (x < p->len)
			{
				ft_printf("%s", lem->rooms[p->path[x]]->name);
				if (x + 1 != p->len)
					ft_printf(" -> ");
				x++;
			}
			ft_printf("\n");
			i++;
		}
		ft_printf("} %d\n\n", j);
		j++;
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
	lem->room = 0;
	lem->end = -1;
	lem->start = -1;
	lem->room_end = 0;
	lem->opt_count = 0;
	lem->ants_count = 0;
	lem->path_count = 0;
	lem->tmp = NULL;
	lem->opt = NULL;
	lem->best = NULL;
	lem->path = NULL;
	lem->rooms = NULL;
	lem->output = NULL;
}

int			main()
{
	t_lem	lem;
	int		i;

	lem_struct_init(&lem);
	lem_read(&lem);
	lem_path_prepare(&lem);
	print_path(&lem);
	lem_find_options(&lem);
	print_opt(&lem);
//	lem_find_best_opt(&lem);
	return 0;
}