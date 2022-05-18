/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyou <jeyou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 20:28:14 by jeyou             #+#    #+#             */
/*   Updated: 2022/04/27 17:58:20 by jeyou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	char	c;
	int		rtn;

	rtn = 1;
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		write(1, "-", 1);
		rtn += 1;
		n *= -1;
	}
	if (n >= 10)
		rtn += ft_putnbr(n / 10);
	c = n % 10 + '0';
	write(1, &c, 1);
	return (rtn);
}

int	ft_putnbr_u(unsigned int n)
{
	char	c;
	int		rtn;

	rtn = 1;
	if (n >= 10)
		rtn += ft_putnbr(n / 10);
	c = n % 10 + '0';
	write(1, &c, 1);
	return (rtn);
}
