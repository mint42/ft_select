/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_format.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 23:30:49 by rreedy            #+#    #+#             */
/*   Updated: 2019/10/31 23:43:26 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct_format.h"

void	init_format(struct s_format *format)
{
	format->term_width = 0;
	format->term_height = 0;
	format->col_width = 0;
}
