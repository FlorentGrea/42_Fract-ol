/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_image_gestion.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrea <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 09:14:55 by fgrea             #+#    #+#             */
/*   Updated: 2017/03/25 22:43:30 by fgrea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void			fractol_hud(t_pxl *pxl)
{
	int			i;

	i = 0x00FF00;
	mlx_string_put(pxl->mlx, pxl->win, 10, 0, i, "1 : Mandelbrot");
	mlx_string_put(pxl->mlx, pxl->win, 10, 20, i, "2 : Mandelbar");
	mlx_string_put(pxl->mlx, pxl->win, 10, 40, i, "3 : Julia");
	mlx_string_put(pxl->mlx, pxl->win, 10, 60, i, "4 : BurningShip");
	mlx_string_put(pxl->mlx, pxl->win, 10, 80, i, "+ : It++");
	mlx_string_put(pxl->mlx, pxl->win, 10, 100, i, "- : It--");
	mlx_string_put(pxl->mlx, pxl->win, 10, 120, i, "R : Reset");
	mlx_string_put(pxl->mlx, pxl->win, 10, 140, i, "S : It-moove");
	mlx_string_put(pxl->mlx, pxl->win, 10, 1005, i, "R-click & mol- : dezoom");
	mlx_string_put(pxl->mlx, pxl->win, 10, 1025, i, "L-click & mol+ : zoom");
	mlx_string_put(pxl->mlx, pxl->win, 10, 1045, i, "Autorepeat is on, enjoy");
}

static t_pxl	*fractol_fractal_choice(t_pxl *pxl, char *av)
{
	if (ft_strcmp(av, "Julia") == 0)
	{
		pxl = fractol_julia_variables(pxl, 0);
		pxl = fractol_julia(pxl);
	}
	if (ft_strcmp(av, "Julia") != 0)
	{
		pxl = fractol_mandelbrot_variables(pxl, 0);
		if (ft_strcmp(av, "Mandelbrot") == 0)
			pxl = fractol_mandelbrot(pxl);
		if (ft_strcmp(av, "Mandelbar") == 0)
			pxl = fractol_mandelbar(pxl);
		if (ft_strcmp(av, "BurningShip") == 0)
			pxl = fractol_burningship(pxl);
	}
	return (pxl);
}

t_pxl			*fractol_pxl_set(t_pxl *pxl)
{
	pxl->img_x = 1080;
	pxl->img_y = 1080;
	pxl->gx = (pxl->img_x / pxl->img_y) * 2;
	pxl->gy = (pxl->img_x / pxl->img_y) * 2;
	pxl->x = -1;
	pxl->y = -1;
	pxl->tz_r = 0;
	pxl->tz_i = 0;
	return (pxl);
}

t_pxl			*fractol_image_inputs(t_pxl *pxl)
{
	pxl = fractol_fractal_choice(pxl, pxl->av);
	fractol_hud(pxl);
	return (pxl);
}
