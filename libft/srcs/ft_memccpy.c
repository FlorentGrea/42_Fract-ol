/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrea <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 04:08:42 by fgrea             #+#    #+#             */
/*   Updated: 2017/03/13 17:41:54 by fgrea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	*dest;
	int				q;
	size_t			i;

	i = 0;
	str = (unsigned char *)src;
	dest = (unsigned char *)dst;
	q = (unsigned char)c;
	while (i < n)
	{
		if ((dest[i] = str[i]) == q)
			return (dst + (i + 1));
		i++;
	}
	return (NULL);
}
