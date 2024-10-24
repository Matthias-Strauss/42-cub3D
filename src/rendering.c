/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:21:34 by mstrauss          #+#    #+#             */
/*   Updated: 2024/10/24 17:33:10 by mstrauss         ###   ########.fr       */
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
		texture_y = (int)texture_pos; /* & (TEXTURE_SIZE - 1);*/
		// bitwise is faster than modulus
		texture_pos += step;
		ft_memcpy(&main->image->pixels[(y * main->image->width + x) * 4],
			&main->textures[ray->side]->pixels[(TEXTURE_SIZE * texture_y
				+ ray->texture_x) * 4], sizeof(uint8_t) * 4);
	}
}

void	draw_floor(t_main *main)
{
	int		y;
	int		x;
	t_ray	ray_left;
	t_ray	ray_right;
	t_yz	pos;
	t_vec	step;
	double	dist;
	t_vec	floor;
	t_point	map_tile;
	t_point	texture;

	y = main->mlx->height / 2 - 1 + main->player->pitch;
	while (++y < main->mlx->height)
	{
		ray_left.dir.x = main->player->dir.x - main->player->plane.x;
		ray_left.dir.y = main->player->dir.y - main->player->plane.y;
		ray_right.dir.x = main->player->dir.x + main->player->plane.x;
		ray_right.dir.y = main->player->dir.y + main->player->plane.y;
		pos.y = y - main->mlx->height / 2 - main->player->pitch;
		pos.z = main->mlx->height / 2;
		dist = pos.z / pos.y;
		step.x = dist * (ray_right.dir.x - ray_left.dir.x) / main->mlx->width;
		step.y = dist * (ray_right.dir.y - ray_left.dir.y) / main->mlx->width;
		floor.x = main->player->pos.x + dist * ray_left.dir.x;
		floor.y = main->player->pos.y + dist * ray_left.dir.y;
		x = -1;
		while (++x < main->mlx->width)
		{
			map_tile.x = (int)floor.x;
			map_tile.y = (int)floor.y;
			texture.x = (int)(main->textures[FLOOR]->width * (floor.x
						- map_tile.x)) & (main->textures[FLOOR]->width - 1);
			texture.y = (int)(main->textures[FLOOR]->height * (floor.y
						- map_tile.y)) & (main->textures[FLOOR]->height - 1);
			floor.x += step.x;
			floor.y += step.y;
			ft_memcpy(&main->image->pixels[(y * main->image->width + x) * 4],
				&main->textures[FLOOR]->pixels[(main->textures[FLOOR]->width
					* texture.y + texture.x) * 4], sizeof(uint8_t) * 4);
		}
	}
}

void	draw_ceiling(t_main *main)
{
	int		y;
	int		x;
	t_ray	ray_left;
	t_ray	ray_right;
	t_yz	pos;
	t_vec	step;
	double	dist;
	t_vec	ceiling;
	t_point	map_tile;
	t_point	texture;

	y = main->mlx->height / 2 - 1 - main->player->pitch;
	while (++y < main->mlx->height)
	{
		ray_left.dir.x = main->player->dir.x - main->player->plane.x;
		ray_left.dir.y = main->player->dir.y - main->player->plane.y;
		ray_right.dir.x = main->player->dir.x + main->player->plane.x;
		ray_right.dir.y = main->player->dir.y + main->player->plane.y;
		pos.y = y - main->mlx->height / 2 + main->player->pitch;
		pos.z = main->mlx->height / 2;
		dist = pos.z / pos.y;
		step.x = dist * (ray_right.dir.x - ray_left.dir.x) / main->mlx->width;
		step.y = dist * (ray_right.dir.y - ray_left.dir.y) / main->mlx->width;
		ceiling.x = main->player->pos.x + dist * ray_left.dir.x;
		ceiling.y = main->player->pos.y + dist * ray_left.dir.y;
		x = -1;
		while (++x < main->mlx->width)
		{
			map_tile.x = (int)ceiling.x;
			map_tile.y = (int)ceiling.y;
			texture.x = (int)(main->textures[CEILING]->width * (ceiling.x
						- map_tile.x)) & (main->textures[CEILING]->width - 1);
			texture.y = (int)(main->textures[CEILING]->height * (ceiling.y
						- map_tile.y)) & (main->textures[CEILING]->height - 1);
			ceiling.x += step.x;
			ceiling.y += step.y;
			ft_memcpy(&main->image->pixels[((main->mlx->height - y - 1)
					* main->image->width + x) * 4],
				&main->textures[CEILING]->pixels[(main->textures[CEILING]->width
					* texture.y + texture.x) * 4], sizeof(uint8_t) * 4);
		}
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
