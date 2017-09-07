/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaplyar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 21:25:27 by akaplyar          #+#    #+#             */
/*   Updated: 2017/09/07 21:26:15 by akaplyar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	*lem_copy_opt(int *path, int count)
{
	int		*copy;
	int		j;

	if (!(copy = (int*)malloc(sizeof(int) * count)))
		return (NULL);
	j = 0;
	while (j < count)
	{
		copy[j] = path[j];
		j++;
	}
	return (copy);
}

static int	lem_is_parallel(t_lem *lem, int path1, int path2)
{
	int		i;
	int		j;
	int		*p1;
	int		*p2;

	i = 0;
	if (path1 == path2)
		return (0);
	p1 = lem->paths[path1]->path;
	p2 = lem->paths[path2]->path;
	while (p1[i] >= 0 && p1[i] < lem->room)
	{
		j = 0;
		while (p2[j] >= 0 && p2[j] < lem->room)
		{
			if (p1[i] == p2[j] && p1[i] != lem->start && p1[i] != lem->end)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static int	lem_is_parallels(t_lem *lem, int *opt, int len, int path)
{
	int		i;

	i = -1;
	while (++i < len)
		if (!lem_is_parallel(lem, opt[i], path))
			return (0);
	return (1);
}

static void	lem_find_parallels(t_lem *lem, int *start, int len, int path)
{
	int		i;
	int		flag;
	int		*opt;

	flag = 0;
	if (!(opt = lem_copy_opt(start, lem->path_count)))
		return ;
	opt[len++] = path;
	i = -1;
	while (++i < lem->path_count)
		if (lem_is_parallels(lem, opt, len, i))
		{
			lem_find_parallels(lem, opt, len, i);
			flag++;
		}
	if (!flag)
		ft_lstadd(&lem->tmp, ft_lstnew_struct(opt, (size_t)len, lem_new_opt));
	free(opt);
}

void		lem_find_options(t_lem *lem)
{
	int		*opt;
	int		i;

	opt = (int*)malloc(sizeof(int) * lem->path_count);
	i = 0;
	while (i < lem->path_count)
		opt[i++] = -1;
	i = 0;
	while (i < lem->path_count)
	{
		lem_find_parallels(lem, opt, 0, i);
		i++;
	}
	free(opt);
	lem_opt_hash(lem);
}
