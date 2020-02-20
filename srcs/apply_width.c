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

	//if (formats->type == 'c')
		//printf("	applying width: %d\n	on string: |%c|\n", width , formats->conv[0]);
	//else
		//printf("	applying width: %d\n	on string: |%s|\n", width , formats->conv);
	if (formats->true_len > width)
		return (0);
	formats->old_len = formats->true_len;
	if (!(buff = (char *)ft_calloc(width + 1, sizeof(char))))
		return (-1);
	fill_len = width - formats->true_len;
	i = 0;
	while (i < fill_len)
		buff[i++] = ' ';
	ft_strlcpy(&buff[i], formats->conv, formats->true_len);
	buff[width] = '\0';
	////printf("width buff: _%s_\ni: %d\n", buff, i);
	free(formats->conv);
	formats->conv = buff;
	formats->true_len += fill_len;
	//if (formats->type == 'c')
		//printf("	width handled, conv c: |%s%c|\n", formats->conv, formats->conv[formats->true_len]);
	//else
		//printf("	width handled, conv s: |%s|\n", formats->conv);
	return (0);
}