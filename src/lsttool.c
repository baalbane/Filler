/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lsttool.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/09 16:26:01 by baalbane          #+#    #+#             */
/*   Updated: 2016/10/15 16:06:20 by baalbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/filler.h"

t_list		*initlst(void)
{
	t_list	*new;
	char	*line;

	if ((new = malloc(sizeof(t_list))) == NULL)
		return (NULL);
	get_next_line(0, &line);
	if (line[10] == '1')
		new->player = 'O';
	else
		new->player = 'X';
	free(line);
	return (new);
}

int			freelst(t_list *new)
{
	int		i;

	i = -1;
	while (++i < new->mapy)
		free(new->map[i]);
	free(new->map);
	i = -1;
	while (++i < new->py)
		free(new->piece[i]);
	free(new->piece);
	return (1);
}
