/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 19:29:45 by mmakarov          #+#    #+#             */
/*   Updated: 2023/03/29 09:43:38 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_hook(int key_code, t_fr *fr)
{
	if (key_code == ESC)
		exit(1);
	if (key_code == LEFT_KEY)
		fr->x -= 1;
	if (key_code == RIGHT_KEY)
		fr->x += 1;
	if (key_code == UP_KEY)
		fr->y -= 1;
	if (key_code == DOWN_KEY)
		fr->y += 1;
//	mlx_clear_window(fr->mlx, fr->mlx_win);
	if (!ft_strcmp(fr->fractal, "Mandelbrot"))
		mandelbrot(fr);
	if (!ft_strcmp(fr->fractal, "Julia"))
		julia(fr);
	if (!ft_strcmp(fr->fractal, "Buddhabrot"))
		buddhabrot(fr);
	mlx_put_image_to_window(fr->mlx, fr->mlx_win, fr->img, fr->x, fr->y);
	return (0);
}

int	zoom_unzoom(int key_code, int x, int y, t_fr *fr)
{
	(void)x;
	(void)y;
	if (key_code == ON_MOUSEDOWN || key_code == ON_MOUSEUP)
	{
		if (key_code == ON_MOUSEDOWN)
			fr->zoom /= 0.8;
		else
			fr->zoom *= 0.8;
	}
	//mlx_clear_window(fr->mlx, fr->mlx_win); //it should zoom without clearing
	if (!ft_strcmp(fr->fractal, "Mandelbrot"))
		mandelbrot(fr);
	if (!ft_strcmp(fr->fractal, "Julia"))
		julia(fr);
	if (!ft_strcmp(fr->fractal, "Buddhabrot"))
		buddhabrot(fr);
	mlx_put_image_to_window(fr->mlx, fr->mlx_win, fr->img, fr->x, fr->y);
	return (0);
}
/*
int	mouse_hook(int click)
{
	if (click == 1)
		printf("%s\n", "left");
	else if (click == 2)
		printf("%s\n", "right");
	return (0);
}
*/
