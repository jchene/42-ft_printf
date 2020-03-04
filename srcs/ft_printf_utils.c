/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 15:49:10 by jchene            #+#    #+#             */
/*   Updated: 2020/03/04 17:23:07 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

int		count_chars(const char *string)
{
	int i;

	i = 0;
	while (string[i] && string[i] != '%')
		i++;
	if (string[i])
		return (i);
	return (-1);
}

int		line_l_realloc(char *str, int n, char **line, t_format *formats)
{
	char			*buff;

	if (!*line)
	{
		if (!(*line = (char *)ft_calloc(n + 1, sizeof(char))))
			return (-1);
		ft_strlcpy(*line, str, n);
		(*line)[n] = '\0';
		formats->ret_len = n;
		return (0);
	}
	if (!(buff = (char *)ft_calloc((n + formats->ret_len + 1), sizeof(char))))
		return (-1);
	ft_strlcpy(buff, *line, formats->ret_len);
	buff[formats->ret_len] = '\0';
	ft_strncat(buff, str, n, formats->ret_len);
	buff[n + formats->ret_len] = '\0';
	free(*line);
	*line = buff;
	formats->ret_len += n;
	return (0);
}

int		line_error(char *line)
{
	if (line)
	{
		free(line);
		line = NULL;
	}
	return (-1);
}

int		ret_and_free(char *line, t_format *formats)
{
	int		ret_len;

	ret_len = formats->ret_len;
	free(formats);
	free(line);
	line = NULL;
	formats = NULL;
	return (ret_len);
}

int		null_number(t_format *formats, char *buff)
{
	buff[0] = '0';
	if (!(formats->conv = (char *)ft_calloc(2, sizeof(char))))
		return (-1);
	ft_strcpy(formats->conv, buff);
	formats->type = 'x';
	formats->true_len = 1;
	return (0);
}
