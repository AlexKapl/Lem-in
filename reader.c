#include "lem_in.h"

static void	lem_get_ants_count(t_lem *lem)
{
	char	*buff;

	buff = NULL;
	get_line(0, &buff);
	lem->ants_count = ft_atoi(buff);
	if (lem->ants_count <= 0)
		lem_errors(ANT_ERR);
	ft_strdel(&buff);
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
			ft_strdel(&buff);
			return ;
		}
		if (!*buff)
			lem_errors(INPUT_ERR);
		else if (*buff == '#')
			lem_comments_operate(lem, buff);
		else if (ft_strchr(buff, '-'))
			lem_links_operate(lem, buff);
		else
			lem_rooms_operate(lem, buff);
		ft_lst_push_back(&lem->output, ft_lstnew(buff, ft_strlen(buff) + 1));
		ft_strdel(&buff);
	}
}