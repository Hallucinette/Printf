#include "ft_printf.h"
int		ft_convert_base(t_data *p)
{
	char         	*base;
	int          	i;
	
	base = "0123456789abcdef";
	i = 8;
	while ((p->adr / 16) > 0)
	{
    	p->res[i] = base[(p->adr % 16)];
    	p->adr /= 16;
    	i--;	
	}
	p->res[i] = base[(p->adr % 16)];
	p->reslen = 9 - i;
	return (i);
}

void		ft_write_Xx(t_data *p)
{
	//unsigned int 	adr;
	//char         	*base;
	//char         	res[9];
	int          	i;
	//int				len;
	
	p->adr = va_arg(p->list, unsigned int);
	// base = "0123456789abcdef";
	// i = 8;
	// while ((adr / 16) > 0)
	// {
    // 	res[i] = base[(adr % 16)];
    // 	adr /= 16;
    // 	i--;	
	// }
	// res[i] = base[(adr % 16)];
	// len = 9 - i;
	i = ft_convert_base(p);
	if (p->reslen >= p->width && p->reslen >= p->precision)
	{
		if (!(p->precision == 0 && p->adr == 0))
		{
			p->size += p->reslen;
			ft_put_xX(p, p->res, i);
		}
	}
	else
	{
		if (p->precision >= p->reslen && p->precision >= p->width && p->precision > 0)
		{
			p->size += p->precision;
			p->precision -= p->reslen;
			while (p->precision > 0)
			{
				write(1, "0", 1);
				p->precision--;
			}
			ft_put_xX(p, p->res, i);
		}
		else
		{
			if (p->precision <= p->reslen)
			{
				p->size += p->reslen;
				p->width -= p->reslen;
			}
			else
			{
				p->size += p->precision;
				p->width -= p->precision; 
			}
			
			if (p->minZ != 2)
				ft_write_width(p);
			while (p->precision > p->reslen)
			{
				ft_putchar_fd('0', 1);
				p->precision--;
			}
			if (p->precision == 0)
				ft_putchar_fd(' ', 1);
			else
				ft_put_xX(p, p->res, i);
			if (p->minZ == 2)
				ft_write_width(p);
		}
	}
}