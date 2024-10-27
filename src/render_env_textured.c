/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_env_textured.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 17:55:17 by mstrauss          #+#    #+#             */
/*   Updated: 2024/10/27 21:15:07 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

inline void	draw_floor_textured(t_main *main)
{
	t_z_ray		ray;
	uint32_t	*px_src;
	uint32_t	*px_dst;

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
			px_dst = (uint32_t *)&main->image->pixels[(ray.pixel.y
					* main->image->width + ray.pixel.x) * sizeof(uint8_t) * 4];
			px_src = (uint32_t *)&main->textures[FLOOR]->pixels[(main->textures[FLOOR]->width
					* ray.texture.y + ray.texture.x) * sizeof(uint8_t) * 4];
			*px_dst = *px_src;
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

inline void	draw_ceiling_textured(t_main *main)
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
			copy_pixel(&main->image->pixels[((main->mlx->height - ray.pixel.y
						- 1) * main->image->width + ray.pixel.x) * 4],
				&main->textures[CEILING]->pixels[(main->textures[CEILING]->width
					* ray.texture.y + ray.texture.x) * 4], sizeof(uint8_t) * 4);
		}
	}
}
