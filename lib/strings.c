/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 11:27:20 by jchene            #+#    #+#             */
/*   Updated: 2020/02/18 17:35:27 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/printf.h"

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

void  ft_strncat(char *dst, char *src, int n, int buff_len)
{
	int		i;
	int		j;

	i = buff_len;
	j = 0;
	while (j < n)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
}

void	ft_strlcpy(char *dst, char *src, int nb)
{
	int		i;

	i = 0;
	while (i < nb)
	{
		dst[i] = src[i];
		i++;
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

void	putprint(char *str, int nb)
{
	int		i;

	i = 0;
	while (i < nb)
		printf("%c", str[i++]);
}