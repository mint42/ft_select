/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   box_drawing.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 06:03:58 by rreedy            #+#    #+#             */
/*   Updated: 2019/11/15 06:35:55 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BOX_DRAWING_H
# define BOX_DRAWING_H

# include "config.h"
# include <stdint.h>

# define BOX_DRAWING_CHAR_SIZE 3
# define BUILT_IN_WIDTH 1
# define BUILT_IN_HEIGHT 3
# define TOTAL_PAD_WIDTH OUTER_PAD_WIDTH + INNER_PAD_WIDTH + BUILT_IN_WIDTH
# define TOTAL_PAD_HEIGHT OUTER_PAD_HEIGHT + INNER_PAD_HEIGHT + BUILT_IN_HEIGHT

struct s_info;

int		draw_box(struct s_info *info, uint8_t mode);

#endif
