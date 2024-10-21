/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:21:34 by mstrauss          #+#    #+#             */
/*   Updated: 2024/10/20 21:55:54 by mstrauss         ###   ########.fr       */
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
	ray->ray_dir.x = player->direction.x + player->plane.x * ray->camera_x;
	ray->camera_x = 2 * x / width - 1;
	ray->ray_dir.y = player->direction.y + player->plane.y * ray->camera_x;
	ray->map_box.x = (int)player->position.x;
	ray->map_box.y = (int)player->position.y;
}

void	get_side_dist(t_player *player, t_ray *ray)
{
	if (ray->ray_dir.x < 0)
	{
		ray->step.x = -1;
		ray->side_dist.x = (player->position.x - ray->map_box.x)
			* ray->delta_dist.x;
	}
	else
	{
		ray->step.x = 1;
		ray->side_dist.x = (ray->map_box.x + 1.0 - player->position.x)
			* ray->delta_dist.x;
	}
	if (ray->ray_dir.y < 0)
	{
		ray->step.y = -1;
		ray->side_dist.y = (player->position.y - ray->map_box.y)
			* ray->delta_dist.y;
	}
	else
	{
		ray->step.y = 1;
		ray->side_dist.y = (ray->map_box.y + 1.0 - player->position.y)
			* ray->delta_dist.y;
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
		ray->wall_hit_x = player->position.y + ray->perpendicular_wall_dist
			* ray->ray_dir.y;
	else
		ray->wall_hit_x = player->position.x + ray->perpendicular_wall_dist
			* ray->ray_dir.x;
	ray->wall_hit_x -= floor(ray->wall_hit_x);
}

// unsure about correctness, check later when compilable
//
void	get_texture_x(t_ray *ray)
{
	ray->texture_x = (int)(ray->wall_hit_x * (double)TEXTURE_SIZE);
	if ((ray->side == EAST || ray->side == WEST) && ray->ray_dir.x > 0)
		ray->texture_x = TEXTURE_SIZE - ray->texture_x - 1;
	if ((ray->side == NORTH || ray->side == SOUTH) && ray->ray_dir.y < 0)
		ray->texture_x = TEXTURE_SIZE - ray->texture_x - 1;
}

void	draw_vert_stripe(t_ray *ray, t_main *main, int x)
{
	int			i;
	int			texture_y;
	double		step;
	double		texture_pos;
	uint32_t	color;

	i = ray->line_start - 1;
	step = TEXTURE_SIZE / ray->line_height; // cast TEXTURE_SIZE to double?
	texture_pos = (ray->line_start - main->player->pitch - (main->mlx->height
				+ ray->line_height) / 2) * step;
	while (++i < ray->line_end)
	{
		texture_y = (int)texture_pos; //
		texture_pos += step;
		color = main->textures[ray->side]->pixels[TEXTURE_SIZE * texture_y
			+ ray->texture_x];
		mlx_put_pixel(main->image, x, i, color);
	}
}

void	render_3d(t_main *main)
{
	t_player	*player;
	t_ray		ray;
	int			x;

	// init_new_structs();
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
