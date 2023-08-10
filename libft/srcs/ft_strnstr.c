/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrea <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 17:05:40 by fgrea             #+#    #+#             */
/*   Updated: 2017/03/13 17:47:35 by fgrea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	y;
	char	*s;

	s = (char *)big;
	i = 0;
	y = 0;
	if (ft_strlen(little) == 0)
		return (s);
	while (s[y] && y < len)
	{
		while (s[y + i] == little[i] && (y + i) < len)
		{
			i++;
			if (little[i] == '\0')
				return (&s[y]);
		}
		i = 0;
		y++;
	}
	return (NULL);
}
