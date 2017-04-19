/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/09 16:26:29 by baalbane          #+#    #+#             */
/*   Updated: 2016/10/15 16:21:31 by baalbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/filler.h"

int		initmap(t_list *new)
{
	char	*line;
	int		i;

	i = 8;
	new->mapx = 0;
	new->mapy = 0;
	if (get_next_line(0, &line) != 1 || ft_strlen(line) < 12)
		return (-1);
	while (line[i] >= '0' && line[i] <= '9')
		new->mapy = new->mapy * 10 + line[i++] - '0';
	i++;
	while (line[i] >= '0' && line[i] <= '9')
		new->mapx = new->mapx * 10 + line[i++] - '0';
	free(line);
	if (new->mapx < 1 || new->mapy < 1 || takemap(new) == -1)
		return (-1);
	return (1);
}

int		takemap(t_list *new)
{
	char	*line;
	int		i;
	int		x;

	if ((new->map = malloc(sizeof(char*) * new->mapy)) == NULL)
		return (-1);
	if (get_next_line(0, &line) != 1)
		return (-1);
	free(line);
	i = -1;
	while (++i < new->mapy && get_next_line(0, &line) == 1
	&& ft_strlen(line) == new->mapx + 4)
	{
		x = -1;
		if ((new->map[i] = malloc(sizeof(char) * (new->mapx + 1))) == NULL)
			return (-1);
		new->map[i][new->mapx] = '\0';
		while (++x < new->mapx)
			new->map[i][x] = line[x + 4];
		free(line);
	}
	if (i == new->mapy)
		return (1);
	return (-1);
}

int		initpiece(t_list *new)
{
	char	*line;
	int		i;

	i = 6;
	new->px = 0;
	new->py = 0;
	if (get_next_line(0, &line) != 1 || ft_strlen(line) < 10)
		return (-1);
	while (line[i] >= '0' && line[i] <= '9')
		new->py = new->py * 10 + line[i++] - '0';
	i++;
	while (line[i] >= '0' && line[i] <= '9')
		new->px = new->px * 10 + line[i++] - '0';
	free(line);
	if (new->px < 1 || new->py < 1 || takepiece(new) == -1)
		return (-1);
	new->best[0] = 4204200;
	return (1);
}

int		takepiece(t_list *new)
{
	char	*line;
	int		i;
	int		x;

	if ((new->piece = malloc(sizeof(char*) * new->py)) == NULL)
		return (-1);
	i = -1;
	while (++i < new->py && get_next_line(0, &line) == 1
	&& ft_strlen(line) == new->px)
	{
		x = -1;
		if ((new->piece[i] = malloc(sizeof(char) * (new->px + 1))) == NULL)
			return (-1);
		new->piece[i][new->px] = '\0';
		while (++x < new->px)
			new->piece[i][x] = line[x];
		free(line);
	}
	if (i == new->py)
		return (1);
	return (-1);
}
