/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_format.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 14:32:26 by jchene            #+#    #+#             */
/*   Updated: 2020/03/04 17:07:43 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

int		check_flags(char *string, va_list params, t_format *formats)
{
	int		i;
	int		inchar;

	i = 0;
	formats->flags = 0;
	while ((inchar = is_charset(string[i], "-0")) != -1)
	{
		formats->flags++;
		i++;
	}
	if ((check_width(&string[i], params, formats)) == -1)
		return (-1);
	if (formats->flags > 0 || formats->width_param < 0)
		if ((handle_flags(&string[(i - formats->flags)], formats)) == -1)
			return (-1);
	return (0);
}

int		check_width(char *string, va_list params, t_format *formats)
{
	int		i;

	i = 0;
	formats->width = 0;
	formats->width_param = 0;
	if (string[i] == '*')
	{
		formats->width++;
		formats->width_param = va_arg(params, int);
		i++;
	}
	else
	{
		while ((is_charset(string[i], "0123456789")) != -1)
		{
			formats->width++;
			i++;
		}
	}
	if ((check_precision(&string[i], params, formats)) == -1)
		return (-1);
	if (formats->width > 0)
		if ((handle_width(&string[(i - formats->width)], formats)) == -1)
			return (-1);
	return (0);
}

int		check_precision(char *string, va_list params, t_format *formats)
{
	int		i;

	formats->precision = ((string[0] == '.') ? 1 : 0);
	formats->prec_in_param = ((formats->precision && string[1] == '*') ? 1 : 0);
	formats->precision_param = ((formats->prec_in_param) ? va_arg(params, int)
		: 0);
	formats->precision += ((formats->prec_in_param) ? 1 : 0);
	i = formats->precision;
	if (formats->precision != 0)
		if (formats->prec_in_param == 0)
			while ((is_charset(string[i], "0123456789")) != -1)
				i++;
	formats->precision = i;
	if ((check_type(&string[i], params, formats)) == -1)
		return (-1);
	if (formats->precision > 0)
		if ((handle_precision(&string[(i - (formats->precision) + 1)],
			formats)) == -1)
			return (-1);
	return (0);
}

int		check_type(char *string, va_list params, t_format *formats)
{
	if ((is_charset(string[0], "cspdiuxX%")) == -1)
		return (-1);
	if ((handle_type(&string[0], params, formats)) == -1)
		return (-1);
	return (0);
}

int		check_format(char *string, va_list params, t_format *formats)
{
	formats->conv = NULL;
	if ((check_flags(string, params, formats)) == -1)
	{
		if (formats->conv)
		{
			free(formats->conv);
			formats->conv = NULL;
		}
		free(formats);
		formats = NULL;
		return (-1);
	}
	return (0);
}
