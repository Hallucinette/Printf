#include "ft_printf.h"

void				ft_write_u(t_data *p)
{
	unsigned int	num;
	int				nb;

	nb = va_arg(p->list, int);
	if (nb < 0)
		num = 4294967295 + nb + 1;
	else
		num = nb;
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
		if(p->precision >= p->width)
			ft_print_pre(p, num);
		else
			ft_write_u2(p, num);
	}
}


void	ft_write_u2(t_data *p, long num)
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
	if (p->minZ != 2)
		ft_write_width(p);
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
	if (p->minZ == 2)
		ft_write_width(p);
}
