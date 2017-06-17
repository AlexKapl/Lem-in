#ifndef LEM_IN_H
#define LEM_IN_H

# include "libft/libft.h"

typedef struct	s_lem
{
	int			ants;
	int			start;
	int			end;
	char		**rooms;
	char		**links;
}				t_lem;

void			lem_read(t_lem *lem);

#endif