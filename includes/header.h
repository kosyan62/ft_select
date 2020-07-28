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
# include <curses.h>
# include <term.h>

typedef struct	s_outputs
{
	char	tbuf[2048];
	char	strings[256];
	char	*p;
	char	*tname;
	char	*CL;
	char	*UL;
	char	*NORM;
	char	*RV;
	char	*VI;
	char	*VE;
	char	*HO;
	int		fd;
}				t_outputs;

typedef struct	s_selection
{
	char	*word;
	size_t 	len;
	bool	selected;
	bool	under_cursor;
	int		vert_pos;
	int 	hor_pos;
	struct s_selection *next;
	struct s_selection *prev;
}				t_selection;

t_selection		*add_doubly_list(t_selection *lst, char *word, size_t len);
void			fill_list_to_screen(t_selection *selection, int elem_fin_count);
void			move_cursor(t_selection **selection, const char key[4], t_outputs out);
int 			del_double_list_item(t_selection *lst);
void			del_whole_list(t_selection *lst);
char			*select_args(t_selection *selections, t_outputs out);
void			draw_selections(t_selection *selection, t_outputs out);
struct winsize	get_winsize(void);
void 			escape(t_outputs out);
void			tinit(t_outputs *out);
void 			clearscreen(void);
void			underline_text(void);
void			reverse_video_text(void);
void			normal_text(void);
void			invisible_cursor(void);
void			visible_cursor(void);

#endif //FT_SELECT_HEADER_H
