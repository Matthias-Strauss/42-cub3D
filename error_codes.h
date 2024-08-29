/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_codes.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kklockow <kklockow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 18:35:19 by kklockow          #+#    #+#             */
/*   Updated: 2024/08/29 18:57:14 by kklockow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define ERR_UAM_C	1
#define ERR_UAM_M	"Unable to allocate memory\n"

#define ERR_WAA_C	2
#define ERR_WAA_M	"Wrong amount of arguments (only 1)\n"

#define ERR_WFF_C	3
#define ERR_WFF_M	"Wrong File Format (use .cub)\n"

#define ERR_UOF_C	4
#define ERR_UOF_M	"Unable to close file\n"

#define ERR_UCF_C	5
#define ERR_UCF_M	"Unable to allocate memory\n"

#define ERR_TIE_C	6
#define ERR_TIE_M	"Type is empty\n"

#define ERR_TNS_C	7
#define ERR_TNS_M	"All types have to be set in mapfile\n"