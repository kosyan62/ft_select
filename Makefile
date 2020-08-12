NAME=ft_select
CFILE=cursor.c draw.c init_and_signals.c main.c select_args.c support_1.c support_2.c termcap_extra.c two_side_list.c
OFILE=$(CFILE:%.c=%.o)
CC= gcc -Wall -Wextra -Werror -Iincludes/ -Iincludes/libft/ -g
VPATH= . src/ includes/ includes/libft includes/libft/includes includes/libft/hash_table
LIB=libft.a
LIB_PATH=includes/libft/


all: $(NAME)

$(NAME): $(LIB) $(OFILE)
	$(CC) $(LIB_PATH)$(LIB) $(OFILE) -o $(NAME) -ltermcap
%.o: %.c
	$(CC) -I$(LIB_PATH)$(LIB) -c $< -o $@
$(LIB):
	$(MAKE) -C $(LIB_PATH)
clean:
	rm -f $(OFILE)
	@make -C $(LIB_PATH) clean
fclean: clean
	rm -f $(NAME)
	@make -C $(LIB_PATH) fclean
norm: $(NAME)
	norminette */**.c */**.h
re: fclean all