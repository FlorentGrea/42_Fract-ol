/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrea <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 16:32:22 by fgrea             #+#    #+#             */
/*   Updated: 2017/03/13 17:48:17 by fgrea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*p;
	size_t	i;

	i = ft_strlen(s);
	p = (char *)s + i;
	while (*p != c)
	{
		if (p == s)
			return (NULL);
		p--;
	}
	return (p);
}
