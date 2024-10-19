/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:21:34 by mstrauss          #+#    #+#             */
/*   Updated: 2024/10/20 00:30:12 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_perp_wall_dist(t_player *player, t_ray *ray)
{
	if (ray->side == EAST || ray->side == WEST)
		ray->perpendicular_wall_dist = ray->side_dist.x - ray->delta_dist.x;
	else
		ray->perpendicular_wall_dist = ray->side_dist.y - ray->delta_dist.y;
}

void	init_new_ray(t_player *player, t_ray *ray, int x, int width)
{
	ray->ray_dir.x = player->direction.x + player->plane.x * ray->camera_x;
	ray->camera_x = 2 * x / width - 1;
	ray->ray_dir.y = player->direction.y + player->plane.y * ray->camera_x;
	ray->map_box.x = (int)player->position.x;
	ray->map_box.y = (int)player->position.y;
}

double	get_side_dist(t_player player, t_ray *ray)
{
	if (ray->ray_dir.x < 0)
	{
		ray->step.x = -1;
		ray->side_dist.x = (player.position.x - ray->map_box.x)
			* ray->delta_dist.x;
	}
	else
	{
		ray->step.x = 1;
		ray->side_dist.x = (ray->map_box.x + 1.0 - player.position.x)
			* ray->delta_dist.x;
	}
	if (ray->ray_dir.y < 0)
	{
		ray->step.y = -1;
		ray->side_dist.y = (player.position.y - ray->map_box.y)
			* ray->delta_dist.y;
	}
	else
	{
		ray->step.y = 1;
		ray->side_dist.y = (ray->map_box.y + 1.0 - player.position.y)
			* ray->delta_dist.y;
	}
}

void	get_wall_height(t_ray *ray, t_main *main)
{
	int	line_height;
	int	line_start;
	int	line_end;
	int	pitch;

	pitch = main->player->pitch;
	line_height = (int)(main->mlx->height / ray->perpendicular_wall_dist);
	line_start = (-line_height + main->mlx->height) / 2 + pitch;
	if (line_start < 0)
		line_start = 0;
	line_end = (line_height + main->mlx->height) / 2 + pitch;
	if (line_end >= main->mlx->height)
		line_end = main->mlx->height - 1;
}

void	get_wall_hit_x_pos(t_ray *ray, t_player *player)
{
	if (ray->side == EAST || ray->side == WEST)
		ray->wall_hit_x = player->position.y + ray->perpendicular_wall_dist
			* ray->ray_dir.y;
	else
		ray->wall_hit_x = player->position.x + ray->perpendicular_wall_dist
			* ray->ray_dir.x;
	ray->wall_hit_x -= floor(ray->wall_hit_x);
}

void	render_3d(t_main *main)
{
	t_player	player;
	t_ray		ray;
	int			x;

	init_new_structs();
	x = -1;
	while (++x < main->mlx->width)
	{
		init_new_ray(&player, &ray, x, main->mlx->width);
		get_side_dist(player, &ray);
		dda_algo(&player, &ray, main);
		get_perp_wall_dist(&player, &ray);
		get_wall_height(&ray, main);
		get_wall_hit_x_pos(&ray, &player);
	}
}
