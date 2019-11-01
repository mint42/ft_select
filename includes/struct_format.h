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

#ifndef STRUCT_FORMAT_H
# define STRUCT_FORMAT_H

# include <stdint.h>

struct			s_format
{
	uint32_t	term_width;
	uint32_t	term_height;
	uint32_t	max_name_len;
	uint32_t	col_width;
	uint8_t		columns;
	uint8_t		rows;
	uint8_t		cursor_position;
};

void			init_format(struct s_format *format);

#endif
