/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:21:34 by mstrauss          #+#    #+#             */
/*   Updated: 2024/10/25 12:58:19 by mstrauss         ###   ########.fr       */
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

void	init_new_ray(t_player *player, t_ray *ray, int_fast32_t x,
		int_fast32_t width)
{
	ray->hit = false;
	ray->side = 0;
	ray->cam_x = (float)(2 * x) / (float)width - 1;
	ray->dir.x = player->dir.x + (player->plane.x * ray->cam_x);
	ray->dir.y = player->dir.y + (player->plane.y * ray->cam_x);
	ray->map_tile.x = (int_fast32_t)player->pos.x;
	ray->map_tile.y = (int_fast32_t)player->pos.y;
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
	int_fast32_t	pitch;
	float			player_height;

	pitch = main->player->pitch;
	player_height = main->player->height;
	ray->line_height = (int_fast32_t)(main->mlx->height
			/ ray->perpendicular_wall_dist);
	ray->line_start = (-ray->line_height + main->mlx->height) / 2 + pitch
		- player_height;
	if (ray->line_start < 0)
		ray->line_start = 0;
	ray->line_end = (ray->line_height + main->mlx->height) / 2 + pitch
		- player_height;
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
	ray->texture_x = (int_fast32_t)(ray->wall_hit_x * (float)TEXTURE_SIZE);
	if ((ray->side == EAST || ray->side == WEST) && ray->dir.x > 0)
		ray->texture_x = TEXTURE_SIZE - ray->texture_x - 1;
	if ((ray->side == NORTH || ray->side == SOUTH) && ray->dir.y < 0)
		ray->texture_x = TEXTURE_SIZE - ray->texture_x - 1;
}

void	draw_vert_stripe(t_ray *ray, t_main *main, int_fast32_t x)
{
	int_fast32_t	y;
	int_fast32_t	texture_y;
	float			step;
	float			texture_pos;

	y = ray->line_start - 1;
	step = (TEXTURE_SIZE * 1.0) / ray->line_height;
	texture_pos = (ray->line_start + main->player->height - main->player->pitch
			- (main->mlx->height - ray->line_height) / 2) * step;
	while (++y < ray->line_end)
	{
		texture_y = (int_fast32_t)texture_pos; /* & (TEXTURE_SIZE - 1);*/
		texture_pos += step;
		ft_memcpy(&main->image->pixels[(y * main->image->width + x) * 4],
			&main->textures[ray->side]->pixels[(TEXTURE_SIZE * texture_y
				+ ray->texture_x) * 4], sizeof(uint8_t) * 4);
	}
}

static inline void	init_ray_floor(t_main *main, t_z_ray *ray)
{
	ray->l_ray_dir_x.x = main->player->dir.x - main->player->plane.x;
	ray->l_ray_dir_x.y = main->player->dir.y - main->player->plane.y;
	ray->r_ray_dir_x.x = main->player->dir.x + main->player->plane.x;
	ray->r_ray_dir_x.y = main->player->dir.y + main->player->plane.y;
	ray->pos.y = ray->pixel.y - main->mlx->height / 2 - main->player->pitch
		- main->player->height;
	ray->pos.z = main->mlx->height / 2 + main->player->height;
	ray->dist = ray->pos.z / ray->pos.y;
	ray->step.x = ray->dist * (ray->r_ray_dir_x.x - ray->l_ray_dir_x.x)
		/ main->mlx->width;
	ray->step.y = ray->dist * (ray->r_ray_dir_x.y - ray->l_ray_dir_x.y)
		/ main->mlx->width;
	ray->ceiling.x = main->player->pos.x + ray->dist * ray->l_ray_dir_x.x;
	ray->ceiling.y = main->player->pos.y + ray->dist * ray->l_ray_dir_x.y;
	ray->pixel.x = -1;
}

void	draw_floor(t_main *main)
{
	t_z_ray	ray;

	ray.pixel.y = main->mlx->height / 2 - 1 + main->player->pitch
		+ main->player->height;
	while (++ray.pixel.y < main->mlx->height)
	{
		init_ray_floor(main, &ray);
		while (++ray.pixel.x < main->mlx->width)
		{
			ray.texture.x = (int_fast32_t)(main->textures[FLOOR]->width
					* (ray.ceiling.x
						- (int_fast32_t)ray.ceiling.x)) & (main->textures[FLOOR]->width
					- 1);
			ray.texture.y = (int_fast32_t)(main->textures[FLOOR]->height
					* (ray.ceiling.y
						- (int_fast32_t)ray.ceiling.y)) & (main->textures[FLOOR]->height
					- 1);
			ray.ceiling.x += ray.step.x;
			ray.ceiling.y += ray.step.y;
			ft_memcpy(&main->image->pixels[(ray.pixel.y * main->image->width
					+ ray.pixel.x) * 4],
				&main->textures[FLOOR]->pixels[(main->textures[FLOOR]->width
					* ray.texture.y + ray.texture.x) * 4], sizeof(uint8_t) * 4);
		}
	}
}

static inline void	init_ray_ceiling(t_main *main, t_z_ray *ray)
{
	ray->l_ray_dir_x.x = main->player->dir.x - main->player->plane.x;
	ray->l_ray_dir_x.y = main->player->dir.y - main->player->plane.y;
	ray->r_ray_dir_x.x = main->player->dir.x + main->player->plane.x;
	ray->r_ray_dir_x.y = main->player->dir.y + main->player->plane.y;
	ray->pos.y = ray->pixel.y - main->mlx->height / 2 + main->player->pitch
		+ main->player->height;
	ray->pos.z = main->mlx->height / 2 + main->player->height;
	ray->dist = ray->pos.z / ray->pos.y;
	ray->step.x = ray->dist * (ray->r_ray_dir_x.x - ray->l_ray_dir_x.x)
		/ main->mlx->width;
	ray->step.y = ray->dist * (ray->r_ray_dir_x.y - ray->l_ray_dir_x.y)
		/ main->mlx->width;
	ray->ceiling.x = main->player->pos.x + ray->dist * ray->l_ray_dir_x.x;
	ray->ceiling.y = main->player->pos.y + ray->dist * ray->l_ray_dir_x.y;
	ray->pixel.x = -1;
}

void	draw_ceiling(t_main *main)
{
	t_z_ray	ray;

	ray.pixel.y = main->mlx->height / 2 - 1 - main->player->pitch
		+ main->player->height;
	while (++ray.pixel.y < main->mlx->height)
	{
		init_ray_ceiling(main, &ray);
		while (++ray.pixel.x < main->mlx->width)
		{
			ray.texture.x = (int_fast32_t)(main->textures[CEILING]->width
					* (ray.ceiling.x
						- (int_fast32_t)ray.ceiling.x)) & (main->textures[CEILING]->width
					- 1);
			ray.texture.y = (int_fast32_t)(main->textures[CEILING]->height
					* (ray.ceiling.y
						- (int_fast32_t)ray.ceiling.y)) & (main->textures[CEILING]->height
					- 1);
			ray.ceiling.x += ray.step.x;
			ray.ceiling.y += ray.step.y;
			ft_memcpy(&main->image->pixels[((main->mlx->height - ray.pixel.y
						- 1) * main->image->width + ray.pixel.x) * 4],
				&main->textures[CEILING]->pixels[(main->textures[CEILING]->width
					* ray.texture.y + ray.texture.x) * 4], sizeof(uint8_t) * 4);
		}
	}
}

void	render_3d(t_main *main)
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
		get_wall_hit_x_pos(&ray, player);
		get_texture_x(&ray);
		draw_vert_stripe(&ray, main, x);
	}
}
