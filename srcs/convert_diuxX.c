/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_diuxX.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 11:19:21 by jchene            #+#    #+#             */
/*   Updated: 2020/02/13 18:31:58 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/lib.h"
#include "../headers/ext_libs.h"
#include "../headers/printf.h"

int		convert_int(int nb, t_format *formats)
{
	int		i;
	int		len;

	len = int_len(nb);
	if (!(formats->conv = (char *)malloc(sizeof(char) * len + 1)))
		return (-1);
	if (nb < 0)
	{
		nb *= -1;
		formats->conv[0] = '-';
	}
	i = 0;
	while (nb > 0)
	{
		formats->conv[(len - 1 - i)] = ((nb % 10) + '0');
		nb /= 10;
		i++;
	}
	formats->conv[len] = '\0';
	return (0);
}

int		convert_uint(unsigned int nb, t_format *formats)
{
	int		i;
	int		len;

	len = uint_len(nb);
	if (!(formats->conv = (char *)malloc(sizeof(char) * len + 1)))
		return (-1);
	i = 0;
	while (nb > 0)
	{
		formats->conv[(len - 1 - i)] = ((nb % 10) + '0');
		nb /= 10;
		i++;
	}
	formats->conv[len] = '\0';
	return (0);
}

int		convert_hexa(unsigned int nb, t_format *formats, char *base)
{
	int		i;
	int		len;
	char	buff[9];

	buff[8] = '\0';
	i = 7;
	while (nb != 0 && i >= 0)
	{
		buff[i] = base[nb % 16];
		nb /= 16;
		i--;
	}
	len = ft_strlen(&buff[i + 1]);
	if (!(formats->conv = (char *)malloc(sizeof(char) * len + 1)))
		return (-1);
	ft_strcpy(formats->conv, &buff[i + 1]);
	formats->conv[len] = '\0';
	return (0);
}
