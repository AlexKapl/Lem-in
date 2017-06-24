#ifndef LEM_IN_H
#define LEM_IN_H

# define ANT_ERR 0
# define INPUT_ERR 1
# define MLC_ERR 2

# include "libft/libft.h"

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
	t_list		*rooms;
	t_list		*path;
	t_list		**hash;
}				t_lem;

void			lem_read(t_lem *lem);
void			lem_errors(int errnum);
void			lem_make_hash(t_lem *lem);
void			lem_check_room(char **tab, int room_end);
void			lem_links_operate(t_lem *lem, char *buff);
void			lem_rooms_operate(t_lem *lem, char *buff);
void			lem_comments_operate(t_lem *lem, char *buff);
void 			lem_find_paths(t_lem *lem, int room, int *path, int len);
int				lem_new_node(void const *name, size_t size, t_list **node);

void			check(t_lem *lem);
#endif