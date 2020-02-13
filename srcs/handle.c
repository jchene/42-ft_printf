/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 15:50:34 by jchene            #+#    #+#             */
/*   Updated: 2020/02/13 17:20:48 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/lib.h"
#include "../headers/ext_libs.h"
#include "../headers/printf.h"

int		handle_type(char *string, va_list params, t_format *formats)
{
	int		i;
	int		inchar;
	int		ret_value;

	i = 0;
	if (*string == 'c')
		ret_value = convert_char(va_arg(params, char), formats);
	else if (*string == 's')
		ret_value = convert_string(va_arg(params, const char *), formats);
	else if (*string == 'p')
		ret_value = convert_pointer(va_arg(params, unsigned int), formats);
	else if (*string == 'd' || c == 'i')
		ret_value = convert_int(va_arg(params, int), formats);
	else if (*string == 'u')
		ret_value = convert_uint(va_arg(params, unsigned int), formats);
	else if (*string == 'x')
		ret_value = convert_lowhexa(va_arg(params, unsigned int), formats);
	else if (*string == 'X')
		ret_value = convert_uphexa(va_arg(params, unsigned int), formats);
	else
		ret_value = convert_percent(formats);
	if (ret_value == -1)
		return (-1);
	return (0);
}

