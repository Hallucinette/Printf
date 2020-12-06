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

void			ft_write_p(t_data *p)
{
	int len;
	long addr;

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
		{
			p->width -= 2;
			if (p->precision >= len + 2)
			{
				p->width -= p->precision;
				if(p->minZ == 1)
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
			{
				ft_write_width(p);
			}
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
			{
				ft_write_width(p);
			}
		}
	}
}

void	ft_write_u(t_data *p)
{
	unsigned int  num;
	int  nb;
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
	}
}
