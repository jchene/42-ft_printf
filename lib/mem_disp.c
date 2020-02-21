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

void	ft_puterror(char *str)
{
	int		i;

	i = 0;
	while(str[i] && str[i] != '.')
		write(1, &str[i++], 1);
	if (!(str[i]))
		return;
	write(1, ".", 1);
	i++;
	if (str[i] == '+' || str[i] == '-')
		write(1, "0", 1);
	else if (str[i] == '0')
		while (str[i] == '0')
			i++;
	ft_putstr(&str[i], ft_strlen(&str[i]));
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