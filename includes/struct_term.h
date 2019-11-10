/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_term.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 22:33:37 by rreedy            #+#    #+#             */
/*   Updated: 2019/11/09 21:58:13 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_TERM_H
# define STRUCT_TERM_H

# include <termios.h>

# define SET_SETTINGS 1
# define GET_SETTINGS 2

struct				s_term
{
	char			*term_buffer;
	struct termios	new_settings;
};

int					setup_term(struct s_term *term);
int					reset_term(void);

#endif
