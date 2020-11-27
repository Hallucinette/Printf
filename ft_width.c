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
        while (ft_isdigit(*p->format) == 1) // a rajouter doit etre  tmp < intmax
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