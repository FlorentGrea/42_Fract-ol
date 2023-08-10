/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrea <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 23:45:43 by fgrea             #+#    #+#             */
/*   Updated: 2017/03/13 17:42:52 by fgrea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memset(void *s, int c, size_t len)
{
	unsigned char	*str;

	if (len == 0)
		return (s);
	str = (unsigned char *)s;
	while (len--)
	{
		*str = (unsigned char)c;
		if (len)
			str++;
	}
	return (s);
}
