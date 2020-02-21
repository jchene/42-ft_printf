/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 11:57:50 by jchene            #+#    #+#             */
/*   Updated: 2020/02/18 17:53:52 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H
# include "lib.h"
# include "ext_libs.h"
# include "test.h"

typedef struct		s_format
{
	int				flags;
	int				old_len;
	int				width;
	int				width_param;
	int				precision;
	int				precision_param;
	int				true_len;
	int				ret_len;
	char			*conv;
	char			type;
}					t_format;

int					check_flags(char *str, va_list params, t_format *formats);
int					check_width(char *str, va_list params, t_format *formats);
int					check_precision(char *str, va_list params, t_format *formats);
int					check_type(char *str, va_list params, t_format *formats);
int					check_format(char *str, va_list params, t_format *formats);
int					handle_flags(char *str, t_format *formats);
int					handle_width(char *str, t_format *formats);
int					handle_precision(char *str, t_format *formats);
int					handle_type(char *str, va_list params, t_format *formats);
int					convert_char(char c, t_format *formats);
int					convert_string(char *str, t_format *formats);
int					convert_pointer(void *p, t_format *formats);
int					convert_int(int nb, t_format *formats);
int					convert_uint(unsigned int nb, t_format *formats);
int					convert_hexa(unsigned long nb, t_format *formats, char *base);
int					convert_percent(t_format *formats);
int					apply_prec_str(int precision, t_format *formats);
int					apply_prec_nbr(int precision, t_format *formats);
int					apply_width(int width, t_format *formats);
int					apply_flag_minus(t_format *formats);
int					apply_flag_zero(t_format *formats);
int					count_chars(const char *string);
int					line_l_realloc(char *str, int n, char **line, t_format *formats);
int					sum_formats(t_format *formats);
int					ft_printf(const char *string, ...);

#endif
