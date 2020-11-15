/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amepocch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 20:02:29 by amepocch          #+#    #+#             */
/*   Updated: 2019/12/12 01:33:20 by amepocch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*s1;
	unsigned char	*s2;

	i = 0;
	s1 = (unsigned char *)dst;
	s2 = (unsigned char *)src;
	if (dst == NULL && src == NULL && len > 0)
		return (dst);
	if (s2 > s1)
	{
		while (i < len)
		{
			s1[i] = s2[i];
			i++;
		}
	}
	else
		while (i < len)
		{
			s1[len - 1] = s2[len - 1];
			len--;
		}
	return (dst);
}
