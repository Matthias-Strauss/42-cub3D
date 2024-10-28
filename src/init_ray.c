/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 13:36:05 by mstrauss          #+#    #+#             */
/*   Updated: 2024/10/28 13:36:35 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

inline void	init_new_ray(t_player *player, t_ray *ray, int_fast32_t x,
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
