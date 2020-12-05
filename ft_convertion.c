#include "ft_printf.h"

int		ft_num_neg(t_data *p, int num)
{
	ft_putchar_fd('-', 1);
	p->size++;
        	num *= -1;
	return (num);
}

void		ft_put_xX(t_data *p, int len)
{
	int i;

	i = 0;
	if(*p->format == 'X')
	{
		while (p->resp[i])
		{
			p->resp[i] = ft_toupper(p->resp[i]);
			i++;
		}
	}
	write(1, &(p->resp), len);
}

// void		ft_write_c(t_data *p)
// {
// 	char	c;
	
// 	c = va_arg(p->list, int);
// 	if (p->width > 0)
// 		p->width--;
// 	if (p->minZ != 2)
// 		ft_write_width(p);
// 	if (*p->format == '%')
// 		write(1, "%", 1);
// 	else
// 		write(1, &c, 1);
// 	p->size++;
// 	if (p->minZ == 2)
// 		ft_write_width(p);
// }

// 
void		ft_write_c(t_data *p)
{
	char	c;

	if (p->width > 0)
		p->width--;
	if (p->minZ != 2)
		ft_write_width(p);
	if (*p->format == '%')
		write(1, "%", 1);
	else
	{
		c = va_arg(p->list, int);
		write(1, &c, 1);
	}
	p->size++;
	if (p->minZ == 2)
		ft_write_width(p);
}

void		ft_write_s(t_data *p)
{
 	char	*string;
	int		i;
	int		len;

	string = va_arg(p->list, char *);
	i = 0;
	
	if (string != NULL)
		len = ft_strlen(string);
	if (string == NULL)
	{
		string = "(null)";
		len = ft_strlen(string);
	}
	if (len >= p->width && (len <= p->precision || p->precision < 0))
	{
		ft_putstr_fd(string, 1);
		p->size += len;
	}
	else
	{
		if (p->precision >= 0 && p->precision < len && p->precision >= p->width)
		{
			while (p->precision > i)
			{
				ft_putchar_fd(string[i], 1);
				i++;
			}
			p->size += p->precision;
		}
		else
		{
			if (p->precision < len && p->precision >= 0)
				p->width -= p->precision;
			else
				p->width = (p->width - len);
			if (p->minZ != 2)
				ft_write_width(p);
			if (p->precision < len && p->precision >= 0)
			{
				while (p->precision > i)
				{
					ft_putchar_fd(string[i], 1);
					i++;
				}
				p->size += p->precision;
			}
			else
			{
				ft_putstr_fd(string, 1);
				p->size += len;
			}
			if (p->minZ == 2)
				ft_write_width(p);
		}
	}
}

void	ft_print_pre(t_data *p, long int num)
{
	if (num < 0)
		num = ft_num_neg(p, num);
	p->precision = p->precision - ft_intlen(num);
	while(p->precision > 0)
	{
		p->size++;
		ft_putchar_fd('0', 1);
		p->precision--;
	}
	p->size += ft_intlen(num);
	ft_putnbr_fd(num, 1);
}

void	ft_write_d(t_data *p)
{
	int  num;
	num = va_arg(p->list, int);
	
	if (*p->format == 'u' && num < 0)
	{
		p->size += 10;
		write(1, "4294967295", 10);
	}
	else
	{
		if (ft_intlen(num) >= p->width && ft_intlen(num) >= p->precision)
			{
				if (!(p->precision == 0 && num == 0))
				{
					p->size += ft_intlen(num);
					ft_putnbr_fd(num, 1);
				}
			}
		//	num = 42 | width == 19 | p == 14
		else
		{
			if(p->precision >= p->width)
				ft_print_pre(p, num);
			else
			{
				if (ft_intlen(num) > p->precision && 
					!(p->precision == 0 && num == 0))
						p->width = (p->width - ft_intlen(num));  //??
				else
				{
					p->width = (p->width - p->precision); // 5
					if (num < 0)
						p->width--;
				}
				if (p->minZ != 2)  // si != ' '
				{
					if (num < 0 && p->minZ == 1 && p->precision == -1)
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
				if (p->minZ == 2)
					ft_write_width(p);
			}
		}
	}
}