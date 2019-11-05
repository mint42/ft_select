/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_arg.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 22:33:29 by rreedy            #+#    #+#             */
/*   Updated: 2019/11/04 22:43:27 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_ARG_H
# define STRUCT_ARG_H

# include <stdint.h>

# define ACTIVE 0
# define INACTIVE 1
# define SELECTED 2

struct s_info;

struct			s_arg
{
	char		*name;
	uint32_t	len;
	uint32_t	x_pos;
	uint32_t	y_pos;
	uint32_t	active_prev;
	uint32_t	active_next;
	uint32_t	finder_prev;
	uint32_t	finder_next;
	uint32_t	delete_group;
	uint8_t		status;
};

int				setup_args(struct s_arg **args, struct s_info *info, int argc,
					char **argv);

#endif
