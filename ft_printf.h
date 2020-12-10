/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amepocch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 23:10:53 by amepocch          #+#    #+#             */
/*   Updated: 2020/12/10 01:51:35 by amepocch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdarg.h>
# include "./libft/libft.h"

typedef struct	s_data
{
	int		minz;
	int		dot;
	char	type;
	char	*format;
	int		width;
	int		size;
	int		precision;
	char	resp[16];
	va_list	list;
}				t_data;

void			ft_params0(t_data *p);

void			ft_write_c(t_data *p);
void			ft_write_s(t_data *p);
void			ft_write_s2(t_data *p, int len, int i, char *string);
void			ft_write_d(t_data *p);
void			ft_write_d2(t_data *p, int num);
void			ft_write_x(t_data *p);
void			ft_write_x2(t_data *p, int len, unsigned int nbr);
void			ft_write_x3(t_data *p, int len, unsigned int nbr);

void			ft_write_p(t_data *p);
void			ft_write_p2(t_data *p, int len, long addr);
void			ft_write_p3(t_data *p, int len, long addr);
void			ft_write_p4(t_data *p, int len, long addr);
void			ft_write_u(t_data *p);
void			ft_write_u2(t_data *p, long num);

void			ft_check_line(t_data *p);
void			ft_check_t(t_data *p);
void			ft_check_flags(t_data *p);

void			ft_write_width(t_data *p);

int				ft_printf(const char *src, ...);
int				ft_intlen(long int n);
int				ft_check_wp(t_data *p);
int				ft_num_neg(t_data *p, int num);

void			ft_print_pre(t_data *p, long int num);
int				putnbr_base(unsigned long nbr, char *base, t_data *p);
void			ft_put_x(t_data *p, int len);

#endif
