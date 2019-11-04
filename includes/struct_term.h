/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 01:24:05 by rreedy            #+#    #+#             */
/*   Updated: 2019/11/01 01:25:01 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_TERM_H
# define STRUCT_TERM_H

# include <termios.h>

struct				s_term
{
	char			*term_buffer;
	struct termios	old_settings;
	struct termios	new_settings;
};

int		setup_terminal(struct s_term *term);
int		reset_terminal(struct s_term *term);

#endif
