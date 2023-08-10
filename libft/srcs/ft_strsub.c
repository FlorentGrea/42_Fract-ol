/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrea <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 04:01:38 by fgrea             #+#    #+#             */
/*   Updated: 2017/03/13 17:48:45 by fgrea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t		i;
	size_t		y;
	char		*s2;

	if (s)
	{
		if ((s2 = (char *)malloc(sizeof(*s2) * len + 1)) == NULL)
			return (NULL);
		i = start;
		y = 0;
		len = start + len;
		while (s[i] && i < len)
		{
			s2[y] = s[i];
			y++;
			i++;
		}
		s2[y] = '\0';
		return (s2);
	}
	return (NULL);
}
