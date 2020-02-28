/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 15:50:34 by jchene            #+#    #+#             */
/*   Updated: 2020/02/18 17:36:42 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/printf.h"

int		handle_type(char *string, va_list params, t_format *formats)
{
	int		ret_value;
	char	*lohexa;
	char	*uphexa;

	lohexa = "0123456789abcdef";
	uphexa = "0123456789ABCDEF";
	printf("handling type\n");
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
	printf("handling precision \n");
	printf("	actual string: %s", &string[i]);
	printf("	type: %c\n", formats->type);
	if (formats->prec_in_param == 1)
	{
		if (formats->precision_param < 0)
			return (0);
		precision = formats->precision_param;
	}
	else
	{
		while (string[i] == '0')
			i++;
		printf("	atoi-ing: %s", &string[i]);
		precision = ft_atoi(&string[i]);
	}
	printf("	jumping? string: |%s| atoi: %d\n",formats->conv, ft_atoi(formats->conv));
	if (((formats->prec_in_param == 1) ? (formats->precision_param == 0) : (precision == 0)) &&
		(is_charset(formats->type, "diuxX") != -1) && ((is_charset(formats->type, "diu") != -1) ?
		(ft_atoi(formats->conv) == 0) : (revert_hexa(formats->conv) == 0)))
	{
		printf("	jumping\n");
		formats->jump = 1;
		return (0);
	}
	printf("	precision: %d\n", precision);
	if (formats->type == 'c' || formats->type == '%' || formats->type == 'p')
		return (0);
	else if (formats->type == 's')
		ret_value = apply_prec_str(precision, formats);
	else 
		ret_value = apply_prec_nbr(precision, formats);
	printf("	precision handled, conv: |%s|\n", formats->conv);
	if (ret_value == -1)
		return (-1);
	return (0);
}

int		handle_width(char *string, t_format *formats)
{
	int		i;
	int		width;

	i = 0;
	printf("handling width on %s", string);
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
		printf("	atoi-ing %s", &string[i]);
		width = ft_atoi(&string[i]);
		printf("	width: %d\n", width);
	}
	if ((apply_width(width, formats)) == -1)
		return (-1);
	return (0);
}

int		handle_flags(char *string, t_format *formats)
{
	int		ret_value;

	////printf("handling flags\n");
	printf("handling flags on: %s	param: %d\n	conv: |", string, formats->width_param);
	putprint(formats->conv, formats->true_len);
	printf("|\n");
	if ((formats->flags > 1 || string[0] == '-' || formats->width_param < 0) && formats->true_len > 1)
		ret_value = apply_flag_minus(formats);
	else if (string[0] == '0')
		ret_value = apply_flag_zero(formats);
	else
		ret_value = 0;
	printf("	flags handled, conv: |%s%c|\n", formats->conv ,formats->conv[formats->true_len]);
	if (ret_value == -1)
		return (-1);
	return (0);
}
