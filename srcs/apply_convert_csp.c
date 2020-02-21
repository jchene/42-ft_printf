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
	//printf("converting char: |%c|\n", c);
	if (!(formats->conv = (char *)malloc(sizeof(char) * 2)))
		return (-1);
	formats->conv[0] = c;
	formats->conv[1] = '\0';
	formats->type = 'c';
	formats->true_len = 1;
	//if (c == '\0')
		//printf("invisible char\n");
	//printf("converted: |%c|\n", formats->conv[0]);
	return (0);
}

int		convert_string(char *str, t_format *formats)
{
	int		len;
	
	len = ft_strlen(str);
	if (!(formats->conv = (char *)malloc(sizeof(char) * len + 1)))
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

	address = (unsigned long) p;
	if ((convert_hexa(address, formats, "0123456789abcdef")) == -1)
		return (-1);
	if (!(buff = (char *)malloc(sizeof(char) * 15)))
		return(-1);
	ft_strcpy(buff, "0x");
	ft_strncat(buff, formats->conv, ft_strlen(formats->conv), ft_strlen(buff));
	buff[14] = '\0';
	free(formats->conv);
	formats->conv = buff;
	formats->type = 'p';
	formats->true_len += ft_strlen(formats->conv);
	return (0);
}
