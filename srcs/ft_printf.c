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

int		line_l_realloc(char *str, int n, char **line, t_format *formats)
{
	char			*buff;

	printf("new realloc:\n	str: |%s|	n: %d\n	line_len: %d\n", str, n, formats->ret_len);
	if (!*line)
	{
		printf("	creating line of %d chars\n", n + 1);
		if (!(*line = (char *)ft_calloc(n + 1 , sizeof(char))))
			return (-1);
		ft_strlcpy(*line, str, n);
		(*line)[n] = '\0';
		formats->ret_len = n;
		printf("	line_len: %d\n", formats->ret_len);
		printf("	new line: %s\n", *line);
		return (0);
	}
	printf("	realloc-ing %d len\n", n + formats->ret_len);
	if (!(buff = (char *)ft_calloc((n + formats->ret_len + 1), sizeof(char))))
		return (-1);
	ft_strlcpy(buff, *line, formats->ret_len);
	buff[formats->ret_len] = '\0';
	ft_strncat(buff, str, n, formats->ret_len);
	buff[n + formats->ret_len] = '\0';
	free(*line);
	*line = buff;
	formats->ret_len += n;
	printf("	line_len: %d\n", formats->ret_len);
	putprint("new line: |", 11);
	putprint(*line, formats->ret_len);
	putprint("|\n", 2);
	return (0);
}

int		ft_printf(const char *string, ...)
{
	int			i;
	int			count;
	int			ret_len;
	char		*line;
	va_list		params;
	t_format	*formats;

	
	if (!(ft_strlen((char *)string)))
		return (0);
	if (!(formats = (t_format *)ft_calloc(1, sizeof(t_format))))
		return (-1);
	i = 0;
	count = 0;
	line = NULL;
	formats->true_len = 0;
	formats->ret_len = 0;
	formats->old_len = -1;
	va_start(params, string);
	while (string[i])
	{
		if ((count = count_chars(&string[i])) > 0)
		{
			printf("\nfound %% after %d chars in |%s|, i = %d\n", count, &string[i], i);
			////printf("%s\n", (char *)&string[i]);
			if ((line_l_realloc((char *)&string[i], count, &line, formats)) == -1)
			{
				if (line)
				{
					free(line);
					line = NULL;
				}
				return (-1);
			}
			i += count;
			formats->true_len += count;
			printf("jumped to %%\n");
		}
		else if (count == 0)
		{
			printf("\nfound %% in %s, i = %d\n", &string[i], i);
			i++;
			formats->jump = 0;
			if (check_format((char *)&string[i], params, formats) == -1)
			{
				va_end(params);
				return (-1);
			}
			if (formats->jump == 0 || formats->width > 0)
			{
				if ((line_l_realloc(formats->conv, formats->true_len, &line, formats)) == -1)
				{
					if (line)
					{
						free(line);
						line = NULL;
					}
					return (-1);
				}
				free(formats->conv);
				formats->conv = NULL;
			}
			printf("old i: %d\n", i);
			i += sum_formats(formats);
			printf("new i: %d\n", i);
			printf("sum formats: %d\n", sum_formats(formats));
		}
		else
		{
			printf("\nno %% found in |%s|, i = %d\n", &string[i], i);
			if ((line_l_realloc((char *)&string[i], ft_strlen((char *)&string[i]), &line, formats)) == -1)
			{
				if (line)
				{
					free(line);
					line = NULL;
				}
				return (-1);
			}
			formats->true_len += ft_strlen((char *)&string[i]);
			ft_putstr(line, formats->ret_len);
			ret_len = formats->ret_len;
			free(line);
			free(formats);
			line = NULL;
			formats = NULL;
			return (ret_len);
		}
	}
	return (0);
}
