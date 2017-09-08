/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_out.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaplyar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 21:26:26 by akaplyar          #+#    #+#             */
/*   Updated: 2017/09/08 11:36:25 by akaplyar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#define PATH lem->ants[i]->path
#define ROOM lem->rooms[lem->paths[PATH]->path[lem->ants[i]->room]]->name

static void	lem_print_best(t_lem *lem)
{
	int		j;
	int		i;

	i = 0;
	ft_printf("{green}Best option\n{\n");
	while (i < lem->best->count)
	{
		j = 0;
		ft_printf("\t");
		while (j < lem->paths[lem->best->paths[i]]->len)
		{
			ft_printf("%s",
					lem->rooms[lem->paths[lem->best->paths[i]]->path[j]]->name);
			if (j + 1 != lem->paths[lem->best->paths[i]]->len)
				ft_printf(" -> ");
			j++;
		}
		ft_printf("\n");
		i++;
	}
	ft_printf("}\n\n{eoc}");
}

static void	lem_print_path(t_lem *lem)
{
	t_room	*r;
	t_path	*p;
	size_t	i;
	int		j;

	j = 0;
	ft_printf("{yellow}All possible paths:\n\t(Path | length)\n{\n");
	while (j < lem->path_count)
	{
		i = 0;
		p = lem->paths[j];
		ft_printf("\t");
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
	ft_printf("}\n\n{eoc}");
}

static void	lem_print_input(t_lem *lem)
{
	t_list	*tmp;
	char	*line;

	while (lem->output)
	{
		line = (char*)lem->output->content;
		if (!ft_strcmp(line, "##start") || !ft_strcmp(line, "##end"))
			ft_printf("{red}%s{eoc}\n", line);
		else if (!ft_strcmp(line, "##best"))
			ft_printf("{green}%s{eoc}\n", line);
		else if (!ft_strcmp(line, "##paths"))
			ft_printf("{yellow}%s{eoc}\n", line);
		else if (!ft_strcmp(line, "##moves"))
			ft_printf("{magenta}%s{eoc}\n", line);
		else if (line[0] == '#')
			ft_printf("{black}%s{eoc}\n", line);
		else
			ft_printf("%s\n", line);
		tmp = lem->output;
		lem->output = lem->output->next;
		free(tmp->content);
		free(tmp);
	}
	ft_printf("\n");
}

static void	lem_print_ants(t_lem *lem)
{
	int		i;
	int		pass;

	pass = 1;
	while (pass)
	{
		lem->moves++;
		i = -1;
		pass = 0;
		while (++i < lem->ants_count)
			if (lem_ant_check(lem, i))
			{
				if (pass)
					ft_printf(" ");
				else if (lem->print_moves)
					ft_printf("%d | ", lem->moves);
				pass = 1;
				ft_printf("L%d-%s", lem->ants[i]->num, ROOM);
				if (++lem->ants[i]->room >= lem->paths[lem->ants[i]->path]->len)
					lem->ants[i]->room = -1;
			}
		ft_printf("\n");
	}
}

void		lem_print_output(t_lem *lem)
{
	lem_print_input(lem);
	if (lem->print_paths)
		lem_print_path(lem);
	if (lem->print_best)
		lem_print_best(lem);
	lem_print_ants(lem);
	if (lem->print_moves)
		ft_printf("{magenta}Total moves: %d\n{eoc}", --lem->moves);
}
