/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_format.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 14:32:26 by jchene            #+#    #+#             */
/*   Updated: 2020/02/14 17:19:55 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/lib.h"
#include "../headers/ext_libs.h"
#include "../headers/printf.h"

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
	if (formats->flags > 0)
		if ((handle_flags()) == -1)
			return (-1);
	return (0);
}

int		check_width(char *string, va_list params, t_format *formats)
{
	int		i;

	i = 0;
	formats->width = 0;
	formats->width_param = -1;
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
		if ((handle_width()) == -1)
			return (-1);
	return (0);
}

int		check_precision(char *string, va_list params, t_format *formats)
{
	int		i;

	i = 0;
	formats->precision = 0;
	formats->precision_param = -1;
	if (string[i] == '.')
	{
		i++;
		if (string[i] == '*')
		{
			formats->precision++;
			formats->precision_param = va_arg(params, int);
			i++;
		}
		else
		{
			while ((is_charset(string[i], "0123456789+-")) != -1)
			{
				formats->precision++;
				i++;
			}
		}
	}
	if ((check_type(&string[i], params, formats)) == -1)
		return(-1);
	if (formats->precision > 0)
		if ((handle_precision(&string[(i - formats->precision) + 1], formats)) == -1)
			return (-1);
	return (0);
}

int		check_type(char *string, va_list params, t_format *formats)
{
	int		i;

	if ((is_charset(string[0], "cspdiuxX%")) == -1)
		return (-1);
	if ((handle_type(&string[0], params, formats)) == -1)
		return(-1);
	return (0);
}

int		check_format(char *string, va_list params, t_format *formats)
{
	if (!formats)
		if (!(formats = (t_format *)malloc(sizeof(t_format))))
			return (-1);
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
