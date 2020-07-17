//
// Created by Maxon Gena on 16/03/2020.
//

#ifndef FT_SELECT_HEADER_H
# define FT_SELECT_HEADER_H

# include "libft.h"
# include <unistd.h>
# include <fcntl.h>
# include <termios.h>
# include <sys/ioctl.h>
# include <stdbool.h>

typedef struct	s_selection
{
	char	*word;
	size_t 	len;
	bool	selected;
	bool	under_cursor;
	bool	displayed;
	struct s_selection *next;
	struct s_selection *prev;
}				t_selection;

t_selection		*add_doubly_list(t_selection *lst, char *word, size_t len);
void			move_cursor(t_selection **selection, const char key[4]);
void			del_double_list_item(t_selection *lst);
char			**select_args(t_selection *selections);
void			draw_selections(t_selection *selection);
struct winsize	get_winsize(void);
void			restart_term();
void 			escape();

#endif //FT_SELECT_HEADER_H
