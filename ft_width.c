/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amepocch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 23:33:00 by amepocch          #+#    #+#             */
/*   Updated: 2020/12/10 02:24:28 by amepocch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_intlen(long int n)
{
	long int	len;

	len = 1;
	if (n < 0)
		len++;
	while (n <= -10 || n >= 10)
	{
		n /= 10;
		len++;
	}
	return (len);
}

int		ft_check_wp(t_data *p)
{
	int		tmp;

	tmp = 0;
	if (*p->format == '*')
	{
		tmp = va_arg(p->list, int);
		if (tmp < 0 && p->dot == 0)
		{
			p->minz = 2;
			tmp *= -1;
		}
		p->format++;
	}
	else
	{
		while (ft_isdigit(*p->format) == 1)
		{
			tmp *= 10;
			tmp += *p->format - 48;
			p->format++;
		}
	}
	return (tmp);
}

void	ft_write_width(t_data *p)
{
	p->size += p->width;
	while (p->width > 0)
	{
		if (p->minz == 1 && (p->precision < 0 || *p->format == 's'))
			ft_putchar_fd('0', 1);
		else
			ft_putchar_fd(' ', 1);
		p->width--;
	}
}

void	ft_print_pre(t_data *p, long int num)
{
	if (num < 0)
		num = ft_num_neg(p, num);
	p->precision = p->precision - ft_intlen(num);
	while (p->precision > 0)
	{
		p->size++;
		ft_putchar_fd('0', 1);
		p->precision--;
	}
	p->size += ft_intlen(num);
	ft_putnbr_fd(num, 1);
}
