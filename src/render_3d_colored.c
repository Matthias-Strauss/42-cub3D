/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_3d_colored.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:21:34 by mstrauss          #+#    #+#             */
/*   Updated: 2024/10/28 14:13:41 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static inline void	get_perp_wall_dist(t_ray *ray)
{
	if (ray->side == EAST || ray->side == WEST)
		ray->perpendicular_wall_dist = ray->side_dist.x - ray->delta_dist.x;
	else
		ray->perpendicular_wall_dist = ray->side_dist.y - ray->delta_dist.y;
}

static inline void	get_side_dist(t_player *player, t_ray *ray)
{
	if (ray->dir.x < 0)
	{
		ray->step.x = -1;
		ray->side_dist.x = ray->delta_dist.x * (player->pos.x
				- ray->map_tile.x);
	}
	else
	{
		ray->step.x = 1;
		ray->side_dist.x = ray->delta_dist.x * (ray->map_tile.x + 1.0
				- player->pos.x);
	}
	if (ray->dir.y < 0)
	{
		ray->step.y = -1;
		ray->side_dist.y = ray->delta_dist.y * (player->pos.y
				- ray->map_tile.y);
	}
	else
	{
		ray->step.y = 1;
		ray->side_dist.y = ray->delta_dist.y * (ray->map_tile.y + 1.0
				- player->pos.y);
	}
}

static inline void	get_wall_height(t_ray *ray, t_main *main)
{
	int_fast32_t	pitch;

	pitch = main->player->pitch;
	ray->line_height = (int_fast32_t)(main->mlx->height
			/ ray->perpendicular_wall_dist);
	ray->line_start = (-ray->line_height + main->mlx->height) / 2 + pitch;
	if (ray->line_start < 0)
		ray->line_start = 0;
	ray->line_end = (ray->line_height + main->mlx->height) / 2 + pitch;
	if (ray->line_end >= main->mlx->height)
		ray->line_end = main->mlx->height - 1;
}

static inline void	draw_vert_stripe_color(t_ray *ray, t_main *main,
int_fast32_t x)
{
	int_fast32_t	y;

	y = ray->line_start - 1;
	while (++y < ray->line_end)
		ft_memcpy(&(main->image->pixels[(y * main->image->width + x) * 4]),
			&(main->colors[((4 * main->frame) + (60 * ray->side * 4)) % 1016]),
			4);
}

void	render_3d_colored(t_main *main)
{
	t_player		*player;
	t_ray			ray;
	int_fast32_t	x;

	player = main->player;
	x = -1;
	while (++x < main->mlx->width)
	{
		init_new_ray(player, &ray, x, main->mlx->width);
		get_side_dist(player, &ray);
		dda_algo(main, &ray);
		get_perp_wall_dist(&ray);
		get_wall_height(&ray, main);
		draw_vert_stripe_color(&ray, main, x);
	}
}
