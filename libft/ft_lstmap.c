#include "libft.h"

static t_list	*lstdel(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst)
	{
		if (lst->content != NULL)
			free(lst->content);
		free(lst);
		lst = lst->next;
	}
	lst = NULL;
	return (NULL);
}

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new;
	t_list *begin_new;

	begin_new = NULL;
	if (lst != NULL && f != NULL)
	{
		if (!(new = f(lst)))
			return (NULL);
		begin_new = new;
		lst = lst->next;
		while (lst != NULL)
		{
			if (!(new->next = f(lst)))
				return (lstdel(begin_new));
			new = new->next;
			lst = lst->next;
		}
	}
	return (begin_new);
}
