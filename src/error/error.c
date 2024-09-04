/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kklockow <kklockow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 19:34:53 by kklockow          #+#    #+#             */
/*   Updated: 2024/09/04 16:38:45 by kklockow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

char	*error_messages(int error_code)
{
	char	*error_messages[17];

	error_messages[0] = "No error\n";
	error_messages[1] = "Unable to allocate memory\n";
	error_messages[2] = "Wrong amount of arguments (only map filepath)\n";
	error_messages[3] = "Wrong file format (use .cub)\n";
	error_messages[4] = "Unable to open map file\n";
	error_messages[5] = "Unable to close map file\n";
	error_messages[6] = "Type is empty\n";
	error_messages[7] = "All types have to be set in mapfile\n";
	error_messages[8] = "No map layout found (should be at end of file)\n";
	error_messages[9] = "Wrong character in map layout\n";
	error_messages[10] = "Empty line in map layout\n";
	error_messages[11] = "Map is not closed by walls\n";
	error_messages[12] = "No player position found\n";
	error_messages[13] = "Types cant be set twice\n";
	error_messages[14] = "Garbage found in mapfile\n";
	error_messages[15] = "Colors not set correctly\n";
	error_messages[16] = "Map file is to large\n";
	return (error_messages[error_code]);
}

void	print_error_message_parser(int error_code)
{
	ft_putstr_fd(error_messages(error_code), STDERR_FILENO);
}

void	print_mlx_error_message(void)
{
	ft_putstr_fd((char *)mlx_strerror(mlx_errno), STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
}

void	print_error_message(int error_code)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	if (error_code == (int)mlx_errno)
	{
		print_mlx_error_message();
	}
	if (error_code == errno)
	{
		ft_putstr_fd((char *)strerror(errno), STDERR_FILENO);
		ft_putstr_fd("\n", STDERR_FILENO);
	}
	else
	{
		print_error_message_parser(error_code);
	}
}

void	error_exit(t_main *main, int error_code)
{
	free_structs(main);
	print_error_message(error_code);
	exit (error_code);
}
