#ifndef LEM_IN_H
#define LEM_IN_H

#define ANT_ERR 0
#define INPUT_ERR 1

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
	t_list		*hash;
}				t_lem;

void			lem_read(t_lem *lem);
void			lem_errors(int errnum);
void			lem_check_room(char **tab);
void			lem_links_operate(t_lem *lem, char *buff);
void			lem_rooms_operate(t_lem *lem, char *buff);
void			lem_comments_operate(t_lem *lem, char *buff);

#endif