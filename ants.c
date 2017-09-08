/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaplyar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 21:18:21 by akaplyar          #+#    #+#             */
/*   Updated: 2017/09/07 21:19:00 by akaplyar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#define BEST lem->best->paths

int				lem_ant_check(t_lem *lem, int num)
{
	int			i;

	if (lem->ants[num]->room < 0)
		return (0);
	i = -1;
	while (++i < lem->ants_count)
		if (lem->ants[i]->path == lem->ants[num]->path && i != num)
			if (lem->ants[num]->room + 1 == lem->ants[i]->room)
				return (0);
	return (1);
}

void			lem_put_ants(t_lem *lem, t_opt *opt)
{
	int			i;
	int			count;
	int			min[2];
	int			path;

	i = 0;
	min[0] = INTMAX;
	min[1] = -1;
	while (i < opt->count)
	{
		path = opt->paths[i];
		count = lem->paths[path]->len + lem->paths[path]->ants;
		if (count < min[0])
		{
			min[0] = count;
			min[1] = path;
		}
		i++;
	}
	lem->paths[min[1]]->ants++;
}

static void		lem_create_ants(t_lem *lem)
{
	int			i;
	int			j;

	if (!(lem->ants = (t_ant**)malloc(sizeof(t_ant*) * lem->ants_count)))
		lem_errors(MLC_ERR);
	i = 0;
	while (i < lem->ants_count)
	{
		j = -1;
		while (++j < lem->best->count)
			if (i < lem->ants_count && lem->paths[BEST[j]]->ants)
			{
				if (!(lem->ants[i] = (t_ant*)malloc(sizeof(t_ant))))
					lem_errors(MLC_ERR);
				lem->ants[i]->num = i + 1;
				lem->ants[i]->path = BEST[j];
				lem->ants[i]->room = 1;
				lem->paths[BEST[j]]->ants--;
				i++;
			}
	}
}

void			lem_make_ants(t_lem *lem)
{
	int			i;
	int			*ants;

	ants = (int*)malloc(sizeof(int) * lem->path_count);
	i = -1;
	while (++i < lem->ants_count)
		lem_put_ants(lem, lem->best);
	i = -1;
	while (++i < lem->path_count)
		ants[i] = lem->paths[i]->ants;
	lem_create_ants(lem);
	lem_desolate_paths(lem);
	i = -1;
	while (++i < lem->path_count)
		lem->paths[i]->ants = ants[i];
	free(ants);
}
