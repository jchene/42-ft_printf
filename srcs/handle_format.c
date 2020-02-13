/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_format.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 14:32:26 by jchene            #+#    #+#             */
/*   Updated: 2020/02/13 14:46:09 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		handle_flags(char *str, va_list params, char *conv, t_format formats)
{
	int		i;
	int		inchar;

	i = 0;
	if ((inchar = is_charset(*format, "-0")) == -1)
		return (-1);
	if (c == 'c')
		return (convert_char(va_arg(params, char)));
	if (c == 's')
		return (convert_string(va_arg(params, const char *)));
}

int		handle_width(char *str, char *conv)

int		handle_precision()

int		handle_type(char *string, va_list params, char *conv, t_format formats)
{
	int		i;
	int		inchar;
	char	charset[10];

	i = 0;
	charset = "cspdiuxX%";
	if ((inchar = is_charset(symbol[0], charset)) == -1)
		return (-1);
	if (c == 'c')
		return (convert_char(va_arg(params, char)));
	if (c == 's')
		return (convert_string(va_arg(params, const char *)));
	if (c == 'p')
		return (convert_pointer(va_arg(params, void *)));
	if (c == 'd' || c == 'i')
		return (convert_int(va_arg(params, int)));
	if (c == 'u')
		return (convert_uint(va_arg(params, unsigned int)));
	if (c == 'x')
		return (convert_lowhexa(va_arg(params, unsigned int)));
	if (c == 'X')
		return (convert_uphexa(va_arg(params, unsigned int)));
	if (c == '%')
		return ("%");
}

int		handle_format(char *format, va_list params, t_format formats)
{
	formats
}
