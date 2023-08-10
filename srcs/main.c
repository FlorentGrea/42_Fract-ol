/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrea <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 03:20:24 by fgrea             #+#    #+#             */
/*   Updated: 2017/03/27 03:41:14 by fgrea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void		fractol_usage(void)
{
	ft_putendl("usage : ./fractol fractal_name\nFractals available :");
	ft_putendl("Mandelbrot\nMandelbar\nJulia\nBurningShip");
	exit(0);
}

void			fractol_check_names(char **av)
{
	if (ft_strcmp(av[1], "Mandelbrot") != 0 && \
			ft_strcmp(av[1], "Julia") != 0 && \
			ft_strcmp(av[1], "Mandelbar") != 0 && \
			ft_strcmp(av[1], "BurningShip") != 0)
	{
		ft_putendl("This is not an available fractal name.\n");
		fractol_usage();
	}
}

void			fractol_error(void)
{
	ft_putendl("error");
	exit(0);
}

int				main(int ac, char **av)
{
	t_pxl		*pxl;

	if (ac != 2)
		fractol_usage();
	fractol_check_names(av);
	if ((pxl = (t_pxl *)malloc(sizeof(t_pxl))) == NULL)
		fractol_error();
	pxl->av = av[1];
	pxl = fractol_pxl_set(pxl);
	if ((pxl->mlx = mlx_init()) == NULL)
		fractol_error();
	mlx_do_key_autorepeaton(pxl->mlx);
	if ((pxl->win = mlx_new_window(pxl->mlx, 1080, 1080, "FRACTOL")) == NULL)
		fractol_error();
	pxl->img = NULL;
	pxl = fractol_image_inputs(pxl);
	mlx_hook(pxl->win, 2, 0, fractol_key_capture, pxl);
	mlx_hook(pxl->win, 6, 0, fractol_mouse_capture, pxl);
	mlx_hook(pxl->win, 4, 0, fractol_mouse_input, pxl);
	mlx_loop(pxl->mlx);
	return (0);
}
