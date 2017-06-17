#include "lem_in.h"

void		lem_read(t_lem *lem)
{
	char	*buff;

	buff = NULL;
	get_line_by_line(0, &buff);
	lem->ants = ft_atoi(buff);
	while (get_line_by_line(0, &buff))
	{

	}
}