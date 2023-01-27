/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvon-nag <fvon-nag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:05:20 by fvon-nag          #+#    #+#             */
/*   Updated: 2023/01/10 15:55:56 by fvon-nag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

int		ft_printf(const char *fmt, ...);
void	printint(int n, int fd, int *wlen);
void	printpointer(void *ptr, int *wlen);
void	printunsignedint(unsigned int n, int fd, int *wlen);
void	printhex(char c, unsigned int hex, int *wlen);

#endif
