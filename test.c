/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 14:42:42 by jchene            #+#    #+#             */
/*   Updated: 2020/02/18 17:55:26 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "headers/printf.h"

int		ft_printf(const char *string, ...);

int		main(void)
{
	char		*string;
	const char	*test = "-->|%-4x|<--\n";
	int			nb = -21;
	int			*p;

	string = "abc";
	p = NULL;
	ft_printf(test, 0);
	printf(test, 0);
	return (0);
}