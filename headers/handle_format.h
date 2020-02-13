/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 11:57:50 by jchene            #+#    #+#             */
/*   Updated: 2020/02/13 14:46:02 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HANDLE_FORMAT_H
# define HANDLE_FORMAT_H

typedef struct	s_format
{
	int			flags;
	int			width;
	int			precision;
	int			type;
}				t_format;

char			*convert_int(int nb);
#endif
