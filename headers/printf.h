/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 11:57:50 by jchene            #+#    #+#             */
/*   Updated: 2020/02/13 16:27:52 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

typedef struct	s_format
{
	int			flags;
	int			width;
	int			precision;
	char		*conv;
}				t_format;

int				check_format;
int				check_flags;
int				check_width;
int				check_precision;
int				check_type;

int				handle_flags;
int				handle_width;
int				handle_precision;
int				handle_type;

char			*convert_int(int nb);
#endif
