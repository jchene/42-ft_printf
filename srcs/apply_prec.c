/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_prec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 17:19:10 by jchene            #+#    #+#             */
/*   Updated: 2020/03/04 17:07:20 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

int		apply_prec_str(int precision, t_format *formats)
{
	int		i;
	char	*buff;

	i = 0;
	if (!(buff = (char *)malloc(sizeof(char) * (precision + 1))))
		return (-1);
	while (i < precision)
	{
		buff[i] = formats->conv[i];
		i++;
	}
	buff[i] = '\0';
	free(formats->conv);
	formats->conv = buff;
	formats->true_len = ((formats->true_len <= precision) ?
		formats->true_len : precision);
	return (0);
}

int		apply_prec_nbr(int precision, t_format *formats)
{
	int		i;
	int		j;
	int		len;
	int		minus;
	char	*buff;

	minus = ((formats->conv[0] == '-') ? 1 : 0);
	i = (minus ? 1 : 0);
	j = (minus ? 1 : 0);
	len = formats->true_len - minus;
	if (precision == 0 && formats->conv[0] == '0')
		formats->conv[0] = ' ';
	if (len >= precision)
		return (0);
	if (!(buff = (char *)malloc(sizeof(char) * (precision + 1 + minus))))
		return (-1);
	buff[0] = (minus ? '-' : buff[0]);
	while ((i - minus) < (precision - len))
		buff[i++] = '0';
	while (i < precision + minus)
		buff[i++] = formats->conv[j++];
	free(formats->conv);
	formats->conv = buff;
	formats->true_len = precision + minus;
	return (0);
}
