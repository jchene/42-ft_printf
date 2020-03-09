/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 11:57:50 by jchene            #+#    #+#             */
/*   Updated: 2020/03/09 17:10:22 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "lib.h"
# include "ext_libs.h"

typedef struct		s_format
{
	int				flags;
	int				old_len;
	int				width;
	int				width_param;
	int				precision;
	int				prec_in_param;
	int				precision_param;
	int				jump;
	int				true_len;
	int				ret_len;
	char			*conv;
	char			type;
}					t_format;

int					check_flags(char *str, va_list params, t_format *formats);
int					check_width(char *str, va_list params, t_format *formats);
int					check_precision(char *str, va_list params,
					t_format *formats);
int					check_type(char *str, va_list params, t_format *formats);
int					check_format(char *str, va_list params, t_format *formats);

int					handle_flags(char *str, t_format *formats);
int					handle_width(char *str, t_format *formats);
int					handle_precision(char *str, t_format *formats);
int					handle_type(char *str, va_list params, t_format *formats);

int					convert_char(char c, t_format *formats);
int					convert_string(char *str, t_format *formats);
int					null_address(t_format *formats);
int					convert_pointer(void *p, t_format *formats);
int					convert_int_min(t_format *formats);
int					convert_int(int nb, t_format *formats);
int					convert_uint(unsigned int nb, t_format *formats);
int					convert_hexa(unsigned long nb, t_format *formats,
					char *base);
int					null_number(t_format *formats, char *buff);
int					convert_percent(t_format *formats);

int					apply_prec_str(int precision, t_format *formats);
int					apply_prec_nbr(int precision, t_format *formats);
int					apply_width(int width, t_format *formats);
int					apply_flag_minus(t_format *formats);
int					apply_flag_zero(t_format *formats);

int					count_chars(const char *string);
int					line_l_realloc(char *str, int n, char **line,
					t_format *formats);
int					line_error(char *line);
int					ret_and_free(char *line, t_format *formats);
int					string_start(const char *string, int count, char **line,
					t_format *formats);
int					conv_start(const char *string, t_format *formats,
					va_list *params, char **line);
int					string_end(const char *string, char **line,
					t_format *formats);
int					main_loop(const char *string, char **line, va_list *params,
					t_format *formats);
int					sum_formats(t_format *formats);
int					ft_printf(const char *string, ...
					__attribute__((__format__ (__scanf__, 1, 2))));

#endif
