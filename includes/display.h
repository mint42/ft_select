/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 04:09:06 by rreedy            #+#    #+#             */
/*   Updated: 2019/11/20 04:09:42 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAY_H
# define DISPLAY_H

# include <stdint.h>

struct s_info;
struct s_arg;

int		display_arg(struct s_arg *arg, uint32_t coord, struct s_info *info);
int		display_screen(struct s_info *info);

#endif
