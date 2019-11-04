/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_format.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 23:32:39 by rreedy            #+#    #+#             */
/*   Updated: 2019/10/31 23:42:55 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_INFO_H
# define STRUCT_INFO_H

# include <stdint.h>

struct			s_info
{
	uint32_t	term_width;
	uint32_t	term_height;
	uint32_t	max_name_len;
	uint32_t	col_width;
	uint8_t		columns;
	uint8_t		rows;
	uint8_t		cursor_position;
};

void			setup_info(struct s_info *info);

#endif