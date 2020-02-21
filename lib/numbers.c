/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 11:25:26 by jchene            #+#    #+#             */
/*   Updated: 2020/02/18 17:54:30 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/printf.h"

int		int_len(int nb)
{
	int nb_len;
	int	minus;

	//printf("testing len of %d\n", nb);
	minus = 0;
	if (nb < 0)
	{
		nb *= -1;
		minus++;
	}
	nb_len = 1;
	while (nb >= 10)
	{
		nb /= 10;
		nb_len++;
	}
	return (nb_len + minus);
}

int		uint_len(unsigned int nb)
{
	int nb_len;

	nb_len = 1;
	while (nb > 10)
	{
		nb /= 10;
		nb_len++;
	}
	return (nb_len);
}


int		ul_len(unsigned long nb)
{
	int nb_len;

	nb_len = 1;
	while (nb > 10)
	{
		nb /= 10;
		nb_len++;
	}
	return (nb_len);
}

int		ft_atoi(char *str)
{
	int		i;
	int		nbr;

	i = 0;
	nbr = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr = (nbr * 10) + (str[i] - '0');
		i++;
	}
	return (nbr);
}

int		sum_formats(t_format *formats)
{
	int		ret;

	ret = 0;
	ret += formats->flags;
	ret += formats->width;
	ret += formats->precision;
	if (formats->type)
	{
		if (formats->type == '%')
		{
			ret+=1;
			formats->type = '.';
		}
	}
	ret++;
	return (ret);
}