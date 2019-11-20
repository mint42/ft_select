/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 04:08:42 by rreedy            #+#    #+#             */
/*   Updated: 2019/11/20 04:09:42 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ACTIONS_H
# define ACTIONS_H

# define TOTAL_ACTIONS 13

# define N_ACTION_CONFIGS 2

# define K_PRI_LEFT 0x445B1B
# define K_PRI_DOWN 0x425B1B
# define K_PRI_UP 0x415B1B
# define K_PRI_RIGHT 0x435B1B
# define K_PRI_SELECT 0x20
# define K_PRI_SELECT_ALL 0x61
# define K_PRI_DELETE 0x08
# define K_PRI_DELETE_ALL 0x44
# define K_PRI_RESORE 0x72
# define K_PRI_UNDO 0x75
# define K_PRI_RETURN 0x0A
# define K_PRI_QUIT 0x71
# define K_PRI_HELP 0x3F

struct s_info;

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
