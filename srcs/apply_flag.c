/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 17:19:10 by jchene            #+#    #+#             */
/*   Updated: 2020/02/18 14:39:35 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/printf.h"

int					apply_flag_minus(t_format *formats)
{
	int		i;
	int		start;
	char	*buff;

	i = 0;
	if (formats->old_len == -1)
		formats->old_len = formats->true_len;
	printf("	applying flag minus with true_len: %d\n", formats->true_len);
	if (!(buff = (char *)malloc(sizeof(char) * ft_strlen(formats->conv) + 1)))
		return (-1);
	printf("	len: %d\n", ft_strlen(formats->conv));
	start = formats->true_len - formats->old_len;
	printf("	start: %d\n", start);
	ft_strcpy(&buff[0], &formats->conv[start]);
	while (i < start)
		buff[formats->old_len + i++] = ' ';
	buff[formats->old_len + i] = '\0';
	free(formats->conv);
	formats->conv = buff;
	printf("	minus buff: |%s|\n	i: %d\n", buff, i);
	return (0);
}

int					apply_flag_zero(t_format *formats)
{
	int		i;
	int		start;

	i = 0;
	printf("	applying flag zero\n");
	printf("	true_len: %d\n", formats->true_len);
	if (formats->old_len == -1)
		formats->old_len = formats->true_len;
	if (formats->precision > 0 && is_charset(formats->type, "diuxX") != -1 &&
		((formats->prec_in_param == 1) ? (formats->precision_param >= 0) : 1))
		return (0);
	start = formats->true_len - formats->old_len;
	printf("	start string: |%s|\n", &formats->conv[start]);
	if (formats->conv[start] == '-')
	{
		formats->conv[0] = '-';
		i = 1;
		while (i <= start)
			formats->conv[i++] = '0';
		return (0);
	}
	printf("	start nb: %d\n", start);
	while (i < start)
		formats->conv[i++] = '0';
	////printf("zero buff: _%s_\ni: %d\n", formats->conv, i);
	return (0);
}
