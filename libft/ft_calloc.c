/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amepocch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 16:22:51 by amepocch          #+#    #+#             */
/*   Updated: 2019/12/12 01:31:35 by amepocch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void *nemo;

	if (!(nemo = malloc(count * size)))
		return (NULL);
	ft_bzero(nemo, count * size);
	return (nemo);
}
