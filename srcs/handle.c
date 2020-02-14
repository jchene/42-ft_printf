/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 15:50:34 by jchene            #+#    #+#             */
/*   Updated: 2020/02/14 17:20:42 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/lib.h"
#include "../headers/ext_libs.h"
#include "../headers/printf.h"

int		handle_type(char *string, va_list params, t_format *formats)
{
	int		ret_value;
	char	*lohexa;
	char	*uphexa;

	lohexa = "0123456789abcdef";
	uphexa = "0123456789ABCDEF";
	if (*string == 'c')
		ret_value = convert_char(va_arg(params, int), formats);
	else if (*string == 's')
		ret_value = convert_string((char *)va_arg(params, const char *), formats);
	else if (*string == 'p')
		ret_value = convert_pointer(va_arg(params, void *), formats);
	else if (*string == 'd' || *string == 'i')
		ret_value = convert_int(va_arg(params, int), formats);
	else if (*string == 'u')
		ret_value = convert_uint(va_arg(params, unsigned int), formats);
	else if (*string == 'x')
		ret_value = convert_hexa(va_arg(params, unsigned int), formats, lohexa);
	else if (*string == 'X')
		ret_value = convert_hexa(va_arg(params, unsigned int), formats, uphexa);
	else
		ret_value = convert_percent(formats);
	if (ret_value == -1)
		return (-1);
	return (0);
}

int		handle_precision(char *string, t_format *formats)
{
	int 	i;
	int		precision;
	int		ret_value;

	i = 0;
	if (formats->precision_param != -1)
		precision = formats->precision_param;
	else
	{
		while (string[i] == '0' || string[i] == '-' || string[i] == '+')
			i++;
		precision = ft_atoi(&string[i]);
	}
	if (formats->type == 'c' || formats->type == '%')
		return (0);
	else if (formats->type == 's')
		ret_value = apply_prec_str(precision, formats);
	else 
		ret_value = apply_prec_misc(precision, formats);
	if (ret_value == -1)
		return (-1);
	return (0);
}

int		handle_width(char *str, t_format *formats);

int		handle_flags(char *str, t_format *formats);
