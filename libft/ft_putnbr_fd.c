/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amepocch <amepocch@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 22:40:04 by amepocch          #+#    #+#             */
/*   Updated: 2020/12/02 00:33:45 by amepocch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(long int n, int fd)
{
	int l;
	long int save;

	l = 1;
	save = n;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		l = -1;
	}
	while (n <= -10 || n >= 10)
	{
		n = n / 10;
		l = l * 10;
	}
	while (l != 0)
	{
		ft_putchar_fd((save / l) + 48, fd);
		save -= (save / l) * l;
		l /= 10;
	}
}
