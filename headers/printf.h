/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 11:57:50 by jchene            #+#    #+#             */
/*   Updated: 2020/02/13 18:29:51 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

typedef struct	s_format
{
	int			flags;
	int			width;
	int			precision;
	char		*conv;
}				t_format;

int				check_flags(char *str, va_list params, t_format *formats);
int				check_width(char *str, va_list params, t_format *formats);
int				check_precision(char *str, va_list params, t_format *formats);
int				check_type(char *str, va_list params, t_format *formats);
int				check_format(char *str, va_list params, t_format *formats);
int				handle_flags();
int				handle_width();
int				handle_precision();
int				handle_type(char *str, va_list params, t_format *formats);
int				convert_char(char c, t_format *formats);
int				convert_string(char *str, t_format *formats);
int				convert_pointer(unsigned int ptr, t_format *formats);
int				convert_int(int nb, t_format *formats);
int				convert_uint(unsigned int nb, t_format *formats);
int				convert_hexa(unsigned int nb, t_format *formats, char *base);
int				convert_percent(t_format *formats);
#endif
