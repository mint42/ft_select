/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   box_drawing.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 06:19:51 by rreedy            #+#    #+#             */
/*   Updated: 2019/11/20 23:39:05 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BOX_DRAWING_H
# define BOX_DRAWING_H

# include <stdint.h>

struct s_info;

int		draw_box(struct s_info *info, uint8_t mode);

#endif
