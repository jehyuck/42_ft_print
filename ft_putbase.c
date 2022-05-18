/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbase.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyou <jeyou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 20:28:08 by jeyou             #+#    #+#             */
/*   Updated: 2022/04/27 17:54:29 by jeyou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_putbase_print(unsigned int n, char *base)
{
	int	rtn;

	rtn = 1;
	if (n >= 16)
		rtn += ft_putbase_print(n / 16, base);
	write(1, &base[n % 16], 1);
	return (rtn);
}

int	ft_putbase_p_print(size_t n, char *base)
{
	int	rtn;

	rtn = 1;
	if (n >= 16)
		rtn += ft_putbase_p_print(n / 16, base);
	write(1, &base[n % 16], 1);
	return (rtn);
}

int	ft_putbase(unsigned int n, char format)
{
	if (format == 'x')
		return (ft_putbase_print(n, "0123456789abcdef"));
	else
		return (ft_putbase_print(n, "0123456789ABCDEF"));
}

int	ft_putbase_p(size_t n)
{
	int	rtn;

	rtn = 2;
	write(1, "0x", 2);
	rtn += ft_putbase_p_print(n, "0123456789abcdef");
	return (rtn);
}
