/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_arg.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 22:33:29 by rreedy            #+#    #+#             */
/*   Updated: 2019/11/09 20:30:44 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_ARG_H
# define STRUCT_ARG_H

# include <stdint.h>

# define ACTIVE 0
# define INACTIVE 1
# define SELECTED 2

# define SET_ARGS 1
# define GET_ARGS 2

struct			s_arg
{
	char		*name;
	uint32_t	len;
	uint32_t	coordinate;
	uint32_t	active_prev;
	uint32_t	active_next;
	uint32_t	finder_prev;
	uint32_t	finder_next;
	uint32_t	inactive_group_id;
	uint8_t		status;
};

int				setup_args(struct s_arg **args, uint32_t *max_arg_len, int argc,
					char **argv);
void			hold_args(struct s_arg **args, uint8_t action);

#endif
