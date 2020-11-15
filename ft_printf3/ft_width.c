#include "ft_printf.h"

int	ft_intlen(int n)
{
	int	len;

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


int    ft_check_wp(t_data *p)
{
    int tmp = 0;

    if(*p->format == '*')
    {
        tmp = va_arg(p->list, int);
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
    return(tmp);
}

void	ft_write_width(t_data *p)
{
    p->size += p->width;
    while(p->width > 0)
    {
        if (p->minZ == 1 && p->precision == -1)
            ft_putchar_fd('0', 1);
            else
            ft_putchar_fd(' ', 1);
        p->width--;
    }
}
/*
void	ft_write_width(t_data *p, int len)
{
    int result;

    if(len < p->width)
    {
        result = p->width - len;
        p->size += result;
        while(result > 0)
        {
            if (p->minZ == 1)
                ft_putchar_fd('0', 1);
             else
                ft_putchar_fd(' ', 1);
            result--;
        }
    }
}
*/
/*void        ft_check_precision(t_data *p)
{
   // printf("1");
   //int result = 0;
    if (*p->format == '.')
        p->format++;
    if (*p->format == '*')
    {
        p->format++;
		p->precision = va_arg(p->list, int);
    }
    if (ft_isdigit(*p->format) == 1)
    {
        p->precision = *p->format++ - 48;
			while (ft_isdigit(*p->format))
            {
				p->precision = p->precision * 10 + *p->format++ - 48;
	    	}
    // if (ft_isdigit(*p->format))
    // {

    // }

	}
	else
		p->precision = -1;

   // printf("precison : %d", p->precision);
}/*/