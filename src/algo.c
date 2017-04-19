/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/09 16:25:37 by baalbane          #+#    #+#             */
/*   Updated: 2016/10/15 16:04:43 by baalbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/filler.h"

int		choosepos(t_list *new, int x, int y)
{
	int		tmp;
	if (canbeplace(new, x, y) == 1)
	{
		tmp = getscore(new, x, y);
		if (tmp < new->best[0])
		{
			new->best[0] = tmp;
			new->best[1] = x;
			new->best[2] = y;
		}
	}
	if (x == -(new->px - 1) && y < new->mapy)
		choosepos(new, x, y + 1);
	if (x < new->mapx)
		choosepos(new, x + 1, y);
	return (1);
}

int		canbeplace(t_list *new, int x, int y)
{
	int		i;
	int		j;
	int		check;

	check = 0;
	i = -1;
	while (++i < new->py)
	{
		j = -1;
		while (++j < new->px)
		{
			if (new->piece[i][j] != '.')
			{
				if (checkcoord(new, x + j, y + i) == -1
				|| isenemy(new, x + j, y + i) >= 1)
					return (-1);
				if (isme(new, x + j, y + i) == 1)
					check++;
				if (check > 1)
					return (-1);
			}
		}
	}
	if (check != 1)
		return (-1);
	return (1);
}

int		checkcoord(t_list *new, int x, int y)
{
	if (x < 0 || x >= new->mapx || y < 0 || y >= new->mapy)
		return (-1);
	return (1);
}
