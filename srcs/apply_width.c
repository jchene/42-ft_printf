/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_width.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 17:19:10 by jchene            #+#    #+#             */
/*   Updated: 2020/02/14 17:19:34 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/printf.h"

int		apply_width(int width, t_format *formats)
{
	int		i;
	int		fill_len;
	char	*buff;

	if (formats->type == 'c')
		printf("	applying width: %d\n	on string: |%c|\n", width , formats->conv[0]);
	else
	{
		printf("	applying width: %d\n	on string: |", width);
		putprint(formats->conv, formats->true_len);
		printf("|\n");
	}
	i = 0;
	if (is_charset(formats->type, "diuxX") && formats->jump == 1)
	{
		printf("	filling with width\n");
		if (!(buff = (char *)malloc((width) * sizeof(char))))
			return (-1);
		while (i < width)
			buff[i++] = ' ';
		printf("	buff processed: |%s|\n", buff);
		free(formats->conv);
		formats->conv = buff;
		formats->true_len = width;
		printf("	conv: |");
		putprint(formats->conv, formats->true_len);
		printf("|\n");
		return (0);
	}
	formats->old_len = formats->true_len;
	if (formats->true_len > width)
		return (0);
	if (!(buff = (char *)ft_calloc(width + 1, sizeof(char))))
		return (-1);
	fill_len = width - formats->true_len;
	while (i < fill_len)
		buff[i++] = ' ';
	ft_strlcpy(&buff[i], formats->conv, formats->true_len);
	buff[width] = '\0';
	////printf("width buff: _%s_\ni: %d\n", buff, i);
	free(formats->conv);
	formats->conv = buff;
	formats->true_len += fill_len;
	if (formats->type == 'c')
		printf("	width handled, conv c: |%s%c|\n", formats->conv, formats->conv[formats->true_len]);
	else
		printf("	width handled, conv s: |%s|\n", formats->conv);
	return (0);
}