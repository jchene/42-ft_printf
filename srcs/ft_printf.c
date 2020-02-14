/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 17:56:23 by jchene            #+#    #+#             */
/*   Updated: 2020/02/14 17:20:28 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/lib.h"
#include "../headers/ext_libs.h"
#include "../headers/printf.h"

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

int		line_l_realloc(char *str, int n, char **line)
{
	char	*buff;
	int		len;

	if (!*line)
	{
		if (!(*line = (char *)malloc(sizeof(char) * (n + 1))))
			return (-1);
		ft_strcpy(*line, str);
		return (0);
	}
	len = n + ft_strlen(*line);
	if (!(buff = (char *)malloc(sizeof(char) * (len + 1))))
		return (-1);
	ft_strcpy(buff, *line);
	ft_strncat(buff, str, n);
	free(*line);
	*line = buff;
	return (0);
}

int		ft_printf(const char *string, ...)
{
	int			i;
	int			count;
	char		*line;
	va_list		params;
	t_format	formats;

	i = 0;
	count = 0;
	if (!(ft_strlen((char *)string)))
		return (0);
	va_start(params, string);
	while (string[i])
	{
		if ((count = count_chars(&string[i])) == -1)
		{
			if ((line_l_realloc((char *)&string[i], ft_strlen((char *)&string[i]), &line)) == -1)
			{
				if (line)
				{
					free(line);
					line = NULL;
				}
				return (-1);
			}
			ft_putstr(line);
			free(line);
			line = NULL;
			return (ft_strlen(line));
		}
		else if (count > 0)
		{
			if ((line_l_realloc((char *)&string[i], count, &line)) == -1)
			{
				if (line)
				{
					free(line);
					line = NULL;
				}
				return (-1);
			}
			i += count;
		}
		else
		{
			i++;
			if (check_format((char *)&string[i], params, &formats) == -1)
			{
				va_end(params);
				return (-1);
			}
			if ((line_l_realloc(formats.conv, ft_strlen(formats.conv), &line)) == -1)
			{
				if (line)
				{
					free(line);
					line = NULL;
				}
				return (-1);
			}
			free(formats.conv);
			formats.conv = NULL;
		}
	}
}
