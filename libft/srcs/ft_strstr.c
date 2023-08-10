/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrea <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 16:20:08 by fgrea             #+#    #+#             */
/*   Updated: 2017/03/13 17:48:35 by fgrea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int		i;
	char	*s;

	s = (char *)big;
	if (*little == '\0')
		return (s);
	i = 0;
	while (*s)
	{
		while (*s == little[i] && *s)
		{
			i++;
			s++;
			if (little[i] == '\0')
				return (s - i);
		}
		s -= i;
		i = 0;
		s++;
	}
	return (NULL);
}
