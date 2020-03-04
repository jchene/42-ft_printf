/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lenghts.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 18:26:32 by jchene            #+#    #+#             */
/*   Updated: 2020/03/04 17:13:30 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

int		int_len(int nb)
{
	int nb_len;
	int	minus;

	minus = 0;
	if (nb == INT_MIN)
		return (11);
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
