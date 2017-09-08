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
	lem->moves = 0;
	lem->start = -1;
	lem->room_end = 0;
	lem->opt_count = 0;
	lem->ants_count = 0;
	lem->path_count = 0;
	lem->print_best = 0;
	lem->print_paths = 0;
	lem->print_moves = 0;
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
	lem_find_options(&lem);
	lem_find_best_opt(&lem);
	lem_make_ants(&lem);
	lem_print_output(&lem);
	return (0);
}
