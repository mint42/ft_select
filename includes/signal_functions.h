/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 23:30:43 by rreedy            #+#    #+#             */
/*   Updated: 2019/11/20 23:32:03 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNAL_FUNCTIONS_H
# define SIGNAL_FUNCTIONS_H

void		restore_and_exit(int sig);
void		resize(int sig);
void		run_in_background(int sig);
void		run_in_foreground(int sig);

#endif
