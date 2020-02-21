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
	//printf("	applying flag minus\n");
	if (!(buff = (char *)malloc(sizeof(char) * ft_strlen(formats->conv) + 1)))
		return (-1);
	////printf("len: %d\n", ft_strlen(formats->conv));
	start = formats->true_len - formats->old_len;
	////printf("start: %d\n", start);
	ft_strcpy(&buff[0], &formats->conv[start]);
	while (i < start)
		buff[formats->old_len + i++] = ' ';
	buff[formats->old_len + i] = '\0';
	free(formats->conv);
	formats->conv = buff;
	////printf("minus buff: %s\ni: %d\n", buff, i);
	return (0);
}

int					apply_flag_zero(t_format *formats)
{
	int		i;
	int		start;

	i = 0;
	//printf("	applying flag zero\n");
	start = ft_strlen(formats->conv) - formats->old_len;
	////printf("starting at: %d\n", start);
	while (i < start)
		formats->conv[i++] = '0';
	////printf("zero buff: _%s_\ni: %d\n", formats->conv, i);
	return (0);
}
