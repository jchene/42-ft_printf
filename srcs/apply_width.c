/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_width.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 17:19:10 by jchene            #+#    #+#             */
/*   Updated: 2020/03/04 17:07:30 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

int		jumping_width(int width, t_format *formats)
{
	char	*buff;
	int		i;

	i = 0;
	if (!(buff = (char *)malloc((width) * sizeof(char))))
		return (-1);
	while (i < width)
		buff[i++] = ' ';
	free(formats->conv);
	formats->conv = buff;
	formats->true_len = width;
	return (0);
}

int		apply_width(int width, t_format *formats)
{
	int		i;
	int		fill_len;
	char	*buff;

	i = 0;
	if (is_charset(formats->type, "diuxX") && formats->jump == 1)
		return (jumping_width(width, formats));
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
	free(formats->conv);
	formats->conv = buff;
	formats->true_len += fill_len;
	return (0);
}
