/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrea <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 09:52:00 by fgrea             #+#    #+#             */
/*   Updated: 2017/03/13 17:47:02 by fgrea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		if (src[i] == '\0' && i < len)
		{
			while (i < len)
			{
				dst[i] = '\0';
				i++;
			}
			return (dst);
		}
		dst[i] = src[i];
		i++;
	}
	return (dst);
}
