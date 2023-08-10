/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_burningship.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrea <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 18:54:40 by fgrea             #+#    #+#             */
/*   Updated: 2017/03/25 19:32:33 by fgrea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void			*fractol_burningship2(void *d)
{
	t_pxl			*i;
	double			tmp;

	i = (t_pxl *)d;
	while (++i->y < i->count)
	{
		while (++i->x < i->img_x)
		{
			i = fractol_mandelbrot_variables(i, 1);
			while (i->zr + i->zi < 4 && i->i < i->it_max)
			{
				i = fractol_mandelbrot_variables(i, 2);
				tmp = i->z_r;
				i->z_r = i->zr - i->zi - i->c_r;
				i->z_i = 2 * fabs(i->z_i) * fabs(tmp) + i->c_i;
				i->i++;
			}
			i = fractol_put_pixel(i, i->x, i->y);
		}
		i->x = 0;
	}
	return (NULL);
}

t_pxl				*fractol_burningship(t_pxl *pxl)
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
		pthread_create(&c[p], NULL, fractol_burningship2, &i[p]);
	}
	while (p-- >= 0)
		pthread_join(c[p], NULL);
	mlx_clear_window(pxl->mlx, pxl->win);
	mlx_put_image_to_window(pxl->mlx, pxl->win, pxl->img, 0, 0);
	fractol_hud(pxl);
	return (pxl);
}
