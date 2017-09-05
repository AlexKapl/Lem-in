#ifndef LEM_IN_H
#define LEM_IN_H

# define ANT_ERR 0
# define MLC_ERR 1
# define COMM_ERR 2
# define INPUT_ERR 3

# include "libft/libft.h"

typedef struct	s_options
{
	int			turns;
	t_list		**paths;
}				t_opt;

typedef struct	s_rooms
{
	char		*name;
	int			*links;
}				t_room;

typedef struct	s_lem
{
	int			ants;
	int			start;
	int			end;
	int			room;
	int			room_end;
	t_opt		*opt;
    t_list		*output;
	t_list		*rooms;
	t_list		*path;
	t_list		**hash;
	t_list		**p_hash;
}				t_lem;

void			lem_read(t_lem *lem);
void			lem_errors(int errnum);
void			lem_check_links(t_lem *lem);
void			lem_path_prepare(t_lem *lem);
void			lem_find_options(t_lem *lem);
void			lem_path_del(void *data, size_t size);
void			lem_check_room(char **tab, int room_end);
void			lem_links_operate(t_lem *lem, char *buff);
void			lem_rooms_operate(t_lem *lem, char *buff);
void			lem_comments_operate(t_lem *lem, char *buff);
int				lem_path_sort(size_t size1, size_t size2);
int				lem_new_node(void const *name, size_t size, t_list **node);

#endif