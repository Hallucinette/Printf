/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bomus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amepocch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 06:50:57 by amepocch          #+#    #+#             */
/*   Updated: 2019/12/13 08:14:32 by amepocch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list *save;
	t_list *begin;

	begin = *lst;
	save = *lst;
	if (!lst)
		return ;
	if (*lst == NULL || !del)
		return ;
	while (save)
	{
		del(save->content);
		begin = save;
		save = save->next;
		free(begin);
	}
	*lst = NULL;
}
