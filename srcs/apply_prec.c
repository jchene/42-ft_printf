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

#include "../headers/lib.h"
#include "../headers/ext_libs.h"
#include "../headers/printf.h"

int		apply_prec_str(int precision, t_format *formats)
{
	int		i;
	char	*buff;

	//printf("applying prec on str\n");
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
	return (0);
}

int		apply_prec_nbr(int precision, t_format *formats)
{
	int		i;
	int		j;
	int		len;
	int		minus;
	char	*buff;

	//printf("applying prec on nbr, prec: %d\n", precision);
	i = 0;
	j = 0;
	minus = 0;
	len = ft_strlen(formats->conv);
	if (formats->conv[0] == '-')
		minus++;
	len += minus;
	if (len >= precision)
		return (0);
	if (!(buff = (char *)malloc(sizeof(char) * (precision + 1 + minus))))
		return (-1);
	if (minus)
	{
		buff[i++] = '-';
		j++;
	}
	while (i < (precision - len))
		buff[i++] = '0';
	while (i < precision)
		buff[i++] = formats->conv[j++];
	free(formats->conv);
	formats->conv = buff;
	return (0);
}