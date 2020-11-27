#include "ft_printf.h"

int	putnbr_base(unsigned long nbr, char *base, t_data *p)
{
	int len;
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
	// if (nbr < 0)
	// 	len++;
	//p->size += len;
	return (len);
}

void			ft_write_p(t_data *p)
{
	int len;
	long addr;

	len = 0;
	addr = (long)va_arg(p->list, void *);
	len = putnbr_base(addr, "0123456789abcdef", p);
	if (p->precision < 0 && p->width == 0)
	{
		write(1, "0x", 2);
		p->size += 2;
		write(1, &(p->resp), len);
		p->size += len;
	}
	else
	{
		write(1, "0x", 2);
		p->size += 2;
		if (p->precision > 0 || addr > 0)
		{
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
	}
}