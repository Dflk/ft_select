/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaran <rbaran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 14:45:08 by rbaran            #+#    #+#             */
/*   Updated: 2016/06/02 17:23:50 by rbaran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H
# include <libft.h>
# include <termcap.h>
# include <term.h>
# include <curses.h>
# include <termios.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <signal.h>
# include <fcntl.h>
# include <sys/ioctl.h>
# define LEF 0x445B1B
# define RIG 0x435B1B
# define UP 0x415B1B
# define DO 0x425B1B
# define ESC 0x1B
# define SUP 0x7E335B1B
# define DEL 0x7F
# define UNDER_ON 1
# define UNDER_OFF 0
# define LIST 1
# define DISPLAY 0
# define HEADER_1 "   __ _              _           _\n"
# define HEADER_2 "  / _| |            | |         | |\n"
# define HEADER_3 " | |_| |_   ___  ___| | ___  ___| |_\n"
# define HEADER_4 " |  _| __| / __|/ _ \\ |/ _ \\/ __| __|\n"
# define HEADER_5 " | | | |_  \\__ \\  __/ |  __/ (__| |_ \n"
# define HEADER_6 " |_|  \\__| |___/\\___|_|\\___|\\___|\\__|\n"

typedef struct	s_output
{
	int	o_lines;
	int	o_cols;
	int	len_max;
	int	header;
	int	fd;
	int	o_total_cols;
}				t_output;

typedef struct	s_elems
{
	char			*data;
	short int		selected;
	int				posX;
	int				posY;
	int				map;
	struct s_elems	*next;
	struct s_elems	*prev;
}				t_elems;

t_elems		*ft_fillselect(int ac, char **av);
t_elems		*ft_findstart(t_elems *elems, int mode, int header);
int			ft_termios(int set);
int			ft_open(void);
t_output	*ft_managedisplay(t_elems *elems, int fd);
t_output	*ft_saveoutput(t_output *output);
void		ft_printconf(t_elems *begin_list, t_elems *elems, t_output *output);
void		ft_print(t_elems *elem, int underline, int fd);
int			ft_putchar_int(int c);
void		ft_set_positions(t_elems *elems, t_elems *beg_list, t_output *size_conf, int map);
void		ft_movecursor(int posX, int posY);
void		ft_underlinemode(int mode);
void		ft_clearscreen(void);
void		ft_savecursor(void);
void		ft_restorecursor(void);
void		ft_select(t_elems *elems, t_output *output);
void		ft_deleteelem(t_elems **elem, int header);

#endif
