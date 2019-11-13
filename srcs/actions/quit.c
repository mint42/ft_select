/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 07:46:32 by rreedy            #+#    #+#             */
/*   Updated: 2019/11/13 07:46:51 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errors.h"
#include "actions.h"
#include "struct_info.h"
#include "struct_arg.h"

int		action_quit(struct s_info *info)
{
	(void)info;
	return (BREAK);
}
