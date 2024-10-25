/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 18:06:39 by mstrauss          #+#    #+#             */
/*   Updated: 2024/10/25 19:47:18 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// // @brief Calculates the RGBA value
// /// @param r red value,   0 - 255
// /// @param g green value, 0 - 255
// /// @param b blue value,  0 - 255
// /// @param a opacity,     0 - 255
// /// @return RGBA value
// inline static int	get_rgb(int r, int g, int b, int a)
// {
// 	return (r << 24 | g << 16 | b << 8 | a);
// }

/// @brief Calculates all possible color values
/// @param main data struct
void	pre_calc_colors(t_main *main)
{
	static uint32_t	i = 0;
	static uint32_t	j = 126;
	double			tmp;

	while (i <= 254 / 2)
	{
		tmp = (double)i / (254 / 2);
		main->colors[i * 4] = (int)(127.5 * (1.0 + sin(2.0 * M_PI * tmp
						/ 3.0)));
		main->colors[i * 4 + 1] = (int)(127.5 * (1.0 + sin(2.0 * M_PI * tmp
						/ 3.0 + 2.0 * M_PI / 3.0)));
		main->colors[i * 4 + 2] = (int)(127.5 * (1.0 + sin(2.0 * M_PI * tmp
						/ 3.0 + 4.0 * M_PI / 3.0)));
		main->colors[i * 4 + 3] = 255;
		i++;
	}
	while (i < 254)
	{
		main->colors[i * 4] = main->colors[j * 4];
		main->colors[i * 4 + 1] = main->colors[j * 4 + 1];
		main->colors[i * 4 + 2] = main->colors[j * 4 + 2];
		main->colors[i * 4 + 3] = main->colors[j * 4 + 3];
		i++;
		j--;
	}
}
