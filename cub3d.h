/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kklockow <kklockow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 17:20:01 by kklockow          #+#    #+#             */
/*   Updated: 2024/08/27 17:43:19 by kklockow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/include/MLX42/MLX42.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>

typedef struct s_parser
{
	char	*map_path_stack;
	char	*map_copy_heap;
	int		map_file_descriptor;
} t_parser;

typedef struct s_main
{
	t_parser *parser;
} t_main;

// Delete the relevant line from the . gitmodules file.
// Delete the relevant section from . git/config .
// Run git rm --cached path_to_submodule (no trailing slash).
// Commit and delete the now untracked submodule files.