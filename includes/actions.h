
#ifndef ACTIONS_H
# define ACTIONS_H

# include <stdint.h>

# define TOTAL_ACTION_CODES 25
# define K_PRI_LEFT 0x445B1B
# define K_SEC_LEFT 0x68
# define K_PRI_DOWN 0x425B1B
# define K_SEC_DOWN 0x6A
# define K_PRI_UP 0x415B1B
# define K_SEC_UP 0x6B
# define K_PRI_RIGHT 0x435B1B
# define K_SEC_RIGHT 0x6C
# define K_PRI_SELECT 0x20
# define K_SEC_SELECT 0x20
# define K_PRI_SELECT_ALL 0x61
# define K_SEC_SELECT_ALL 0
# define K_PRI_DELETE 0x08
# define K_SEC_DELETE 0x7F
# define K_PRI_DELETE_ALL 0x44
# define K_SEC_DELETE_ALL 0
# define K_PRI_RESORE 0x72
# define K_SEC_RESORE 0
# define K_PRI_UNDO 0x75
# define K_SEC_UNDO 0
# define K_PRI_RETURN 0x0A
# define K_SEC_RETURN 0
# define K_PRI_QUIT 0x71
# define K_SEC_QUIT 0x1B
# define K_PRI_HELP 0x3F
# define K_SEC_HELP 0

# define K_QUIT_HELP_MODE 0x1B

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
