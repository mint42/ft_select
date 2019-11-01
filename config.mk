# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    config.mk                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rreedy <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/22 09:39:36 by rreedy            #+#    #+#              #
#    Updated: 2019/11/01 01:55:43 by rreedy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := ft_select

LIBFT_NAME := libft.a
LIBFT_DIR := ./libft
LIBFT_MAKEFILE := Makefile
LIBS := ft
LIBS += termcap
LIB_DIRS := $(LIBFT_DIR)
LIB_INCLUDE_DIRS := $(LIBFT_DIR)/includes
LIB_INCLUDE_DIRS += $(LIBFT_DIR)/includes/ft_printf

SRC_DIRS := ./srcs
INCLUDE_DIRS := ./includes

CC := gcc
CFLAGS := -g
CFLAGS += -Wall
CFLAGS += -Wextra
CFLAGS += -Werror
CFLAGS += $(foreach include,$(INCLUDE_DIRS),-I$(include)) $(foreach lib_include,$(LIB_INCLUDE_DIRS),-I$(lib_include))
LDFLAGS := $(foreach local_lib,$(LIB_DIRS),-L$(local_lib)) $(foreach lib,$(LIBS),-l$(lib))
