# Makefile for linking with the libft library

LIBFT_PATH := $(realpath $(dir $(realpath $(lastword $(MAKEFILE_LIST)))))

LIBFT_TARGET = libft.a
LIBFT_SHARED_TARGET = libft.so

LIBFT_INC_DIR = $(LIBFT_PATH)/includes

LIBFT_INC = -I $(LIBFT_INC_DIR)
LIBFT_LNK = -L $(LIBFT_PATH) -lft
LIBFT_LIB = $(LIBFT_PATH)/$(LIBFT_TARGET)