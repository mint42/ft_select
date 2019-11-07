/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_info.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 22:33:32 by rreedy            #+#    #+#             */
/*   Updated: 2019/11/04 22:33:43 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_INFO_H
# define STRUCT_INFO_H

# include <stdint.h>

# define COLUMN_PADDING 4

struct s_arg;

struct				s_info
{
	struct s_arg	*args;
	uint32_t		n_args;
	uint32_t		terminal_width;
	uint32_t		terminal_height;
	uint32_t		max_arg_len;
	uint32_t		column_width;
	uint8_t			n_columns;
	uint8_t			n_rows;
	uint8_t			cursor_coordinate;
};

int					setup_info(struct s_info *info, int argc, char **argv);

#endif
