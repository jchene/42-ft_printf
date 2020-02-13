/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 11:27:20 by jchene            #+#    #+#             */
/*   Updated: 2020/02/13 12:25:27 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/lib.h"
#include "../headers/ext_libs.h"

int		is_charset(char c, char *charset)
{
	int i;

	i = 0;
	while(charset[i])
	{
		if (c == charset[i])
			return (i);
		i++;
	}
	return (-1);
}

int		ft_strlen(char *string)
{
	int i;

	i = 0;
	while (string[i])
		i++
	return (i);
}

void	ft_putstr(const char *string)
{
	int i;

	i = 0;
	while (string[i])
	{
		write (1, &string[i], 1);
		i++;
	}
}
