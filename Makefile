include includes/libft/libft/libft.mk

NAME=ft_select

SRC_DIR = src
SRCS := $(shell find $(SRC_DIR) -name "*.c")


BUILD_DIR = build
OBJS := $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRCS))

INC = -I includes $LIBFT_INC

CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: setup $(NAME)

setup:
	@mkdir -p $(sort $(dir $(OBJS)))

$(NAME): $(LIBFT_LIB) $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBFT_LNK)

$(LIBFT_LIB):
	@make -C $(LIBFT_PATH)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR)
	@make -C $(LIBFT_PATH) clean

fclean: clean
	rm -f $(NAME)
	@make -C $(LIBFT_PATH) fclean

re: fclean all

.PHONY: clean fclean re setup all
