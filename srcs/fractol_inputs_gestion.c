/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_inputs_gestion.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrea <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 12:53:40 by fgrea             #+#    #+#             */
/*   Updated: 2017/04/04 12:02:15 by fgrea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static t_pxl	*fractol_mouse_situation(t_pxl *pxl, int x, int y, int i)
{
	if (i == 1)
	{
		pxl->x1 += x / pxl->zoom_x - (x / (pxl->zoom_x / 2));
		pxl->y1 += y / pxl->zoom_y - (y / (pxl->zoom_y / 2));
		pxl->zoom_x = pxl->zoom_x / 2;
		pxl->zoom_y = pxl->zoom_y / 2;
		pxl->it_max -= 5;
	}
	if (i == 0)
	{
		pxl->x1 += x / pxl->zoom_x - (x / (pxl->zoom_x * 2));
		pxl->y1 += y / pxl->zoom_y - (y / (pxl->zoom_y * 2));
		pxl->zoom_x = pxl->zoom_x * 2;
		pxl->zoom_y = pxl->zoom_y * 2;
		pxl->it_max += 5;
	}
	return (pxl);
}

int				fractol_key_capture(int kcd, t_pxl *pxl)
{
	if (kcd == 18)
		pxl->av = "Mandelbrot";
	if (kcd == 19)
		pxl->av = "Mandelbar";
	if (kcd == 20)
		pxl->av = "Julia";
	if (kcd == 21)
		pxl->av = "BurningShip";
	if (kcd == 78)
		pxl->it_max -= 5;
	if (kcd == 69)
		pxl->it_max += 5;
	if (kcd == 69 || kcd == 78)
		fractol_mouse_input(kcd, 0, 0, pxl);
	if (kcd == 15)
		pxl = fractol_pxl_set(pxl);
	if (kcd == 18 || kcd == 19 || kcd == 20 || kcd == 21 || kcd == 15)
		pxl = fractol_image_inputs(pxl);
	if (kcd == 1 && ft_strcmp(pxl->av, "Julia") != 0)
		pxl->top = 1;
	if (kcd == 1 && ft_strcmp(pxl->av, "Julia") == 0)
		pxl->top = 0;
	if (kcd == 53)
		exit(0);
	return (0);
}

int				fractol_mouse_capture(int x, int y, t_pxl *pxl)
{
	if (pxl->top == 1)
	{
		pxl->tz_r = ((float)(x - (pxl->img_x / 2))) / (pxl->img_x / 2);
		pxl->tz_i = ((float)(y - (pxl->img_y / 2))) / (pxl->img_y / 2);
		if (ft_strcmp(pxl->av, "Mandelbrot") == 0)
			pxl = fractol_mandelbrot(pxl);
		if (ft_strcmp(pxl->av, "Mandelbar") == 0)
			pxl = fractol_mandelbar(pxl);
		if (ft_strcmp(pxl->av, "Julia") == 0)
			pxl = fractol_julia(pxl);
		if (ft_strcmp(pxl->av, "BurningShip") == 0)
			pxl = fractol_burningship(pxl);
	}
	return (0);
}

int				fractol_mouse_input(int keycode, int x, int y, t_pxl *pxl)
{
	if (keycode == 2 || keycode == 4)
		pxl = fractol_mouse_situation(pxl, x, y, 1);
	if (keycode == 1 || keycode == 5)
		pxl = fractol_mouse_situation(pxl, x, y, 0);
	if (ft_strcmp(pxl->av, "Mandelbrot") == 0)
		pxl = fractol_mandelbrot(pxl);
	if (ft_strcmp(pxl->av, "Mandelbar") == 0)
		pxl = fractol_mandelbar(pxl);
	if (ft_strcmp(pxl->av, "Julia") == 0)
		pxl = fractol_julia(pxl);
	if (ft_strcmp(pxl->av, "BurningShip") == 0)
		pxl = fractol_burningship(pxl);
	return (0);
}
