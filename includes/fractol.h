/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrea <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 14:59:37 by fgrea             #+#    #+#             */
/*   Updated: 2017/03/26 22:10:31 by fgrea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/includes/libft.h"
# include <mlx.h>
# include <math.h>
# include <pthread.h>

typedef struct		s_pxl
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*av;
	char			*data;
	int				size;
	int				bpp;
	int				endian;

	int				r;
	int				g;
	int				b;

	int				img_x;
	int				img_y;
	int				x;
	int				y;
	double			gx;
	double			gy;

	int				top;

	double			x1;
	double			x2;
	double			y1;
	double			y2;
	int				it_max;
	int				i;
	double			zoom_x;
	double			zoom_y;
	double			c_r;
	double			c_i;
	double			z_r;
	double			z_i;
	double			zr;
	double			zi;
	double			tz_r;
	double			tz_i;
	int				count;
}					t_pxl;

void				fractol_hud(t_pxl *pxl);
t_pxl				*fractol_burningship(t_pxl *pxl);
t_pxl				*fractol_mandelbar(t_pxl *pxl);
t_pxl				*fractol_julia_variables(t_pxl *pxl, int i);
t_pxl				*fractol_julia(t_pxl *pxl);
t_pxl				*fractol_mandelbrot_variables(t_pxl *pxl, int i);
int					fractol_mouse_input(int keycode, int x, int y, t_pxl *pxl);
int					fractol_mouse_capture(int x, int y, t_pxl *pxl);
t_pxl				*fractol_pxl_set(t_pxl *pxl);
void				fractol_error(void);
void				fractol_check_names(char **av);
t_pxl				*fractol_image_inputs(t_pxl *pxl);
t_pxl				*fractol_put_pixel(t_pxl *pxl, int x, int y);
t_pxl				*fractol_mandelbrot(t_pxl *pxl);
int					fractol_key_capture(int kcd, t_pxl *pxl);

#endif
