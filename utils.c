#include "lem_in.h"

int			lem_path_sort(size_t size1, size_t size2)
{
	return (size1 > size2 ? 1 : 0);
}

void		lem_path_del(void *data, size_t size)
{
	int		*path;

	path = (int*)data;
	free(path);
	(void)size;
}