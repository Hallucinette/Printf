/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amepocch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 22:42:38 by amepocch          #+#    #+#             */
/*   Updated: 2020/12/10 00:40:13 by amepocch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_num_neg(t_data *p, int num)
{
	ft_putchar_fd('-', 1);
	p->size++;
	num *= -1;
	return (num);
}

void	ft_write_d(t_data *p)
{
	int		num;

	num = va_arg(p->list, int);
	if (ft_intlen(num) >= p->width && ft_intlen(num) >= p->precision)
	{
		if (!(p->precision == 0 && num == 0))
		{
			p->size += ft_intlen(num);
			ft_putnbr_fd(num, 1);
		}
	}
	else
	{
		if (p->precision >= p->width)
			ft_print_pre(p, num);
		else
		{
			if (ft_intlen(num) > p->precision &&
					!(p->precision == 0 && num == 0))
				p->width = (p->width - ft_intlen(num));
			else
			{
				p->width = (p->width - p->precision);
				if (num < 0)
					p->width--;
			}
			ft_write_d2(p, num);
		}
	}
}

void	ft_write_d2(t_data *p, int num)
{
	if (p->minz != 2)
	{
		if (num < 0 && p->minz == 1 && p->precision == -1)
			num = ft_num_neg(p, num);
		ft_write_width(p);
	}
	if (p->precision > 0)
		ft_print_pre(p, num);
	else
	{
		if (!(p->precision == 0 && num == 0))
		{
			ft_putnbr_fd(num, 1);
			p->size += ft_intlen(num);
		}
	}
	if (p->minz == 2)
		ft_write_width(p);
}
