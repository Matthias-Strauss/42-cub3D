/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_3d_textured_txcalc.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 13:42:49 by mstrauss          #+#    #+#             */
/*   Updated: 2024/10/28 14:04:57 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

inline void	get_texture_x(t_main *main, t_ray *ray)
{
	ray->texture_x = (int_fast32_t)(ray->wall_hit_x
			* (float)main->textures[ray->side]->width);
	if ((ray->side == EAST || ray->side == WEST) && ray->dir.x > 0)
		ray->texture_x = main->textures[ray->side]->width - ray->texture_x - 1;
	if ((ray->side == NORTH || ray->side == SOUTH) && ray->dir.y < 0)
		ray->texture_x = main->textures[ray->side]->width - ray->texture_x - 1;
}

inline void	draw_vert_stripe(t_ray *ray, t_main *main, int_fast32_t x)
{
	t_render_helper	helper;

	helper.y = ray->line_start - 1;
	helper.texture_size = main->textures[ray->side]->width;
	helper.step = (helper.texture_size * 1.0) / ray->line_height;
	helper.texture_pos = (ray->line_start - main->player->pitch
			- (main->mlx->height - ray->line_height) / 2) * helper.step;
	while (++helper.y < ray->line_end)
	{
		helper.texture_y = (int_fast32_t)helper.texture_pos
			& (helper.texture_size - 1);
		helper.texture_pos += helper.step;
		helper.px_dst = (uint32_t *)&main->image->pixels[(helper.y
				* main->image->width + x) * sizeof(uint8_t) * 4];
		helper.px_src = (uint32_t *)&main->textures[ray->side]->\
		pixels[(helper.texture_size
				* helper.texture_y + ray->texture_x) * sizeof(uint8_t) * 4];
		*helper.px_dst = *helper.px_src;
	}
}
