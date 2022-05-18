/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyou <jeyou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 20:27:58 by jeyou             #+#    #+#             */
/*   Updated: 2022/05/18 17:45:39 by jeyou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_parse(va_list ap, const char *format, int *i, size_t len)
{
	int	rtn;

	rtn = 0;
	if ((size_t)(*i + 1) < len)
	{
		if (format[*i + 1] == 'c')
			rtn += ft_putchar(va_arg(ap, int));
		else if (format[*i + 1] == 's')
			rtn += ft_putstr(va_arg(ap, char *));
		else if (format[*i + 1] == 'd' || format[*i + 1] == 'i')
			rtn += ft_putnbr(va_arg(ap, int));
		else if (format[*i + 1] == 'u')
			rtn += ft_putnbr_u(va_arg(ap, unsigned int));
		else if (ft_strchr("xX", format[*i + 1]))
			rtn += ft_putbase(va_arg(ap, unsigned int), format[*i + 1]);
		else if (format[*i + 1] == 'p')
			rtn += ft_putbase_p(va_arg(ap, size_t));
		else if (format[*i + 1] == '%')
			rtn += write(1, "%", 1);
		*i += 1;
	}
	return (rtn);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		rtn;
	int		i;
	size_t	format_len;

	if (!format)
		return (-1);
	format_len = ft_strlen(format);
	rtn = 0;
	i = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%')
			rtn += ft_parse(ap, format, &i, format_len) - 2;
		else
			write(1, &format[i], 1);
		i++;
	}
	va_end(ap);
	return (i + rtn);
}
