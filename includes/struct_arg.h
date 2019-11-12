/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_arg.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 22:33:29 by rreedy            #+#    #+#             */
/*   Updated: 2019/11/10 02:33:50 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_ARG_H
# define STRUCT_ARG_H

# include <stdint.h>

# define DELETED 0
# define SELECTED 1
# define UNSELECTED 2

struct s_info;

struct			s_arg
{
	char		*name;
	uint32_t	len;
	uint32_t	active_prev;
	uint32_t	active_next;
	uint32_t	finder_prev;
	uint32_t	finder_next;
	uint32_t	delete_group_id;
	uint8_t		status;
};

int				setup_args(struct s_info *info, char **argv);

#endif
