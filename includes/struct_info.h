/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_info.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 22:33:32 by rreedy            #+#    #+#             */
/*   Updated: 2019/11/20 05:28:20 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_INFO_H
# define STRUCT_INFO_H

# include "help.h"
# include <stdint.h>

# define SET_INFO 1
# define GET_INFO 2

# define SELECT_MODE 1
# define HELP_MODE 2

# define FALSE 0
# define TRUE 1

# define BUILTIN_WIDTH 1
# define BUILTIN_HEIGHT 3
# define TOTAL_PAD_WIDTH (OUTER_PAD_WIDTH + INNER_PAD_WIDTH + BUILTIN_WIDTH)
# define TOTAL_PAD_HEIGHT (OUTER_PAD_HEIGHT + INNER_PAD_HEIGHT + BUILTIN_HEIGHT)
# define TOTAL_MIN_WIDTH ((TOTAL_PAD_WIDTH * 2) + HELP_MENU_WIDTH)
# define TOTAL_MIN_HEIGHT ((TOTAL_PAD_HEIGHT * 2) + HELP_MENU_HEIGHT)

struct s_arg;

struct				s_info
{
	uint8_t			screen_mode;
	uint8_t			screen_too_small;
	struct s_arg	*args;
	uint32_t		n_args;
	uint32_t		n_active_args;
	uint32_t		starting_arg;
	uint32_t		cursor_arg;
	uint32_t		cursor_coord;
	uint32_t		max_delete_group_id;
	uint32_t		max_arg_len;
	uint32_t		term_width;
	uint32_t		term_height;
	uint32_t		screen_width;
	uint32_t		screen_height;
	uint32_t		column_width;
	uint32_t		n_columns;
	uint32_t		n_rows;
	uint32_t		n_selected_args;
	uint32_t		s_len;
	char			*selected;
};

void				hold_info(struct s_info **info, uint8_t action);
void				find_new_max_arg_len(struct s_info *info);
int					update_window_size(struct s_info *info);
int					setup_info(struct s_info *info, int argc, char **argv);

#endif
