# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgena <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/05 15:35:59 by mgena             #+#    #+#              #
#    Updated: 2020/07/22 15:55:49 by mgena            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include libft.mk

BUILD_DIR = build
BUILD_STATIC = $(BUILD_DIR)/static
BUILD_SHARED = $(BUILD_DIR)/shared


SRC_DIR = src

SRCS := $(shell find $(SRC_DIR) -name "*.c")
OBJS_STATIC := $(patsubst $(SRC_DIR)/%.c,$(BUILD_STATIC)/%.o,$(SRCS))
OBJS_SHARED := $(patsubst $(SRC_DIR)/%.c,$(BUILD_SHARED)/%.o,$(SRCS))

.PHONY: all clean fclean re

CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(LIBFT_TARGET)

# build static and shared libraries
$(LIBFT_TARGET): $(OBJS_STATIC)
	ar rcs $(LIBFT_TARGET) $(OBJS_STATIC)

$(LIBFT_SHARED_TARGET): $(OBJS_SHARED)
	$(CC) -shared -o $(LIBFT_SHARED_TARGET) $(OBJS_SHARED)

# for testing purposes
so: $(LIBFT_SHARED_TARGET)

# compile source files
$(BUILD_STATIC)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(sort $(dir $(OBJS_STATIC)))
	$(CC) $(CFLAGS) $(LIBFT_INC) -c $< -o $@

$(BUILD_SHARED)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(sort $(dir $(OBJS_SHARED)))
	$(CC) $(CFLAGS) $(LIBFT_INC) -nostartfiles -fPIC -c $< -o $@

# clean, fclean, and rebuild targets
re: fclean all

clean:
	rm -rf $(BUILD_DIR)

fclean: clean
	rm -rf $(LIBFT_TARGET) $(patsubst %.a,%.so,$(LIBFT_TARGET))

