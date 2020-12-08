/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amepocch <amepocch@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 01:01:29 by amepocch          #+#    #+#             */
/*   Updated: 2020/12/07 01:01:31 by amepocch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    ft_params0(t_data *p)
{
    p->precision = -1;
    p->dot = 0;
    p->width = 0;
    p->size = 0;
    p->type = '\0';
    p->minZ = 0;
}
void	ft_check_flags(t_data *p)
{
    while (*p->format == '0' || *p->format == '-')
    {
        if(*p->format == '0' && p->minZ != 2)
            p->minZ = 1;
        else
            p->minZ = 2;
        p->format++;
    }
}

void	ft_check_t(t_data *p)
{
    if (*p->format == 'd' || *p->format == 'i' )
        ft_write_d(p);
    else if (*p->format == 'u')
        ft_write_u(p);
    else if (*p->format == 'X' || *p->format == 'x')
        ft_write_Xx(p);
    else if (*p->format == 'c' || *p->format == '%')
        ft_write_c(p);
    else if (*p->format == 's')
        ft_write_s(p);
    else if (*p->format == 'p')
        ft_write_p(p);
    if (*p->format)
        p->format++;
}

void     ft_check_line(t_data *p)
{
    ft_params0(p);
    p->format++;
    ft_check_flags(p);
    p->width = ft_check_wp(p);
    if (*p->format == '.')
    {
        p->dot = 1;
        p->format++;
        p->precision = ft_check_wp(p);
    }
    ft_check_t(p);
}

int     ft_printf(const char *format, ...)
{
    t_data	p;
    int size;

    size = 0;
    ft_params0(&p);
    va_start(p.list, format);
    p.format = (char *)format;
    while (*p.format)
    {
        if(*p.format == '%' && *(p.format + 1))
        {
            ft_check_line(&p);
            size += p.size;
        }
        else
        {
            ft_putchar_fd(*p.format, 1);
            size++;
            p.format++;
        }
    }
    va_end(p.list);
    return (size);
}
