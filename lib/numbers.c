/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 11:25:26 by jchene            #+#    #+#             */
/*   Updated: 2020/02/13 17:20:50 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/lib.h"
#include "../headers/ext_libs.h"

int		int_len(int nb)
{
	int nb_len;
	int	minus;

	minus = 0;
	if (nb < 0)
	{
		nb *= -1;
		minus++;
	}
	nb_len = 1;
	while (nb > 10)
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
