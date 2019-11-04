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

#include "struct_info.h"

void	setup_info(struct s_info *info)
{
	info->term_width = 0;
	info->term_height = 0;
	info->max_name_len = 0;
	info->col_width = 0;
	info->columns = 0;
	info->rows = 0;
	info->cursor_position = 0;
}
