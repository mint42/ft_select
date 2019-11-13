/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 07:51:18 by rreedy            #+#    #+#             */
/*   Updated: 2019/11/13 07:52:45 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ACTIONS_H
# define ACTIONS_H

# include "config.h"
# include <stdint.h>

struct s_info;

static const uint64_t	g_action_codes[] = {
	K_PRI_LEFT,
	K_SEC_LEFT,
	K_PRI_DOWN,
	K_SEC_DOWN,
	K_PRI_UP,
	K_SEC_UP,
	K_PRI_RIGHT,
	K_SEC_RIGHT,
	K_PRI_SELECT,
	K_SEC_SELECT,
	K_PRI_SELECT_ALL,
	K_SEC_SELECT_ALL,
	K_PRI_DELETE,
	K_SEC_DELETE,
	K_PRI_DELETE_ALL,
	K_SEC_DELETE_ALL,
	K_PRI_RESORE,
	K_SEC_RESORE,
	K_PRI_UNDO,
	K_SEC_UNDO,
	K_PRI_RETURN,
	K_SEC_RETURN,
	K_PRI_QUIT,
	K_SEC_QUIT,
	K_PRI_HELP,
	K_SEC_HELP,
};

int		action_left(struct s_info *info);
int		action_down(struct s_info *info);
int		action_up(struct s_info *info);
int		action_right(struct s_info *info);
int		action_select(struct s_info *info);
int		action_select_all(struct s_info *info);
int		action_delete(struct s_info *info);
int		action_delete_all_selected(struct s_info *info);
int		action_restore(struct s_info *info);
int		action_undo(struct s_info *info);
int		action_return(struct s_info *info);
int		action_quit(struct s_info *info);
int		action_help_mode(struct s_info *info);
int		action_search_mode(struct s_info *info);

#endif
