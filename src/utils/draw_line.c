/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kklockow <kklockow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 18:59:05 by kklockow          #+#    #+#             */
/*   Updated: 2024/09/12 17:55:45 by kklockow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	set_x_and_y_values(t_point start, t_point end, t_line *line)
{
	line->x = (int)start.x;
	line->y = (int)start.y;
	line->x_end = (int)end.x;
	line->y_end = (int)end.y;
}

void	set_other_variables(t_line *line)
{
	line->x_diff = abs(line->x_end - line->x);
	line->y_diff = abs(line->y_end - line->y);
	line->x_step = 1;
	if (line->x > line->x_end)
		line->x_step = -1;
	line->y_step = 1;
	if (line->y > line->y_end)
		line->y_step = -1;
	line->error = line->x_diff - line->y_diff;
}

void	draw_line(t_point start, t_point end, t_main *main, int color)
{
	t_line	line;

	set_x_and_y_values(start, end, &line);
	set_other_variables(&line);
	while (1)
	{
		if (line.x >= 0 && line.y >= 0 && line.x < WIDTH && line.y < HEIGHT)
			mlx_put_pixel(main->image, line.x, line.y, color);
		if (line.x == line.x_end && line.y == line.y_end)
			break ;
		line.error2 = 2 * line.error;
		if (line.error2 > -line.y_diff)
		{
			line.error -= line.y_diff;
			line.x += line.x_step;
		}
		if (line.error2 < line.x_diff)
		{
			line.error += line.x_diff;
			line.y += line.y_step;
		}
	}
}
