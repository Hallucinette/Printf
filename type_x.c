/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amepocch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 23:02:56 by amepocch          #+#    #+#             */
/*   Updated: 2020/12/10 01:35:46 by amepocch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_x(t_data *p, int len)
{
	int	i;

	i = 0;
	if (*p->format == 'X')
	{
		while (p->resp[i])
		{
			p->resp[i] = ft_toupper(p->resp[i]);
			i++;
		}
	}
	write(1, &(p->resp), len);
}

void	ft_write_x(t_data *p)
{
	int				len;
	unsigned int	nbr;

	nbr = va_arg(p->list, unsigned int);
	len = putnbr_base(nbr, "0123456789abcdef", p);
	if (len >= p->width && len >= p->precision)
	{
		if (!(p->precision == 0 && nbr == 0))
		{
			p->size += len;
			ft_put_x(p, len);
		}
	}
	else
		ft_write_x2(p, len, nbr);
}

void	ft_write_x2(t_data *p, int len, unsigned int nbr)
{
	if (p->precision >= len && p->precision >= p->width && p->precision > 0)
	{
		p->size += p->precision;
		p->precision -= len;
		while (p->precision > 0)
		{
			write(1, "0", 1);
			p->precision--;
		}
		ft_put_x(p, len);
	}
	else
	{
		if (p->precision <= len)
		{
			p->size += len;
			p->width -= len;
		}
		else
		{
			p->size += p->precision;
			p->width -= p->precision;
		}
		ft_write_x3(p, len, nbr);
	}
}

void	ft_write_x3(t_data *p, int len, unsigned int nbr)
{
	if (p->minz != 2)
		ft_write_width(p);
	while (p->precision > len)
	{
		ft_putchar_fd('0', 1);
		p->precision--;
	}
	if (p->precision == 0 && nbr == 0)
		ft_putchar_fd(' ', 1);
	else
		ft_put_x(p, len);
	if (p->minz == 2)
		ft_write_width(p);
}
