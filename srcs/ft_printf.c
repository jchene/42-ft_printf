/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 17:56:23 by jchene            #+#    #+#             */
/*   Updated: 2020/03/05 18:33:36 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

int		string_start(const char *string, int count, char **line,
	t_format *formats)
{
	if ((line_l_realloc((char *)string, count, line,
		formats)) == -1)
		return (-1);
	formats->true_len += count;
	return (0);
}

int		conv_start(const char *string, t_format *formats,
	va_list *params, char **line)
{
	formats->jump = 0;
	if (check_format((char *)string, *params, formats) == -1)
	{
		va_end(*params);
		return (-1);
	}
	if (formats->jump == 0 || formats->width > 0)
	{
		if ((line_l_realloc(formats->conv, formats->true_len, line,
			formats)) == -1)
			return (-1);
		free(formats->conv);
		formats->conv = NULL;
	}
	return (0);
}

int		string_end(const char *string, char **line, t_format *formats)
{
	if ((line_l_realloc((char *)string,
		ft_strlen((char *)string), line, formats)) == -1)
		return (line_error(*line));
	formats->true_len += ft_strlen((char *)string);
	ft_putstr(*line, formats->ret_len);
	return (ret_and_free(*line, formats));
}

int		main_loop(const char *string, char **line, va_list *params,
	t_format *formats)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (string[i])
	{
		if ((count = count_chars(&string[i])) > 0)
		{
			if (string_start(&string[i], count, line, formats) == -1)
				return (-1);
			i += count;
		}
		else if (count == 0)
		{
			if (conv_start(&string[++i], formats, params, line) == -1)
				return (-1);
			i += sum_formats(formats);
			free(formats->conv);
			formats->conv = NULL;
		}
		else
			return (string_end(&string[i], line, formats));
	}
	return (0);
}

int		ft_printf(const char *string, ...)
{
	int			ret;
	char		*line;
	va_list		params;
	t_format	*formats;

	if (!(ft_strlen((char *)string)))
		return (0);
	if (!(formats = (t_format *)ft_calloc(1, sizeof(t_format))))
		return (-1);
	line = NULL;
	formats->true_len = 0;
	formats->ret_len = 0;
	formats->old_len = -1;
	va_start(params, string);
	if ((ret = main_loop(string, &line, &params, formats)) == -1)
		return (line_error(line));
	return (ret);
}
