/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tc.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 02:43:14 by rreedy            #+#    #+#             */
/*   Updated: 2019/11/10 03:35:21 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TC_H
# define TC_H

# include <stdint.h>

int		tc_move_cur(uint32_t x_pos, uint32_t y_pos);
int		tc_put(char *tc_id);

#endif