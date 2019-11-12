/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_info.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 22:33:32 by rreedy            #+#    #+#             */
/*   Updated: 2019/11/10 06:52:08 by rreedy           ###   ########.fr       */
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
	uint32_t		max_delete_group_id;
	uint32_t		max_arg_len;
	uint32_t		column_width;
	uint32_t		n_columns;
	uint32_t		n_rows;
	uint32_t		n_selected_args;
	uint32_t		s_len;
	char			*selected;
};

void				hold_info(struct s_info **info, uint8_t action);
int					update_window_size(struct s_info *info);
int					setup_info(struct s_info *info, int argc, char **argv);

#endif
