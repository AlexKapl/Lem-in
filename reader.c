#include "lem_in.h"

static void	lem_get_ants_count(t_lem *lem)
{
	char	*buff;

	buff = NULL;
	get_line(0, &buff);
	lem->ants = ft_atoi(buff);
	if (lem->ants <= 0)
		lem_errors(ANT_ERR);
}

void		lem_read(t_lem *lem)
{
	char	*buff;

	buff = NULL;
	lem_get_ants_count(lem);
	while (get_line(0, &buff))
	{
		if (*buff == '%')
		{
			free(buff);
			return ;
		}
		if (!*buff || *buff == '\n')
			lem_errors(INPUT_ERR);
		else if (*buff == '#')
			lem_comments_operate(lem, buff);
		else if (ft_strchr(buff, '-'))
			lem_links_operate(lem, buff);
		else
			lem_rooms_operate(lem, buff);
		free(buff);
	}
}