/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 11:19:21 by jchene            #+#    #+#             */
/*   Updated: 2020/02/13 12:30:13 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/lib.h"
#include "../headers/ext_libs.h"

char	*convert_int(int nb)
{
	int		i;
	int		len;
	char	*string;

	len = nb_len(nb);
	string = (char *)malloc(sizeof(char) * len + 1);
	if (nb < 0)
	{
		nb *= -1;
		string[0] = '-';
	}
	i = 0;
	while (nb > 0)
	{
		string[(len - 1 - i)] = ((nb % 10) + '0');
		nb /= 10;
		i++;
	}
	string[len] = '\0';
	return (string);
}


