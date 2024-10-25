/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 19:34:53 by kklockow          #+#    #+#             */
/*   Updated: 2024/10/24 18:40:59 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*ft_strerror(int_fast32_t error_code)
{
	char	*error_messages[17];

	error_messages[0] = "No error";
	error_messages[1] = "Unable to allocate memory";
	error_messages[2] = "Wrong amount of arguments (only map filepath)";
	error_messages[3] = "Wrong file format (use .cub)";
	error_messages[4] = "Unable to open map file";
	error_messages[5] = "Unable to close map file";
	error_messages[6] = "Type is empty";
	error_messages[7] = "All types have to be set in mapfile";
	error_messages[8] = "No map layout found (should be at end of file)";
	error_messages[9] = "Wrong character in map layout";
	error_messages[10] = "Empty line in map layout";
	error_messages[11] = "Map is not closed by walls";
	error_messages[12] = "No player position found";
	error_messages[13] = "Types cant be set twice";
	error_messages[14] = "Garbage found in mapfile";
	error_messages[15] = "Colors not set correctly";
	error_messages[16] = "Map file is to large";
	return (error_messages[error_code]);
}

void	print_ft_error_message(int_fast32_t error_code)
{
	ft_putstr_fd(ft_strerror(error_code), STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
}

void	print_mlx_error_message(void)
{
	ft_putstr_fd((char *)mlx_strerror(mlx_errno), STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
}

void	print_error_message(int_fast32_t error_code)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	if (error_code == (int_fast32_t)mlx_errno)
		print_mlx_error_message();
	else
		print_ft_error_message(error_code);
}

void	error_exit(t_main *main, int_fast32_t error_code)
{
	print_error_message(error_code);
	free_structs(main);
	exit(error_code);
}
