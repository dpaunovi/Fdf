/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaunovi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 16:26:24 by dpaunovi          #+#    #+#             */
/*   Updated: 2017/01/28 16:21:47 by dpaunovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "fdf.h"
#include "mlx.h"

void	draw(t_env *e)
{
	char	*line;
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (0)
	{
//		printf("%d\n", p.i);
		while (x)
		{
			mlx_pixel_put(e->mlx, e->win, x, y, 0xFF0000);
			x++;
			y++;
		}
	}
		y++;
}

int		key_hook(int keycode, t_env *e)
{
	printf("key code : %d\n", keycode);
	if (keycode == 53)
		exit(0);
	return (0);
}
/*
int		mouse_hook(int button, int x, int y, t_env *e)
{
	printf("mouse : %d (%d:%d)\n", button, x, y);
	return (0);
}*/

int		expose_hook(t_env *e)
{
	draw(e);
	return (0);
}

int		main(int argc, char **argv)
{
	t_env	e;

	e.size_x = 400;
	e.size_y = 400;
	if (argc != 2)
		return (0);
	else
	{
		if (lst_tab(file_lst(argv[1]), &e))
		{
			e.mlx = mlx_init();
			e.win = mlx_new_window(e.mlx, e.size_x, e.size_y, "FDF");
			mlx_key_hook(e.win, key_hook, &e);
			mlx_expose_hook(e.win, expose_hook, &e);
//			mlx_mouse_hook(e.win, mouse_hook, &e);
			mlx_loop(e.mlx);
		}
		else
			ft_putstr("File error\n");
	}
	return (0);
}