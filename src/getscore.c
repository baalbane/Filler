/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getscore.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/09 16:25:50 by baalbane          #+#    #+#             */
/*   Updated: 2016/10/15 16:05:29 by baalbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/filler.h"

int		getscore(t_list *new, int x, int y)
{
	int		i;
	int		j;
	int		score;

	score = 0;
	i = -1;
	while (++i < new->py)
	{
		j = -1;
		while (++j < new->px)
		{
			if (new->piece[i][j] == '*')
			{
				score += getcloser(new, x+j, y+i);
				score -= fitin(new, x+j, y+i);
			}
		}
	}
	return (score);
}

int		fitin(t_list *new, int x, int y)
{
	int		count;

	count = 1;
	if (y >= 0 && x-1 > 0 && new->map[y][x-1] != '.')
		count++;
	if (x >= 0 && y-1 > 0 && new->map[y-1][x] != '.')
		count++;
	if (y >= 0 && x >= 0 && x+1 < new->mapx && new->map[y][x+1] != '.')
		count++;
	if (x >= 0 && y >= 0 && y+1 < new->mapy && new->map[y][y+1] != '.')
		count++;
	return (count * 10);
}

int		getcloser(t_list *new, int x, int y)
{
	int		i;
	int		j;
	int		best;
	int		tmp;

	best = 420420;
	i = -1;
	while (++i < new->mapy)
	{
		j = -1;
		while (++j < new->mapx)
		{
			if (isenemy(new, j, i) == 1
			&& (tmp = getdist(x, y, j, i) * 10) < best)
				best = tmp;
			else if (isenemy(new, j, i) == 2
			&& (tmp = getdist(x, y, j, i) * 2) < best)
				best = tmp;
		}
	}
	return (best);
}

int		getdist(int x, int y, int x2, int y2)
{
	return (vabs(x - x2) + vabs(y - y2));
}

int		vabs(int x)
{
	return (x < 0 ? -x : x);
}





















