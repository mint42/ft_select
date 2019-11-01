/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_item.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 23:34:57 by rreedy            #+#    #+#             */
/*   Updated: 2019/11/01 01:21:00 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_ITEM_H
# define STRUCT_ITEM_H

# include <stdint.h>

struct			s_item
{
	char		*name;
	uint32_t	len;
	uint32_t	active_prev;
	uint32_t	active_next;
	uint32_t	finder_prev;
	uint32_t	finder_next;
	uint8_t		status;
};

void			init_items(struct s_item *items, struct s_format *format,
					int argc, char **argv);

#endif
