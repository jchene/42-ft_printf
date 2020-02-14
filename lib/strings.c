/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 11:27:20 by jchene            #+#    #+#             */
/*   Updated: 2020/02/13 18:30:58 by jchene           ###   ########.fr       */
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
		i++;
	return (i);
}

void	ft_putstr(char *string)
{
	int i;

	i = 0;
	while (string[i])
	{
		write (1, &string[i], 1);
		i++;
	}
}

void  ft_strncat(char *dst, char *src, int n)
{
	int		i;
	int		j;

	i = ft_strlen(dst);
	j = 0;
	while (src[j] && j < n)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
}

void	ft_strcpy(char *dst, char *src)
{
	int		i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
}