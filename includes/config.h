/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 04:08:56 by rreedy            #+#    #+#             */
/*   Updated: 2019/11/20 10:15:02 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_H
# define CONFIG_H

/*
**	Adjust the space between the agruments printed in Select Mode
*/

# define COLUMN_PADDING 4

/*
**	This determines how much padding there is between the edge of the
**	terminal and the box's border.
*/

# define OUTER_PAD_WIDTH 2
# define OUTER_PAD_HEIGHT 1

/*
**	This determines how much padding there is between the box's border and the
**	text.
*/

# define INNER_PAD_WIDTH 2
# define INNER_PAD_HEIGHT 1

/*
**	OUTPUT_PADDING_CHAR pads the returned output by any ascii character. The
**	amount of this character can be adjusted with OUTPUT_PADDING_LEN.
*/

# define OUTPUT_PADDING_CHAR ' '
# define OUTPUT_PADDING_LEN 1

/*
**	TRUNCATE_STRING will print at the end of an argument that is too large to
**	be displayed in the given width.
*/

# define TRUNCATE_STRING "..."
# define TRUNCATE_STRING_LEN 3

/*
**	A second set of key supports.  Primary key supports live in
**	includes/actions.h and should remain untouched in order to avoid undefined
**	behavior. The numbers shown should be configured to the value for the key
**	you would like to press for that action. Multibyte keys are supported.
**	This set will not be shown in Help Mode.
*/

# define K_SEC_LEFT 0x68
# define K_SEC_DOWN 0x6A
# define K_SEC_UP 0x6B
# define K_SEC_RIGHT 0x6C
# define K_SEC_SELECT 0
# define K_SEC_SELECT_ALL 0
# define K_SEC_DELETE 0x7E335B1B
# define K_SEC_DELETE_ALL 0
# define K_SEC_RESORE 0
# define K_SEC_UNDO 0
# define K_SEC_RETURN 0
# define K_SEC_QUIT 0x1B
# define K_SEC_HELP 0

#endif
