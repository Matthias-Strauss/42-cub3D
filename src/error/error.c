/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kklockow <kklockow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 19:34:53 by kklockow          #+#    #+#             */
/*   Updated: 2024/08/29 19:47:34 by kklockow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	print_error_message(int error_code)
{
	write(STDERR_FILENO, "Error\n", 6);
	if (error_code == ERR_UAM_C)
		write(STDERR_FILENO, ERR_UAM_M, ft_strlen(ERR_UAM_M));
	if (error_code == ERR_WAA_C)
		write(STDERR_FILENO, ERR_WAA_M, ft_strlen(ERR_WAA_M));
	if (error_code == ERR_WFF_C)
		write(STDERR_FILENO, ERR_WFF_M, ft_strlen(ERR_WFF_M));
	if (error_code == ERR_UOF_C)
		write(STDERR_FILENO, ERR_UOF_M, ft_strlen(ERR_UOF_M));
	if (error_code == ERR_UCF_C)
		write(STDERR_FILENO, ERR_UCF_M, ft_strlen(ERR_UCF_M));
	if (error_code == ERR_TIE_C)
		write(STDERR_FILENO, ERR_TIE_M, ft_strlen(ERR_TIE_M));
	if (error_code == ERR_TNS_C)
		write(STDERR_FILENO, ERR_TNS_M, ft_strlen(ERR_TNS_M));
}

void	error_exit(t_main *main, int error_code)
{
	free_structs(main);
	print_error_message(error_code);
	exit (error_code);
}
