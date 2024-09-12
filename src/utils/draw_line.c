/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kklockow <kklockow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 18:59:05 by kklockow          #+#    #+#             */
/*   Updated: 2024/09/11 19:58:30 by kklockow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	draw_line(int x1, int y1, int x2, int y2, t_main *main, int color)
{
	int dx = abs(x2 - x1); // Calculate the difference in x
    int dy = abs(y2 - y1); // Calculate the difference in y

    int sx = (x1 < x2) ? 1 : -1; // Determine step direction for x
    int sy = (y1 < y2) ? 1 : -1; // Determine step direction for y

    int err = dx - dy; // Error term

    while (1)
	{
        if (x1 >= 0 && y1 >= 0 && x1 < WIDTH && y1 < HEIGHT)
			mlx_put_pixel(main->image, x1, y1, color); // Plot the current point
        // Check if we have reached the end point
        if (x1 == x2 && y1 == y2)
            break;

        int e2 = 2 * err;

        // Adjust x and error
        if (e2 > -dy) {
            err -= dy;
            x1 += sx;
        }

        // Adjust y and error
        if (e2 < dx) {
            err += dx;
            y1 += sy;
        }
    }
}

