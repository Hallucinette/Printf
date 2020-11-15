/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amepocch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 18:24:40 by amepocch          #+#    #+#             */
/*   Updated: 2019/12/13 09:12:57 by amepocch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	len_s;
	char	*dst;

	i = 0;
	if (!s)
		return (NULL);
	len_s = ft_strlen(s);
	if (!(dst = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	dst[0] = '\0';
	if (len_s < start)
		return (dst);
	if (start + len > len_s)
		len = len_s - start;
	while (i < len)
	{
		dst[i] = s[start];
		i++;
		start++;
	}
	dst[i] = '\0';
	return (dst);
}
