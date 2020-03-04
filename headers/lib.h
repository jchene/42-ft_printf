/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 11:28:27 by jchene            #+#    #+#             */
/*   Updated: 2020/03/04 17:15:19 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_H
# define LIB_H
# include "ext_libs.h"
# include "ft_printf.h"

void	ft_putstr(char *str, int nb);
void	*ft_memset(void *s, int c, int n);
void	*ft_calloc(int count, int size);

int		is_charset(char c, char *charset);
int		ft_strlen(char *str);
void	ft_strlcpy(char *dst, char *src, int nb);
void	ft_strcpy(char *dst, char *src);
void	ft_strncat(char *dst, char *src, int n, int buff_len);

int		int_len(int nb);
int		uint_len(unsigned int nb);
int		ul_len(unsigned long nb);
int		ft_atoi(char *str);
int		ft_power(int nb, int power);
int		revert_hexa(char *str);
#endif
