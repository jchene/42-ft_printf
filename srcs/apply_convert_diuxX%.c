/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_convert_diuxX.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 11:19:21 by jchene            #+#    #+#             */
/*   Updated: 2020/02/18 17:46:25 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/printf.h"

int		convert_int(int nb, t_format *formats)
{
	int		i;
	int		len;

	printf("	type = d/i\n");
	len = int_len(nb);
	printf("	converting %d\n	with len: %d\n", nb, len);
	if (!(formats->conv = (char *)ft_calloc(len + 1, sizeof(char))))
		return (-1);
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
		formats->conv[(len - 1 - i)] = ((nb % 10) + '0');
		nb /= 10;
		i++;
	}
	formats->conv[len] = '\0';
	formats->type = 'i';
	formats->true_len = ft_strlen(formats->conv);
	printf("	converted: !%s!\n", formats->conv);
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
	formats->type = 'u';
	formats->true_len = ft_strlen(formats->conv);
	return (0);
}

int		convert_hexa(unsigned long nb, t_format *formats, char *base)
{
	int		i;
	int		len;
	char	buff[ul_len(nb) + 1];

	printf("	converting %lu\n", nb);
	len = ul_len(nb);
	buff[len] = '\0';
	i = len - 1;
	if (nb == 0)
	{
		buff[0] = '0';
		if (!(formats->conv = (char *)ft_calloc(2, sizeof(char))))
			return (-1);
		ft_strcpy(formats->conv, buff);
		formats->type = 'x';
		formats->true_len = 1;
		return (0);
	}
	while (nb > 0 && i >= 0)
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
	printf("	converted to |%s|\n", formats->conv);
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
