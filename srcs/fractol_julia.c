/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_julia.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrea <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 05:23:26 by fgrea             #+#    #+#             */
/*   Updated: 2017/03/25 19:32:26 by fgrea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

t_pxl				*fractol_julia_variables(t_pxl *pxl, int i)
{
	if (i == 0)
	{
		pxl->top = 1;
		pxl->x1 = -pxl->gx;
		pxl->x2 = pxl->gx;
		pxl->y1 = -pxl->gy;
		pxl->y2 = pxl->gy;
		pxl->zoom_x = pxl->img_x / (pxl->x2 - pxl->x1);
		pxl->zoom_y = pxl->img_y / (pxl->y2 - pxl->y1);
		pxl->it_max = 50;
	}
	if (i == 1)
	{
		pxl->c_r = pxl->tz_r;
		pxl->c_i = pxl->tz_i;
		pxl->z_r = pxl->x / pxl->zoom_x + pxl->x1;
		pxl->z_i = pxl->y / pxl->zoom_y + pxl->y1;
		pxl->i = 0;
	}
	pxl->zr = pxl->z_r * pxl->z_r;
	pxl->zi = pxl->z_i * pxl->z_i;
	return (pxl);
}

static void			*fractol_julia2(void *d)
{
	t_pxl			*i;
	double			tmp;

	i = (t_pxl *)d;
	while (++i->y < i->img_y)
	{
		while (++i->x < i->img_x)
		{
			i = fractol_julia_variables(i, 1);
			while (i->zr + i->zi < 4 && i->i < i->it_max)
			{
				i = fractol_julia_variables(i, 2);
				tmp = i->z_r;
				i->z_r = i->zr - i->zi + i->c_r;
				i->z_i = 2 * i->z_i * tmp + i->c_i;
				i->i++;
			}
			i = fractol_put_pixel(i, i->x, i->y);
		}
		i->x = 0;
	}
	return (NULL);
}

t_pxl				*fractol_julia(t_pxl *pxl)
{
	t_pxl			i[8];
	pthread_t		c[8];
	int				p;

	if (!pxl->img)
		(pxl->img = mlx_new_image(pxl->mlx, pxl->img_x, \
					pxl->img_y)) == NULL ? fractol_error() : \
		(pxl->data = mlx_get_data_addr(pxl->img, &pxl->bpp, \
				&pxl->size, &pxl->endian));
	p = -1;
	while (++p <= 7)
	{
		ft_memcpy((void*)&i[p], (void*)pxl, sizeof(t_pxl));
		i[p].x = 0;
		i[p].y = (i[p].img_y / 8) * p;
		i[p].count = i[p].img_y / (p + 1);
		pthread_create(&c[p], NULL, fractol_julia2, &i[p]);
	}
	while (p-- >= 0)
		pthread_join(c[p], NULL);
	mlx_clear_window(pxl->mlx, pxl->win);
	mlx_put_image_to_window(pxl->mlx, pxl->win, pxl->img, 0, 0);
	fractol_hud(pxl);
	return (pxl);
}
