/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyou <jeyou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 18:00:18 by jeyou             #+#    #+#             */
/*   Updated: 2022/05/18 17:51:18 by jeyou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>

int		ft_printf(const char *format, ...);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
int		ft_putchar(char c);
int		ft_putnbr(int n);
int		ft_putnbr_u(unsigned int n);
int		ft_putstr(char *s);
int		ft_putbase(unsigned int n, char format);
int		ft_putbase_p(size_t n);
#endif
