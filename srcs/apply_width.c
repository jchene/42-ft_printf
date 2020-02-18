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

#include "../headers/lib.h"
#include "../headers/ext_libs.h"
#include "../headers/printf.h"

int		apply_width(int width, t_format *formats)
{
	int		i;
	int		fill_len;
	char	*buff;

	formats->old_len = ft_strlen(formats->conv);
	if (ft_strlen(formats->conv) > width)
		return (0);
	if (!(buff = (char *)malloc(sizeof(char) * width + 1)))
		return (-1);
	fill_len = width - ft_strlen(formats->conv);
	i = 0;
	while (i < fill_len)
		buff[i++] = ' ';
	ft_strcpy(&buff[i], formats->conv);
	buff[width] = '\0';
	free(formats->conv);
	formats->conv = buff;
	return (0);
}