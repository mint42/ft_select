/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 17:21:48 by rreedy            #+#    #+#             */
/*   Updated: 2019/11/20 06:15:45 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCREEN_H
# define SCREEN_H

struct s_info;

int		wipe_screen(void);
int		update_screen(struct s_info *info);
int		setup_screen(void);
int		restore_screen(void);

#endif
