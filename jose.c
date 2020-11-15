#include "ft_printf.h"

void initializeStruct(t_oprint *op)
{
    op->wid = 0;
    op->dot = 0;
    op->numwid = 0;
    op->numpred = 0;
    op->minZero = -1;
    op->va = '\0';
    op->size = 0;
}

char *x_up (char *s)
{
    int i;

    i = 0;
    while (s[i] != '\0')
    {
        s[i] = ft_toupper(s[i]);
        i++;
    }
    return (s);
}

void print_c (t_oprint *op, char t)
{
    if (t == 37)
        write(1, &t, 1);
    else
        ft_putchar_fd(va_arg(op->lis, int), 1);
}

void print_s (t_oprint *op)
{
    ft_putstr_fd(va_arg(op->lis, char *), 1);
}

/*void print_p (t_oprint *op)
{
    char dir[1];

    dir[0] = va_arg(op->lis, char);
    ft_putstr_fd(dir, 1);
    //printf("RealP: %p\n", va_arg(op->lis, char *));
}*/

void print_nb (t_oprint *op, char t)
{
    int nbr;
    
    nbr = va_arg(op->lis, int);
    if (t == 'u' && nbr < 0)
        write(1, "4294967295", 10);
    else
        ft_putnbr_fd(nbr, 1);
}

void print_xX (t_oprint *op, char t)
{
    int nbr;
    char hex[8] = "ffffffff";
    
    nbr = va_arg(op->lis, int);
    if (nbr < 0)
        if(t == 'x')
            write(1, hex, 8);
        else
            write(1, x_up(hex), 8);
    else
        ft_putnbr_fd(nbr, 1);
}

/*
*   Función para evoluar las flags
*/
int    findFlag(t_oprint *op, const char *src, int pos)
{
    if(src[pos] == '0')
        op->minZero = 0;
    else
        op->minZero = 1;
    return(pos++);
}

/*
*   Función para calcular el width
*/

int    getWidth(t_oprint *op, const char *src, int pos)
{
    int num;

    num = 0;
    if (src[pos] == '*')
    {
        num = va_arg(op->lis, int);
    }
    else 
    {
        while (isdigit(src[pos]) == 1)
        {
            num *= 10;
            num += src[pos] -48;
            pos++;
        }
    }
    op->wid = num;
    //ft_putnbr_fd(num, 1);
    return (pos);
}

/*
*   Función para calcular la precisión
*/

int    getPrecision(t_oprint *op, const char *src, int pos)
{
    return (pos);
}

/*
*   Función para evaluar el tipo
*/

void    findType(t_oprint *op, const char *src, int pos)
{
    if(src[pos] == 'c' || src[pos] == '%')
        print_c(op, src[pos]);
    if(src[pos] == 's')
        print_s(op);
    /*if(src[pos] == 'p')
        print_p(op);*/
    if(src[pos] == 'd' || src[pos] == 'i' || src[pos] == 'u')
        print_nb(op, src[pos]);
    if(src[pos] == 'x' || src[pos] == 'X')
        print_xX(op, src[pos]);
}

/*
* Función para comprobar qué hay tras el porcentaje
*/

int nombreProvisional(t_oprint *op, const char *src, int pos)
{
    int size;
    
    size = 0;
    if (src[pos] == '0' || src[pos] == '-')
        pos = findFlag(op, src, pos);
    if (ft_isdigit(src[pos]) == 1 || src[pos] == '*')
        pos = getWidth(op, src, pos);
    if (src[pos] == '.')
        pos = getPrecision(op, src, pos);
    findType(op, src, pos);
    return(size+1);
}

int ft_printf(const char *src, ...)
{
    int         i;
    int         sp;
    int         size;
    t_oprint    op;

    //ft_putstr_fd((char *) src, 1);
    if (!src)
        return (0);
    i = 0;
    size = 0;
    va_start(op.lis, src);
    initializeStruct(&op);
    while (src[i] != '\0')
    {
        if(src[i] == '%')
        {
            sp = nombreProvisional(&op, src, i+1);
            if(sp == 0)
                ft_putchar_fd(src[i], 1);
            else
                size += op.size;
            i += sp;
        }
        else
            ft_putchar_fd(src[i], 1);
        size++;
        i++;
    }
    va_end(op.lis);
    return(size);
}