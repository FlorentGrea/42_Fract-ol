/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrea <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 05:28:01 by fgrea             #+#    #+#             */
/*   Updated: 2017/03/13 17:42:46 by fgrea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dest;
	unsigned char	*sorc;
	size_t			i;

	i = 0;
	dest = (unsigned char *)dst;
	sorc = (unsigned char *)src;
	if (dest < sorc)
	{
		while (i++ < len)
			*dest++ = *sorc++;
	}
	if (dest > sorc)
	{
		while (len--)
			dest[len] = sorc[len];
	}
	return (dst);
}
