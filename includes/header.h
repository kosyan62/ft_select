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
# include <term.h>
# include <sys/stat.h>

bool flag;

typedef struct	s_outputs
{
	struct termios	savetty;
	char			tbuf[2048];
	char			strings[256];
	char			*p;
	char			*tname;
	char			*CL;
	char			*CD;
	char			*UL;
	char			*NORM;
	char			*RV;
	char			*VI;
	char			*VE;
	char			*HO;
	char			*RC;
	char			*SC;
	char			*ND;
	char			*DO;
	int				fd;
}				t_outputs;

typedef struct	s_selection
{
	char	*word;
	int 	len;
	mode_t	filetype;
	bool	selected;
	bool	under_cursor;

	int		vert_pos;
	int 	hor_pos;
	struct s_selection *next;
	struct s_selection *prev;
}				t_selection;

t_selection		*add_doubly_list(t_selection *lst, char *word, size_t len);
int 			del_double_list_item(t_selection *lst);
char			*select_args(t_selection *selections, t_outputs out);
void			delete_elem(t_selection **selection, t_outputs out);
void			draw_selections();
struct winsize	get_winsize(void);
void 			escape(t_outputs out);
void			tinit(t_outputs *out);
t_selection		*selection_storage(t_selection *obj);
t_outputs		out_storage(t_outputs *obj);
mode_t			get_filetype(char *word);
t_selection *get_under_cursor(t_selection **selection);
void 	move_cursor_up(t_selection **selection, t_outputs out);
void 	move_cursor_down(t_selection **selection, t_outputs out);
void 	move_cursor_left(t_selection **selection, t_outputs out);
void 	move_cursor_right(t_selection **selection, t_outputs out);
void return_tty(t_outputs out);
t_outputs 	main_init();
void		sighandler(int sig);
void		init_signals(void);

#endif //FT_SELECT_HEADER_H
