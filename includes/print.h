/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 05:23:46 by rreedy            #+#    #+#             */
/*   Updated: 2019/11/10 06:46:16 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_H
# define PRINT_H

# include <stdint.h>

struct s_info;
struct s_arg;

void	print_string(struct s_arg *arg, uint32_t coord, struct s_info *info);
int		print_screen(struct s_info *info);

#endif
