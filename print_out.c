/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_out.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaplyar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 21:26:26 by akaplyar          #+#    #+#             */
/*   Updated: 2017/09/07 21:27:41 by akaplyar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#define PATH lem->ants[i]->path
#define ROOM lem->rooms[lem->paths[PATH]->path[lem->ants[i]->room]]->name

static void	lem_print_input(t_lem *lem)
{
	t_list	*list;
	t_list	*tmp;

	list = lem->output;
	while (list)
	{
		ft_printf("%s\n", (char*)list->content);
		tmp = list;
		list = list->next;
		free(tmp->content);
		free(tmp);
	}
	ft_printf("\n");
	lem->output = NULL;
}

static int	lem_ant_check(t_lem *lem, int num)
{
	int		i;

	if (lem->ants[num]->room < 0)
		return (0);
	i = -1;
	while (++i < lem->ants_count)
		if (lem->ants[i]->path == lem->ants[num]->path && i != num)
			if (lem->ants[num]->room + 1 == lem->ants[i]->room)
				return (0);
	return (1);
}

static void	lem_print_ants(t_lem *lem)
{
	int		i;
	int		pass;

	pass = 1;
	while (pass)
	{
		i = -1;
		pass = 0;
		while (++i < lem->ants_count)
			if (lem_ant_check(lem, i))
			{
				if (pass)
					ft_printf(" ");
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
	lem_print_ants(lem);
}
