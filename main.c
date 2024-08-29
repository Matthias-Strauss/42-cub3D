/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kklockow <kklockow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 16:36:14 by kklockow          #+#    #+#             */
/*   Updated: 2024/08/29 18:55:19 by kklockow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_error_message(int error_code)
{
	printf("Error\n");
	if (error_code == ERR_UAM_C)
		printf(ERR_UAM_M);
	if (error_code == ERR_WAA_C)
		printf(ERR_WAA_M);
	if (error_code == ERR_WFF_C)
		printf(ERR_WFF_M);
	if (error_code == ERR_UOF_C)
		printf(ERR_UOF_M);
	if (error_code == ERR_UCF_C)
		printf(ERR_UCF_M);
	if (error_code == ERR_TIE_C)
		printf(ERR_TIE_M);
	if (error_code == ERR_TNS_C)
		printf(ERR_TNS_M);
}

void	error_exit(t_main *main, int error_code)
{
	free_structs(main);
	print_error_message(error_code);
	exit (error_code);
}

int	main(int ac, char **av)
{
	t_main	*main;

	main = init_structs();
	parse_arguments(ac, av, main);
	free_structs(main);
	return (0);
}
