/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_wasd_keys.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kklockow <kklockow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 00:44:12 by kklockow          #+#    #+#             */
/*   Updated: 2024/10/23 19:22:17 by kklockow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	w_key(t_main *main, t_vec *pos, t_vec dist, t_point r)
{
	t_point	new;

	if (mlx_is_key_down(main->mlx, MLX_KEY_W))
	{
		new.y = (int)(pos->y + dist.y);
		new.x = (int)(pos->x + dist.x);
		if (main->map_data->map_coor[new.y][new.x] != '1'
			&& (main->map_data->map_coor[r.y][new.x] != '1'
				|| main->map_data->map_coor[new.y][r.x] != '1'))
		{
			pos->y += dist.y;
			pos->x += dist.x;
		}
	}
}

void	a_key(t_main *main, t_vec *pos, t_vec dist, t_point r)
{
	t_point	new;

	if (mlx_is_key_down(main->mlx, MLX_KEY_A))
	{
		new.x = (int)(pos->x + dist.y);
		new.y = (int)(pos->y - dist.x);
		if (main->map_data->map_coor[new.y][new.x] != '1'
			&& (main->map_data->map_coor[r.y][new.x] != '1'
				|| main->map_data->map_coor[new.y][r.x] != '1'))
		{
			pos->y -= dist.x;
			pos->x += dist.y;
		}
	}
}

void	s_key(t_main *main, t_vec *pos, t_vec dist, t_point r)
{
	t_point	new;

	if (mlx_is_key_down(main->mlx, MLX_KEY_S))
	{
		new.x = (int)(pos->x - dist.x);
		new.y = (int)(pos->y - dist.y);
		if (main->map_data->map_coor[new.y][new.x] != '1'
			&& (main->map_data->map_coor[r.y][new.x] != '1'
				|| main->map_data->map_coor[new.y][r.x] != '1'))
		{
			pos->y -= dist.y;
			pos->x -= dist.x;
		}
	}
}

void	d_key(t_main *main, t_vec *pos, t_vec dist, t_point r)
{
	t_point	new;

	if (mlx_is_key_down(main->mlx, MLX_KEY_D))
	{
		new.y = (int)(pos->y + dist.x);
		new.x = (int)(pos->x - dist.y);
		if (main->map_data->map_coor[new.y][new.x] != '1'
			&& (main->map_data->map_coor[r.y][new.x] != '1'
				|| main->map_data->map_coor[new.y][r.x] != '1'))
		{
			pos->y += dist.x;
			pos->x -= dist.y;
		}
	}
}

void	wasd_keys(t_main *main)
{
	t_vec	dist;
	t_point	pos_rounded;

	pos_rounded.x = (int)main->player->pos.x;
	pos_rounded.y = (int)main->player->pos.y;
	dist.y = main->player->dir.y * main->player->speed;
	dist.x = main->player->dir.x * main->player->speed;
	w_key(main, &main->player->pos, dist, pos_rounded);
	a_key(main, &main->player->pos, dist, pos_rounded);
	s_key(main, &main->player->pos, dist, pos_rounded);
	d_key(main, &main->player->pos, dist, pos_rounded);
}
