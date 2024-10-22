/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:21:34 by mstrauss          #+#    #+#             */
/*   Updated: 2024/10/22 19:35:49 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_perp_wall_dist(t_ray *ray)
{
	if (ray->side == EAST || ray->side == WEST)
		ray->perpendicular_wall_dist = ray->side_dist.x - ray->delta_dist.x;
	else
		ray->perpendicular_wall_dist = ray->side_dist.y - ray->delta_dist.y;
}

void	init_new_ray(t_player *player, t_ray *ray, int x, int width)
{
	ray->hit = false;
	ray->side = 0;
	ray->cam_x = (double)(2 * x) / (double)width - 1;
	ray->dir.x = player->dir.x + (player->plane.x * ray->cam_x);
	ray->dir.y = player->dir.y + (player->plane.y * ray->cam_x);
	ray->map_tile.x = (int)player->pos.x;
	ray->map_tile.y = (int)player->pos.y;
	if (ray->dir.x == 0)
		ray->delta_dist.x = DBL_MAX;
	else
		ray->delta_dist.x = fabs(1 / ray->dir.x);
	if (ray->dir.y == 0)
		ray->delta_dist.y = DBL_MAX;
	else
		ray->delta_dist.y = fabs(1 / ray->dir.y);
}

void	get_side_dist(t_player *player, t_ray *ray)
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

void	get_wall_height(t_ray *ray, t_main *main)
{
	int	pitch;

	pitch = main->player->pitch;
	ray->line_height = (int)(main->mlx->height / ray->perpendicular_wall_dist);
	ray->line_start = (-ray->line_height + main->mlx->height) / 2 + pitch;
	if (ray->line_start < 0)
		ray->line_start = 0;
	ray->line_end = (ray->line_height + main->mlx->height) / 2 + pitch;
	if (ray->line_end >= main->mlx->height)
		ray->line_end = main->mlx->height - 1;
}

void	get_wall_hit_x_pos(t_ray *ray, t_player *player)
{
	if (ray->side == EAST || ray->side == WEST)
		ray->wall_hit_x = player->pos.y + ray->perpendicular_wall_dist
			* ray->dir.y;
	else
		ray->wall_hit_x = player->pos.x + ray->perpendicular_wall_dist
			* ray->dir.x;
	ray->wall_hit_x -= floor(ray->wall_hit_x);
}

void	get_texture_x(t_ray *ray)
{
	ray->texture_x = (int)(ray->wall_hit_x * (double)TEXTURE_SIZE);
	if ((ray->side == EAST || ray->side == WEST) && ray->dir.x > 0)
		ray->texture_x = TEXTURE_SIZE - ray->texture_x - 1;
	if ((ray->side == NORTH || ray->side == SOUTH) && ray->dir.y < 0)
		ray->texture_x = TEXTURE_SIZE - ray->texture_x - 1;
}

void	draw_vert_stripe(t_ray *ray, t_main *main, int x)
{
	int		y;
	int		texture_y;
	double	step;
	double	texture_pos;

	y = ray->line_start - 1;
	step = (TEXTURE_SIZE * 1.0) / ray->line_height;
	texture_pos = (ray->line_start - main->player->pitch - (main->mlx->height
				- ray->line_height) / 2) * step;
	while (++y < ray->line_end)
	{
		texture_y = (int)texture_pos & (TEXTURE_SIZE - 1);
		// bitwise is faster than modulus
		texture_pos += step;
		ft_memcpy(&main->image->pixels[(y * main->image->width + x) * 4],
			&main->textures[ray->side]->pixels[(TEXTURE_SIZE * texture_y
				+ ray->texture_x) * 4], sizeof(uint8_t) * 4);
	}
}

void	render_3d(t_main *main)
{
	t_player	*player;
	t_ray		ray;
	int			x;

	player = main->player;
	x = -1;
	while (++x < main->mlx->width)
	{
		init_new_ray(player, &ray, x, main->mlx->width);
		get_side_dist(player, &ray);
		dda_algo(main, &ray);
		get_perp_wall_dist(&ray);
		get_wall_height(&ray, main);
		get_wall_hit_x_pos(&ray, player);
		get_texture_x(&ray);
		draw_vert_stripe(&ray, main, x);
	}
}
