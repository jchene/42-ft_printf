/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_format.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 14:32:26 by jchene            #+#    #+#             */
/*   Updated: 2020/02/18 17:45:59 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	//printf("flags found: %d\n", formats->flags);
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
	////printf("checking width on: %s\n", string);
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
	//printf("width found: %d\n", formats->width);
	////printf("handling width on: %s\n", &string[i]);
	if ((check_precision(&string[i], params, formats)) == -1)
		return (-1);
	////printf("handling width2 on: %s\n", &string[i]);
	if (formats->width > 0)
		if ((handle_width(&string[(i - formats->width)], formats)) == -1)
			return (-1);
	return (0);
}

int		check_precision(char *string, va_list params, t_format *formats)
{
	int		i;

	i = 0;
	formats->precision = 0;
	formats->precision_param = -1;
	////printf("checking precision on: %s\n", string);
	if (string[i] == '.')
	{
		i++;
		formats->precision++;
		if (string[i] == '*')
		{
			formats->precision++;
			formats->precision_param = va_arg(params, int);
			i++;
		}
		else
		{
			while ((is_charset(string[i], "0123456789")) != -1)
			{
				formats->precision++;
				i++;
			}
		}
	}
	//printf("precision found: %d\n", formats->precision);
	if ((check_type(&string[i], params, formats)) == -1)
		return(-1);
	if (formats->precision > 0)
		if ((handle_precision(&string[(i - (formats->precision))], formats)) == -1)
			return (-1);
	return (0);
}

int		check_type(char *string, va_list params, t_format *formats)
{
	////printf("checking type on: %s\n", string);
	if ((is_charset(string[0], "cspdiuxX%")) == -1)
		return (-1);
	if ((handle_type(&string[0], params, formats)) == -1)
		return(-1);
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
