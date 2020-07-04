NAME=ft_select
CFILE=main.c two_side_list.c draw.c support.c select_args.c
OFILE=$(CFILE:%.c=%.o)
CC= gcc -Iincludes/ -Iincludes/libft/includes -g
VPATH= . src/ includes/ includes/libft includes/libft/includes includes/libft/hash_table
LIB=libft.a
LIB_PATH=includes/libft/


all: $(NAME)

$(NAME): $(LIB) $(OFILE)
	$(CC) $(LIB_PATH)$(LIB) $(OFILE) -o $(NAME)
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