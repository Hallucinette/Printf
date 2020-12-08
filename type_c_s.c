/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_c_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amepocch <amepocch@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 01:01:55 by amepocch          #+#    #+#             */
/*   Updated: 2020/12/08 21:57:37 by amepocch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_write_c(t_data *p)
{
	char	c;

	p->precision = -1;
	if (p->width > 0)
		p->width--;
	if (p->minZ != 2)
		ft_write_width(p);
	if (*p->format == '%')
		write(1, "%", 1);
	else
	{
		c = va_arg(p->list, int);
		write(1, &c, 1);
	}
	p->size++;
	if (p->minZ == 2)
		ft_write_width(p);
}

void		ft_write_s(t_data *p)
{
 	char	*string;
	int		i;
	int		len;

	string = va_arg(p->list, char *);
	i = 0;
	if (string != NULL)
		len = ft_strlen(string);
	if (string == NULL)
	{
		string = "(null)";
		len = ft_strlen(string);
	}
	if (len >= p->width && (len <= p->precision || p->precision < 0))
	{
		ft_putstr_fd(string, 1);
		p->size += len;
	}
	else
	{
		if (p->precision >= 0 && p->precision < len && p->precision >= p->width)
		{
			while (p->precision > i)
				ft_putchar_fd(string[i++], 1);
			p->size += p->precision;
		}
		else
			ft_write_s2(p, len, i, string);
	}
}

void		ft_write_s2(t_data *p, int len, int i, char *string)
{
	if (p->precision < len && p->precision >= 0)
		p->width -= p->precision;
	else
		p->width = (p->width - len);
	if (p->minZ != 2)
		ft_write_width(p);
	if (p->precision < len && p->precision >= 0)
	{
		while (p->precision > i)
			ft_putchar_fd(string[i++], 1);
		p->size += p->precision;
	}
	else
	{
		ft_putstr_fd(string, 1);
		p->size += len;
	}
	if (p->minZ == 2)
		ft_write_width(p);
}
