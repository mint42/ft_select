/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_term.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 22:33:37 by rreedy            #+#    #+#             */
/*   Updated: 2019/11/13 08:09:27 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_TERM_H
# define STRUCT_TERM_H

# include <termios.h>
# include <stdint.h>

# define SET_TERM 1
# define GET_TERM 2

# define TERM_BUFF_SIZE 2048

struct				s_term
{
	char			term_buffer[TERM_BUFF_SIZE];
	struct termios	old_settings;
	struct termios	new_settings;
};

void				hold_term(struct s_term **term, uint8_t action);
int					setup_term(struct s_term *term);
int					restore_term(struct s_term *term);

#endif
