/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amepocch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 22:50:58 by amepocch          #+#    #+#             */
/*   Updated: 2020/12/09 23:00:12 by amepocch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		putnbr_base(unsigned long nbr, char *base, t_data *p)
{
	int				len;
	unsigned long	power;
	unsigned long	save;

	len = 0;
	save = nbr;
	power = 1;
	while (nbr >= 16)
	{
		nbr /= 16;
		power *= 16;
	}
	while (power)
	{
		p->resp[len++] = base[save / power];
		save = save - (save / power) * power;
		power = power / 16;
	}
	return (len);
}

void	ft_write_p(t_data *p)
{
	int		len;
	long	addr;

	len = 0;
	addr = (long)va_arg(p->list, void *);
	len = putnbr_base(addr, "0123456789abcdef", p);
	if (p->precision <= len + 2 && p->width <= len + 2)
	{
		write(1, "0x", 2);
		p->size += 2;
		if (!(p->precision == 0 && addr == 0))
		{
			write(1, &(p->resp), len);
			p->size += len;
		}
	}
	else
		ft_write_p2(p, len, addr);
}

void	ft_write_p2(t_data *p, int len, long addr)
{
	if (p->precision >= p->width)
	{
		write(1, "0x", 2);
		p->size += 2;
		p->precision -= len;
		p->size += p->precision;
		while (p->precision > 0)
		{
			ft_putchar_fd('0', 1);
			p->precision--;
		}
		write(1, &(p->resp), len);
		p->size += len;
	}
	else
		ft_write_p3(p, len, addr);
}

void	ft_write_p3(t_data *p, int len, long addr)
{
	if (p->precision <= p->width)
	{
		p->width -= 2;
		if (p->precision >= len + 2)
		{
			p->width -= p->precision;
			if (p->minZ == 1)
				p->minZ = 0;
		}
		else
		{
			if (!(p->precision == 0 && addr == 0))
				p->width -= len;
		}
		if (p->minZ == 1 && p->precision != 0)
			write(1, "0x", 2);
		if (p->minZ != 2)
			ft_write_width(p);
		ft_write_p4(p, len, addr);
	}
}

void	ft_write_p4(t_data *p, int len, long addr)
{
	if (p->minZ != 1 || p->precision == 0)
		write(1, "0x", 2);
	p->size += 2;
	if (p->precision > len)
	{
		p->precision -= len;
		p->size += p->precision;
		while (p->precision > 0)
		{
			ft_putchar_fd('0', 1);
			p->precision--;
		}
		p->precision++;
	}
	if (!(p->precision == 0 && addr == 0))
	{
		write(1, &(p->resp), len);
		p->size += len;
	}
	if (p->minZ == 2)
		ft_write_width(p);
}
