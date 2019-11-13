/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 07:51:26 by rreedy            #+#    #+#             */
/*   Updated: 2019/11/13 08:46:46 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_H
# define CONFIG_H

/*
** Hexadecimal key codes for actions. These can be any multibye key
** combo. Repeated codes and missing primary and seconrary actions are
** considered user error
*/ 

# define OUTPUT_PADDING_CHAR ' '
# define OUTPUT_PADDING_LEN 1

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
# define K_SEC_SELECT 0
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

# define K_QUIT_HELP_MODE 0x1b

#endif
