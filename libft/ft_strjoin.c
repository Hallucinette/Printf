/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amepocch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 06:27:45 by amepocch          #+#    #+#             */
/*   Updated: 2019/12/12 01:34:39 by amepocch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strcat(char *str1, char *str2)
{
	int		len;
	int		i;

	len = ft_strlen(str1);
	i = 0;
	while (str2[i])
	{
		str1[len + i] = str2[i];
		i++;
	}
	str1[len + i] = '\0';
	return (str1);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		total_size;
	char	*new;

	if (!s1 || !s2)
		return (NULL);
	total_size = ft_strlen(s1) + ft_strlen(s2);
	i = 0;
	if (!(new = malloc(total_size + 1)))
		return (NULL);
	new[0] = '\0';
	new = ft_strcat(new, (char *)s1);
	new = ft_strcat(new, (char *)s2);
	return (new);
}
