/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_info.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 22:33:32 by rreedy            #+#    #+#             */
/*   Updated: 2019/11/10 05:55:15 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_INFO_H
# define STRUCT_INFO_H

# include <stdint.h>

# define COLUMN_PADDING 4

# define SET_INFO 1
# define GET_INFO 2

struct s_arg;

struct				s_info
{
	struct s_arg	*args;
	uint32_t		n_active_args;
	uint32_t		starting_arg;
	uint32_t		cursor_arg;
	uint32_t		cursor_coord;
	uint32_t		max_arg_len;
	uint32_t		column_width;
	uint8_t			n_columns;
	uint8_t			n_rows;
};

void				hold_info(struct s_info **info, uint8_t action);
void				update_window_size(void);
int					setup_info(struct s_info *info, int argc, char **argv);

#endif
