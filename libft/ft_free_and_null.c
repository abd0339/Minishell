
#include "libft.h"

void	ft_free_and_null(void **ptr_ref)
{
	if (ptr_ref && *ptr_ref)
	{
		free(*ptr_ref);
		*ptr_ref = NULL;
	}
}