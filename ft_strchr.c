/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyou <jeyou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 20:28:20 by jeyou             #+#    #+#             */
/*   Updated: 2022/04/27 17:59:32 by jeyou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strchr(const char *s, int c)
{
	char	*s_temp;

	s_temp = (char *)s;
	while (1)
	{
		if (*s_temp == (unsigned char)c)
			return (s_temp);
		if (*s_temp == '\0')
			break ;
		s_temp++;
	}
	return (NULL);
}
