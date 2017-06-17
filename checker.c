#include "lem_in.h

void		lem_check_room(char **tab)
{
	char *tmp;

	if (ft_tabcount(tab) != 3)
		lem_errors(INPUT_ERR);
	tmp = tab[1];
	while (*tmp)
	{
		if (!ft_isdigit(*tmp))
			lem_errors(INPUT_ERR);
		tmp++;
	}
	tmp = tab[2];
	while (*tmp)
	{
		if (!ft_isdigit(*tmp))
			lem_errors(INPUT_ERR);
		tmp++;
	}
}