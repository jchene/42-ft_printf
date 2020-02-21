/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_prec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 17:19:10 by jchene            #+#    #+#             */
/*   Updated: 2020/02/14 17:19:34 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/printf.h"

int		apply_prec_str(int precision, t_format *formats)
{
	int		i;
	char	*buff;

	printf("	applying prec on str: %s", formats->conv);
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
	formats->true_len = ((formats->true_len <= precision) ? formats->true_len : precision);
	return (0);
}

int		apply_prec_nbr(int precision, t_format *formats)
{
	int		i;
	int		j;
	int		len;
	int		minus;
	char	*buff;

	//printf("applying prec on nbr: %s\n precision: %d\n", formats->conv, precision);
	i = 0;
	j = 0;
	minus = 0;
	len = formats->true_len;
	////printf("formats->conv: |%s|\n", formats->conv);
	////printf("strlen: |%d|\n", ft_strlen(formats->conv));
	////printf("len: %d\n", len);
	if (formats->conv[0] == '-')
	{
		minus++;
		len--;
	}
	////printf("new len: %d\n", len);
	////printf("minus: %d\n", minus);
	if (len >= precision)
		return (0);
	if (!(buff = (char *)malloc(sizeof(char) * (precision + 1 + minus))))
		return (-1);
	////printf("malloc-ed with %d chars\n", (precision + 1 + minus));
	////printf("converting |%s|\n", formats->conv);
	if (minus)
	{
		buff[i++] = '-';
		j++;
	}
	////printf("buff: |%s|\ni: %d\n", buff, i);
	////printf("i - minus: %d\nprecision - len: %d\n", (i - minus), (precision - len));
	////printf("precision: %d\nlen: %d\n", precision, len);
	while ((i - minus) < (precision - len))
	{
		buff[i++] = '0';
		////printf("new buff: |%s|\ni: %d\n", buff, i);
	}
	////printf("buff: |%s|\ni: %d\n", buff, i);
	while (i < precision + minus)
		buff[i++] = formats->conv[j++];
	////printf("prec buff: _%s_\ni: %d\n", buff, i);
	free(formats->conv);
	formats->conv = buff;
	formats->true_len = precision + minus;
	return (0);
}