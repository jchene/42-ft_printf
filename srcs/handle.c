/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 15:50:34 by jchene            #+#    #+#             */
/*   Updated: 2020/03/04 17:11:57 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

int		handle_type(char *string, va_list params, t_format *formats)
{
	int		ret_val;
	char	*lohexa;
	char	*uphexa;

	lohexa = "0123456789abcdef";
	uphexa = "0123456789ABCDEF";
	if (*string == 'c')
		ret_val = convert_char(va_arg(params, int), formats);
	else if (*string == 's')
		ret_val = convert_string((char *)va_arg(params, const char *), formats);
	else if (*string == 'p')
		ret_val = convert_pointer(va_arg(params, void *), formats);
	else if (*string == 'd' || *string == 'i')
		ret_val = convert_int(va_arg(params, int), formats);
	else if (*string == 'u')
		ret_val = convert_uint(va_arg(params, unsigned int), formats);
	else if (*string == 'x')
		ret_val = convert_hexa(va_arg(params, unsigned int), formats, lohexa);
	else if (*string == 'X')
		ret_val = convert_hexa(va_arg(params, unsigned int), formats, uphexa);
	else
		ret_val = convert_percent(formats);
	if (ret_val == -1)
		return (-1);
	return (0);
}

int		find_precision(t_format *formats, char *string, int *precision)
{
	int		i;

	i = 0;
	if (formats->prec_in_param == 1)
	{
		if (formats->precision_param < 0)
			return (0);
		*precision = formats->precision_param;
	}
	else
	{
		while (string[i] == '0')
			i++;
		*precision = ft_atoi(&string[i]);
	}
	return (1);
}

int		handle_precision(char *string, t_format *formats)
{
	int		precision;
	int		ret_value;

	if (find_precision(formats, string, &precision) != 1)
		return (0);
	if (((formats->prec_in_param == 1) ? (formats->precision_param == 0) :
		(precision == 0)) && (is_charset(formats->type, "diuxX") != -1) &&
		((is_charset(formats->type, "diu") != -1) ?
		(ft_atoi(formats->conv) == 0) : (revert_hexa(formats->conv) == 0)))
	{
		formats->jump = 1;
		return (0);
	}
	if (formats->type == 'c' || formats->type == '%' || formats->type == 'p')
		return (0);
	else if (formats->type == 's')
		ret_value = apply_prec_str(precision, formats);
	else
		ret_value = apply_prec_nbr(precision, formats);
	return (ret_value);
}

int		handle_width(char *string, t_format *formats)
{
	int		i;
	int		width;

	i = 0;
	if (formats->width_param != 0)
	{
		width = formats->width_param;
		if (formats->width_param < 0)
			width *= -1;
	}
	else
	{
		while (string[i] == '0')
			i++;
		width = ft_atoi(&string[i]);
	}
	if ((apply_width(width, formats)) == -1)
		return (-1);
	return (0);
}

int		handle_flags(char *string, t_format *formats)
{
	int		ret_value;

	if ((formats->flags > 1 || string[0] == '-' || formats->width_param < 0) &&
		formats->true_len > 1)
		ret_value = apply_flag_minus(formats);
	else if (string[0] == '0')
		ret_value = apply_flag_zero(formats);
	else
		ret_value = 0;
	if (ret_value == -1)
		return (-1);
	return (0);
}
