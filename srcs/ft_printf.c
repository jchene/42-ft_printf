/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 17:56:23 by jchene            #+#    #+#             */
/*   Updated: 2020/02/18 17:44:22 by jchene           ###   ########.fr       */
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

	//printf("new realloc:\nstr: -%s-\nn: -%d-\n", str, n);
	if (!*line)
	{
		//printf("creating line\n");
		if (!(*line = (char *)malloc(sizeof(char) * (n + 1))))
			return (-1);
		ft_strlcpy(*line, str, n);
		(*line)[n] = '\0';
		//printf("new line: -%s-\n", *line);
		return (0);
	}
	len = n + ft_strlen(*line);
	//printf("realloc-ing -%d- len\n", len);
	if (!(buff = (char *)malloc(sizeof(char) * (len + 1))))
		return (-1);
	ft_strcpy(buff, *line);
	buff[ft_strlen(*line)] = '\0';
	//printf("buff: -%s-\n", buff);
	ft_strncat(buff, str, n);
	buff[len] = '\0';
	free(*line);
	*line = buff;
	//printf("new line: -%s-\n", *line);
	return (0);
}

int		ft_printf(const char *string, ...)
{
	int			i;
	int			len;
	int			count;
	char		*line;
	va_list		params;
	t_format	*formats;

	i = 0;
	count = 0;
	if (!(formats = (t_format *)malloc(sizeof(t_format))))
		return (-1);
	if (!(ft_strlen((char *)string)))
		return (0);
	va_start(params, string);
	while (string[i])
	{
		if ((count = count_chars(&string[i])) == -1)
		{
			//printf("\nno %% found\n");
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
			len = ft_strlen(line);
			free(line);
			line = NULL;
			return (len);
		}
		else if (count > 0)
		{
			//printf("\nfound %% after -%d- chars\n", count);
			//printf("-%s-\n", (char *)&string[i]);
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
			//printf("\nfound %%\n");
			i++;
			if (check_format((char *)&string[i], params, formats) == -1)
			{
				va_end(params);
				return (-1);
			}
			if ((line_l_realloc(formats->conv, ft_strlen(formats->conv), &line)) == -1)
			{
				if (line)
				{
					free(line);
					line = NULL;
				}
				return (-1);
			}
			//printf("conv: %s\n", formats->conv);
			free(formats->conv);
			formats->conv = NULL;
			//printf("end cnv \n");
			i += sum_formats(formats);
		}
	}
	if (line)
		ft_putstr(line);
	return (0);
}
