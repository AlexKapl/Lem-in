/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaplyar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 21:22:53 by akaplyar          #+#    #+#             */
/*   Updated: 2017/09/07 21:23:32 by akaplyar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		p = lem->paths[j];
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
		opt = lem->opts[j]->paths;
		ft_printf("{\n");
		while (i < lem->opts[j]->count)
		{
			x = 0;
			p = lem->paths[opt[i]];
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

static void	print_best(t_lem *lem)
{
	int		j;
	int		i;

	i = 0;
	ft_printf("{green}best opt\n{\n");
	while (i < lem->best->count)
	{
		j = 0;
		ft_printf("\t");
		while (j < lem->paths[lem->best->paths[i]]->len)
		{
			ft_printf("{green}%s", lem->rooms[lem->paths[lem->best->paths[i]]->path[j]]->name);
			if (j + 1 != lem->paths[lem->best->paths[i]]->len)
				ft_printf("{green} -> ");
			j++;
		}
		ft_printf("\n");
		i++;
	}
	ft_printf("{green}}\n{eoc}");
}

void		lem_errors(int errnum)
{
	if (errnum == MLC_ERR)
		ft_printf("{fd}ERROR: Can't allocate memory\n", 2);
	else
		ft_printf("{fd}ERROR\n", 2);
	exit(errnum);
}

static void	lem_struct_init(t_lem *lem)
{
	lem->err = 0;
	lem->room = 0;
	lem->end = -1;
	lem->start = -1;
	lem->room_end = 0;
	lem->opt_count = 0;
	lem->ants_count = 0;
	lem->path_count = 0;
	lem->tmp = NULL;
	lem->ants = NULL;
	lem->opts = NULL;
	lem->best = NULL;
	lem->paths = NULL;
	lem->rooms = NULL;
	lem->output = NULL;
}

int			main(void)
{
	t_lem	lem;

	lem_struct_init(&lem);
	lem_read(&lem);
	lem_path_prepare(&lem);
//	print_path(&lem);
	lem_find_options(&lem);
//	print_opt(&lem);
	lem_find_best_opt(&lem);
//	print_best(&lem);
	lem_make_ants(&lem);
	lem_print_output(&lem);
	return (0);
}
