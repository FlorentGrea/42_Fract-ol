/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_pixel_gestion.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrea <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 22:22:33 by fgrea             #+#    #+#             */
/*   Updated: 2017/03/25 22:44:57 by fgrea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static t_pxl	*fractol_color_pixel(t_pxl *pxl)
{
	if (pxl->i != pxl->it_max)
	{
		pxl->r = pxl->i * 0 / pxl->it_max;
		pxl->g = pxl->i * 0 / pxl->it_max;
		pxl->b = pxl->i * 255 / pxl->it_max;
	}
	else
	{
		pxl->r = 255;
		pxl->g = 0;
		pxl->b = 0;
	}
	return (pxl);
}

t_pxl			*fractol_put_pixel(t_pxl *pxl, int x, int y)
{
	int			ret;

	ret = (x * 4) + (y * pxl->size);
	pxl = fractol_color_pixel(pxl);
	if (0 <= ret && ret < (pxl->count * pxl->size) && \
			x < pxl->img_x && 0 <= x && 0 <= y && y < pxl->count)
	{
		pxl->data[ret] = pxl->r;
		pxl->data[ret + 1] = pxl->g;
		pxl->data[ret + 2] = pxl->b;
	}
	return (pxl);
}
