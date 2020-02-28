/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_disp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 11:25:26 by jchene            #+#    #+#             */
/*   Updated: 2020/02/18 17:54:30 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/printf.h"

void	ft_putstr(char *string, int nb)
{
	int i;

	i = 0;
	while (i < nb)
	{
		write (1, &string[i], 1);
		i++;
	}
}

void	*ft_memset(void *s, int c, int n)
{
	unsigned char	chr;
	int				i;
	char			*str;

	str = s;
	i = 0;
	chr = (unsigned char)c;
	while (i < n)
	{
		str[i] = chr;
		i++;
	}
	return (s);
}

void	*ft_calloc(int count, int size)
{
	void	*ptr;

	if (!(ptr = malloc(size * count)))
		return (NULL);
	return (ft_memset(ptr, 0, count * size));
}