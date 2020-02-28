/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_convert_csp.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 12:30:53 by jchene            #+#    #+#             */
/*   Updated: 2020/02/14 17:20:12 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/printf.h"

int		convert_char(char c, t_format *formats)
{
	printf("converting char: |%c|\n", c);
	if (!(formats->conv = (char *)malloc(sizeof(char) * 2)))
		return (-1);
	formats->conv[0] = c;
	formats->conv[1] = '\0';
	formats->type = 'c';
	formats->true_len = 1;
	////if (c == '\0')
		////printf("invisible char\n");
	////printf("converted: |%c|\n", formats->conv[0]);
	return (0);
}

int		convert_string(char *str, t_format *formats)
{
	int		len;
	
	if (str == NULL)
	{
		printf("str NULL\n");
		if (!(formats->conv = (char *)ft_calloc(7, sizeof(char))))
			return (-1);
		ft_strlcpy(formats->conv, "(null)", 7);
		formats->type = 's';
		formats->true_len = 6;
		return (0);
	}
	len = ft_strlen(str);
	if (!(formats->conv = (char *)ft_calloc(len + 1, sizeof(char))))
		return (-1);
	ft_strcpy(formats->conv, str);
	formats->conv[len] = '\0';
	formats->type = 's';
	formats->true_len = ft_strlen(formats->conv);
	return (0);
}

int		convert_pointer(void *p, t_format *formats)
{
	unsigned long	address;
	char			*buff;

	printf("	converting_pointer\n");
	address = (unsigned long) p;
	printf("	address ul: %lu\n", address);
	if (address == 0)
	{
		if (formats->precision > 0)
		{
			if (!(formats->conv = (char *)ft_calloc(3, sizeof(char))))
				return (-1);
			ft_strlcpy(formats->conv, "0x", 3);
			formats->true_len = 2;
		}
		else
		{
			if (!(formats->conv = (char *)ft_calloc(4, sizeof(char))))
				return (-1);
			ft_strlcpy(formats->conv, "0x0", 4);
			formats->true_len = 3;
		}
		formats->type = 'p';
		return (0);
	}
	if ((convert_hexa(address, formats, "0123456789abcdef")) == -1)
		return (-1);
	if (!(buff = (char *)ft_calloc(15, sizeof(char))))
		return(-1);
	ft_strlcpy(buff, "0x", 3);
	ft_strncat(buff, formats->conv, ft_strlen(formats->conv), ft_strlen(buff));
	free(formats->conv);
	formats->conv = buff;
	formats->type = 'p';
	formats->true_len += 2;
	return (0);
}
