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
	//len += 2;
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
				p->width -= p->precision;
			else
			{
				if (!(p->precision == 0 && addr == 0))
					p->width -= len;
			}
			if (p->minZ != 2)
			{
				ft_write_width(p);
			}
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
				// write(1, &(p->resp), len);
				// p->size += len;
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


////////////////////// TYPE U //////////////////////


// void	ft_print_pre(t_data *p, int num)
// {
// 	if (num < 0)
// 		num = ft_num_neg(p, num);
// 	p->precision = p->precision - ft_intlen(num);
// 	while(p->precision > 0)
// 	{
// 		p->size++;
// 		ft_putchar_fd('0', 1);
// 		p->precision--;
// 	}
// 	p->size += ft_intlen(num);
// 	ft_putnbr_fd(num, 1);
// }

void	ft_write_u(t_data *p)
{
	unsigned int  num;
	// num = va_arg(p->list, unsigned int);

	//printf("%d", ft_intlen(num));
	int  nb;
	//unsigned int nb;
	nb = va_arg(p->list, int);
	//num = nb;

	if (nb < 0)
	{
		// p->size += 9;
		// write(1, "4294967295", 9);
		num = 4294967295 + nb + 1;
		// p->width -= 9;
		// p->precision -= 9;
	}
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
	// 		num = 42 | width == 19 | p == 14
	//TEST nb = 4568 | width = 15 | precision = -7
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
				p->width = (p->width - p->precision); // width == 5
				if (num < 0)
					p->width--;	
			}
			if (p->minZ != 2) // si c'est pas '-'
			{
				// if (num < 0 && p->minZ == 1 && p->precision == -1)
				// 	num = ft_num_neg(p, num);
				ft_write_width(p);
			}
			if (p->precision > 0)
				ft_print_pre(p, num);
			else
			{
				if (!(p->precision == 0 && num == 0))
				{
					//num = ft_num_neg(p, num);
					ft_putnbr_fd(num, 1);
					p->size += ft_intlen(num);
				}
			}
			if (p->minZ == 2)
				ft_write_width(p);
		}
	}
}