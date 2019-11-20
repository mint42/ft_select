/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   box_drawing.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 06:19:51 by rreedy            #+#    #+#             */
/*   Updated: 2019/11/20 06:19:55 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BOX_DRAWING_H
# define BOX_DRAWING_H

# include "config.h"
# include <stdint.h>

# define BOX_DRAWING_CHAR_SIZE 3

struct s_info;

int		draw_box(struct s_info *info, uint8_t mode);

#endif
