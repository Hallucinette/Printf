/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amepocch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 06:36:48 by amepocch          #+#    #+#             */
/*   Updated: 2019/12/13 06:47:24 by amepocch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list *save;

	save = *alst;
	if (*alst == NULL)
		*alst = new;
	else
	{
		while (save->next)
			save = save->next;
		save->next = new;
	}
}
