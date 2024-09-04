/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_codes.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kklockow <kklockow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 18:35:19 by kklockow          #+#    #+#             */
/*   Updated: 2024/09/04 17:41:44 by kklockow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define ERR_UAM	1 // "Unable to allocate memory\n"

#define ERR_WAA	2 // "Wrong amount of arguments (only map filepath)\n"

#define ERR_WFF	3 // "Wrong file format (use .cub)\n"

#define ERR_UOF	4 // "Unable to open map file\n"

#define ERR_UCF	5 // "Unable to close map file\n"

#define ERR_TIE	6 // "Type is empty\n"

#define ERR_TNS	7 // "All types have to be set in mapfile\n"

#define ERR_NMF	8 // "No map layout found (should be at end of file)\n"

#define ERR_WCF	9 // "Wrong character in map layout\n"

#define ERR_ELM	10 // "Empty line in map layout\n"

#define ERR_NCW	11 // "Map is not closed by walls\n"

#define ERR_NPF	12 // "No player position found\n"

#define ERR_TCR	13 // "Types cant be set twice\n"

#define ERR_GFM	14 // "Garbage found in mapfile\n"

#define ERR_CNC	15 // "Colors not set correctly\n"

#define ERR_MTL	16 // "Map file is to large\n"