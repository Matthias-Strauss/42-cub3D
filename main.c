/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kklockow <kklockow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 16:36:14 by kklockow          #+#    #+#             */
/*   Updated: 2024/09/02 18:57:07 by kklockow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

int	next_comma(char *str, int start)
{
	while (str[start] && str[start] != ',')
		start++;
	return (start);
}

int	get_only_number(char *str, int start)
{
	char	*buffer;
	int		number;

	buffer = ft_substr(str, start, next_comma(str, start) - start);
	number = ft_atoi(buffer);
	printf("[%i]   [%s]\n", number, buffer);
	free(buffer);
	return (number);
}

int	convert_string_to_color(char *str)
{
	int		r;
	int		g;
	int		b;

	r = get_only_number(str, 0);
	g = get_only_number(str, next_comma(str, 0) + 1);
	b = get_only_number(str, next_comma(str, next_comma(str, 0) + 1) + 1);

	return (r << 24 | g << 16 | b << 8 | 100);
}

int	main(int ac, char **av)
{
	t_main	*main;
	mlx_t	*mlx;
	mlx_image_t	*image;

	main = init_structs();
	parse_arguments(ac, av, main);
	mlx = mlx_init(256, 256, "cub3d", false);
	image = mlx_new_image(mlx, 256, 256);
	int	color;

	color = convert_string_to_color(main->map_data->ceiling_color);
	for (int i = 0; i < 256; i++)
	{
		mlx_put_pixel(image, i, i, color);
		mlx_put_pixel(image, i + 1, i, color);
		mlx_put_pixel(image, i, i + 1, color);
	}
	mlx_image_to_window(mlx, image, 0, 0);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	free_structs(main);
	return (0);
}
