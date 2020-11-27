#include "ft_printf.h"

void		ft_write_Xx(t_data *p)
{
	int		len;
	unsigned int	nbr;
	len = 0;
	nbr = va_arg(p->list, unsigned int);
	len = putnbr_base(nbr, "0123456789abcdef", p);
	if (len >= p->width && len >= p->precision)
	{
		if (!(p->precision == 0 && nbr == 0))
		{
			p->size += len;
			ft_put_xX(p, len);
		}
	}
	else
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
			ft_put_xX(p, len);
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
			
			if (p->minZ != 2)
				ft_write_width(p);
			while (p->precision > len)
			{
				ft_putchar_fd('0', 1);
				p->precision--;
			}
			if (p->precision == 0 && nbr == 0)
				ft_putchar_fd(' ', 1);
			else
				ft_put_xX(p, len);
			if (p->minZ == 2)
				ft_write_width(p);
		}
	}
}