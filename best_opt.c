/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_opt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaplyar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 21:20:05 by akaplyar          #+#    #+#             */
/*   Updated: 2017/09/07 21:20:19 by akaplyar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		lem_count_turns(t_lem *lem, int opt)
{
	int			i;
	int			path;
	int			turns[2];

	i = -1;
	while (++i < lem->ants_count)
		lem_put_ants(lem, lem->opts[opt]);
	i = 0;
	turns[0] = -1;
	turns[1] = -1;
	while (i < lem->opts[opt]->count)
	{
		path = lem->opts[opt]->paths[i];
		if (lem->paths[path]->ants)
		{
			turns[1] = lem->paths[path]->ants + lem->paths[path]->len - 2;
			if (turns[0] < turns[1])
				turns[0] = turns[1];
		}
		i++;
	}
	return (turns[0]);
}

void			lem_find_best_opt(t_lem *lem)
{
	int			i;
	int			turns;
	int			min[2];

	min[0] = INTMAX;
	min[1] = -1;
	i = 0;
	while (i < lem->opt_count)
	{
		if ((turns = lem_count_turns(lem, i)) < min[0])
		{
			min[0] = turns;
			min[1] = i;
		}
		lem_desolate_paths(lem);
		i++;
	}
	lem->best = lem->opts[min[1]];
}
