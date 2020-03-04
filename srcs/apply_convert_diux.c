/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_convert_diuxX.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 15:36:48 by jchene            #+#    #+#             */
/*   Updated: 2020/03/04 17:23:55 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

int		convert_int_min(t_format *formats)
{
	ft_strlcpy(formats->conv, "-2147483648", 11);
	formats->conv[11] = '\0';
	formats->type = 'i';
	formats->true_len = 11;
	return (0);
}

int		convert_int(int nb, t_format *formats)
{
	int		i;
	int		len;

	len = int_len(nb);
	if (!(formats->conv = (char *)malloc(sizeof(char) * len + 1)))
		return (-1);
	if (nb == INT_MIN)
		return (convert_int_min(formats));
	if (nb < 0)
	{
		nb *= -1;
		formats->conv[0] = '-';
	}
	i = 0;
	if (nb == 0)
		formats->conv[i++] = '0';
	while (nb > 0)
	{
		formats->conv[(len - 1 - i++)] = ((nb % 10) + '0');
		nb /= 10;
	}
	formats->conv[len] = '\0';
	formats->type = 'i';
	formats->true_len = ft_strlen(formats->conv);
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
	if (nb == 0)
		formats->conv[i++] = '0';
	while (nb > 0)
	{
		formats->conv[(len - 1 - i)] = ((nb % 10) + '0');
		nb /= 10;
		i++;
	}
	formats->conv[len] = '\0';
	formats->type = 'u';
	formats->true_len = ft_strlen(formats->conv);
	return (0);
}

int		convert_hexa(unsigned long nb, t_format *formats, char *base)
{
	int		i;
	int		len;
	char	buff[ul_len(nb) + 1];

	len = ul_len(nb);
	buff[len] = '\0';
	i = len - 1;
	if (nb == 0)
		return (null_number(formats, buff));
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
	formats->type = 'x';
	formats->true_len = ft_strlen(formats->conv);
	return (0);
}

int		convert_percent(t_format *formats)
{
	if (!(formats->conv = (char *)malloc(sizeof(char) * 2)))
		return (-1);
	formats->conv[0] = '%';
	formats->conv[1] = '\0';
	formats->type = '%';
	formats->true_len = ft_strlen(formats->conv);
	return (0);
}
