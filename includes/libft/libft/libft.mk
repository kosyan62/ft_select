# Makefile for linking with the libft library

LIBFT_PATH := $(realpath $(dir $(realpath $(lastword $(MAKEFILE_LIST)))))

TARGET_STATIC = libft.a
TARGET_SHARED = libft.so


LIBFT_INC_DIR = $(LIBFT_PATH)/includes

LIBFT_INC = -I $(LIBFT_INC_DIR)
LIBFT_LNK = -L $(LIBFT_PATH) -lft -static
LIBFT_LIB = $(LIBFT_PATH)/$(TARGET_STATIC)