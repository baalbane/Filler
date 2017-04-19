/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/09 16:26:53 by baalbane          #+#    #+#             */
/*   Updated: 2016/10/15 16:07:52 by baalbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include <unistd.h>
# include <stdlib.h>

# define BUFF_SIZE 50

typedef	struct		s_list
{
	char			player;
	int				mapx;
	int				mapy;
	int				px;
	int				py;
	int				best[3];
	char			**map;
	char			**piece;
}					t_list;


int					main(void);

t_list				*initlst(void);
int					freelst(t_list *new);

int					isenemy(t_list *new, int x, int y);
int					isme(t_list *new, int x, int y);
char				*ft_strchr(char *str, char a);
int					ft_strlen(char *str);

int					getscore(t_list *new, int x, int y);
int					fitin(t_list *new, int x, int y);
int					getcloser(t_list *new, int x, int y);
int					getdist(int x, int y, int x2, int y2);
int					vabs(int x);

int					choosepos(t_list *new, int x, int y);
int					canbeplace(t_list *new, int x, int y);
int					checkcoord(t_list *new, int x, int y);

int					initmap(t_list *new);
int					takemap(t_list *new);
int					initpiece(t_list *new);
int					takepiece(t_list *new);

int					ft_putnbr(int nb);
int					ft_putchar(char a);
int					printcoord(int a, int b);

int					ft_strlenchr(char *buffer, int a);
int					saveline(char *buffer, char **line, char **buf);
char				*ft_strjoin2(char *str, char *str2);
int					addbuff(char **buffer, int const fd, int *ret);
int					get_next_line(int const fd, char **line);

#endif
