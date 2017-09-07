/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaplyar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 21:21:49 by akaplyar          #+#    #+#             */
/*   Updated: 2017/09/07 21:22:43 by akaplyar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# define ANT_ERR 0
# define MLC_ERR 1
# define COMM_ERR 2
# define INPUT_ERR 3

# include "libft/libft.h"

typedef struct	s_ant
{
	int			num;
	int			room;
	int			path;
}				t_ant;

typedef struct	s_options
{
	int			count;
	int			*paths;
}				t_opt;

typedef struct	s_path
{
	int			len;
	int			ants;
	int			*path;
}				t_path;

typedef struct	s_rooms
{
	char		*name;
	int			*cords;
	int			*links;
}				t_room;

typedef struct	s_lem
{
	int			ants_count;
	int			path_count;
	int			opt_count;
	int			start;
	int			end;
	int			err;
	int			room;
	int			room_end;
	t_opt		*best;
	t_opt		**opts;
	t_ant		**ants;
	t_room		**rooms;
	t_path		**paths;
	t_list		*tmp;
	t_list		*output;
}				t_lem;

void			lem_read(t_lem *lem);
void			lem_errors(int errnum);
void			lem_opt_hash(t_lem *lem);
void			lem_room_hash(t_lem *lem);
void			lem_path_hash(t_lem *lem);
void			lem_make_ants(t_lem *lem);
void			lem_check_links(t_lem *lem);
void			lem_print_output(t_lem *lem);
void			lem_path_prepare(t_lem *lem);
void			lem_find_options(t_lem *lem);
void			lem_find_best_opt(t_lem *lem);
void			lem_desolate_paths(t_lem *lem);
void			lem_put_ants(t_lem *lem, t_opt *opt);
void			lem_del_tmp(void *data, size_t size);
void			lem_links_operate(t_lem *lem, char *buff);
void			lem_rooms_operate(t_lem *lem, char *buff);
void			lem_comments_operate(t_lem *lem, char *buff);
int				lem_check_room(t_lem *lem, char **tab);
int				lem_new_opt(void const *data, size_t size, t_list **node);
int				lem_new_path(void const *data, size_t size, t_list **node);
int				lem_new_room(void const *name, size_t size, t_list **node);

#endif
