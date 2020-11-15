#include "ft_printf.h"
int		ft_num_neg(t_data *p, int num)
{
	ft_putchar_fd('-', 1);
	p->size++;
	//p->width--;
	num *= -1;
	return (num);
}

void		ft_write_c(t_data *p)
{
	char	c;
	
	c = va_arg(p->list, int);
	if (p->width > 0)
		p->width--;
	if (p->minZ != 2)
		ft_write_width(p);
	write(1, &c, 1);
	p->size++;
	if (p->minZ == 2)
		ft_write_width(p);
}

void	ft_print_pre(t_data *p, int num)
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
		p->size = 10;
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

	
	/*if (p->minZ != 2)
	{
		if (num < 0 && p->minZ == 1)
			num = ft_num_neg(p, num);

	 	//ft_write_width(p, ft_intlen(num));
	}
	if (p->precision >= 1)
	{
	}
	// p->size += ft_intlen(num);
	// ft_putnbr_fd(num, 1);

	if (p->minZ == 2)
		//ft_write_width(p, ft_intlen(num));*/
}
/*

void	ft_write_d(t_data *p)
{
	int  num;
	num = va_arg(p->list, int);
		//printf("\nnum neg:%i\n", num);
	if (p->minZ != 2)
	{
		if (num < 0 && p->minZ == 1)
			num = ft_num_neg(p, num);

	 	//ft_write_width(p, ft_intlen(num));
	}
	p->size += ft_intlen(num);
	ft_putnbr_fd(num, 1);
	// p->size += ft_intlen(num);
	// ft_putnbr_fd(num, 1);

	if (p->minZ == 2)
		//ft_write_width(p, ft_intlen(num));
}*/
// void	ft_write_d(t_data *p)
// {
// 	int  num;
// 	num = va_arg(p->list, int);
// 		//printf("\nnum neg:%i\n", num);
// 	if (p->minZ != 2)
// 	{
// 		if (num < 0 && p->minZ == 1)
// 			num = ft_num_neg(p, num);

// 	 	//ft_write_width(p, ft_intlen(num));
// 	}
// 	// p->size += ft_intlen(num);
// 	// ft_putnbr_fd(num, 1);

// 	if (p->minZ == 2)
// 		//ft_write_width(p, ft_intlen(num));
// }

// void		ft_write_s(t_data *p)
// {
// 	char  *string;
// 	//int i = 0;
// 	string = va_arg(p->list, char *);

// 	//ft_write_width(p, ft_strlen(string));
// 	p->size += ft_strlen(string);
// 	if (p->precision > 0)
// 	{
// 		while (p->precision > 0)
// 		{
// 			ft_putstr_fd(string, 1);
// 			p->precision--;

// 		}
		
// 	}
// 	// else 
// 	// 		ft_putstr_fd(string, 1);
// }

void		ft_write_s(t_data *p)
{
	char  *string;
	string = va_arg(p->list, char *);
    //printf("1");
	if (p->minZ != 2)
	 	//ft_write_width(p, ft_strlen(string));
	p->size += ft_strlen(string);
	ft_putstr_fd(string, 1);
	//if (p->minZ == 2)
		//ft_write_width(p, ft_strlen(string));
}

void		ft_write_Xx(t_data *p)
{
	unsigned int  adr;
	char          *base;
	char          res[9];
	int           i;
	
	adr = va_arg(p->list, unsigned int);
	base = "0123456789abcdef";
	i = 8;
	while ((adr / 16) > 0) //|| i >= 8)
	{
    	res[i] = base[(adr % 16)];
    	adr /= 16;
    	i--;	
		//printf("res: %s\ni: %d\n", res, i);
	}
	res[i] = base[(adr % 16)];
	//printf("res: %s\nlen: %d\n", res, (int)ft_strlen(res));
	//write(1, "0x10", 4);					// modificar
	if (p->minZ != 2)
		//ft_write_width(p, 9 - i);
	p->size += 9 - i;
	while (i < 9)
	{
		if(*p->format == 'X')
			res[i] = ft_toupper(res[i]);
	 	write(1, &res[i], 1);
		i++;
	}	
	//if (p->minZ == 2)
		//ft_write_width(p, 9 - i);
} 