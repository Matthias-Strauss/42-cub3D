/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_codes.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kklockow <kklockow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 18:35:19 by kklockow          #+#    #+#             */
/*   Updated: 2024/09/04 16:18:49 by kklockow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define ERR_UAM_C	1
#define ERR_UAM_M	"Unable to allocate memory\n"

#define ERR_WAA_C	2
#define ERR_WAA_M	"Wrong amount of arguments (only map filepath)\n"

#define ERR_WFF_C	3
#define ERR_WFF_M	"Wrong file format (use .cub)\n"

#define ERR_UOF_C	4
#define ERR_UOF_M	"Unable to open map file\n"

#define ERR_UCF_C	5
#define ERR_UCF_M	"Unable to close map file\n"

#define ERR_TIE_C	6
#define ERR_TIE_M	"Type is empty\n"

#define ERR_TNS_C	7
#define ERR_TNS_M	"All types have to be set in mapfile\n"

#define ERR_NMF_C	8
#define ERR_NMF_M	"No map layout found (should be at end of file)\n"

#define ERR_WCF_C	9
#define ERR_WCF_M	"Wrong character in map layout\n"

#define ERR_ELM_C	10
#define ERR_ELM_M	"Wrong character in map layout\n"

#define ERR_NCW_C	11
#define ERR_NCW_M	"Map is not closed by walls\n"

#define ERR_NPF_C	12
#define ERR_NPF_M	"No player position found\n"

#define ERR_TCR_C	13
#define ERR_TCR_M	"Types cant be set twice\n"

#define ERR_GFM_C	14
#define ERR_GFM_M	"Garbage found in mapfile\n"

#define ERR_CNC_C	15
#define ERR_CNC_M	"Colors not set correctly\n"

#define ERR_MTL_C	16
#define ERR_MTL_M	"Map file is to large\n"