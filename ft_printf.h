#ifndef FT_PRINTF_H

# define FT_PRINTF_H

 #include <stdio.h>
 #include <unistd.h>
 #include <string.h>
 #include <stdarg.h>
 # include "./libft/libft.h"

//structure

typedef struct	s_data
{
	int	minZ;
	char 	type;
	char	*format;
	int		width;
	int		size;
	int		precision;
	char	res[9];
	int		reslen;
	unsigned int 	adr;
	va_list	list;
}				t_data;


void			ft_params0(t_data *p);

void			ft_write_c(t_data *p);
void			ft_write_s(t_data *p);
void			ft_write_d(t_data *p);
void			ft_write_Xx(t_data *p);


void     		ft_check_line(t_data *p);
void			ft_check_t(t_data *p);
void			ft_check_flags(t_data *p);

void			ft_write_width_c(t_data *p, char *c);
void			ft_write_width(t_data *p);

int				ft_printf(const char *src, ...);
int				ft_intlen(int n);
int				ft_check_wp(t_data *p);
int				ft_num_neg(t_data *p, int num);

void			ft_print_pre(t_data *p, int num);
int				ft_putnbr_base(int nbr, char *base, t_data *p);

void			ft_put_xX(t_data *p, char *s, int len);


#endif