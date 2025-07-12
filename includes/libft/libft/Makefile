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

all: setup $(TARGET_STATIC) $(TARGET_SHARED)

# create build directories if they do not exist
setup:
	@mkdir -p $(sort $(dir $(OBJS_STATIC)))
	@mkdir -p $(sort $(dir $(OBJS_SHARED)))


# build static and shared libraries
$(TARGET_STATIC): $(OBJS_STATIC)
	ar rcs $(TARGET_STATIC) $(OBJS_STATIC)

$(TARGET_SHARED): $(OBJS_SHARED)
	$(CC) -shared -o $(TARGET_SHARED) $(OBJS_SHARED)

# compile source files
$(BUILD_STATIC)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(LIBFT_INC) -c $< -o $@

$(BUILD_SHARED)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(LIBFT_INC) -nostartfiles -fPIC -c $< -o $@

# clean, fclean, and rebuild targets
re: fclean all

so: $(TARGET_SHARED) # for testing purposes

clean:
	rm -rf $(BUILD_DIR)

fclean: clean
	rm -rf $(TARGET_STATIC) $(TARGET_SHARED)

