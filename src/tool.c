/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/09 16:26:45 by baalbane          #+#    #+#             */
/*   Updated: 2016/10/15 16:07:36 by baalbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/filler.h"

int		isenemy(t_list *new, int x, int y)
{
	if ((new->player == 'O'	&& new->map[y][x] == 'X')
	|| (new->player == 'X'	&& new->map[y][x] == 'O'))
		return (1);
	if ((new->player == 'O'	&& new->map[y][x] == 'x')
	|| (new->player == 'X'	&& new->map[y][x] == 'o'))
		return (2);
	return (0);
}

int		isme(t_list *new, int x, int y)
{
	if (new->map[y][x] == new->player
	|| new->map[y][x] == new->player + 32)
		return (1);
	return (0);
}

char	*ft_strchr(char *str, char a)
{
	while (*str != '\0' && *str != a)
		str++;
	if (*str == a)
		return (str);
	return (NULL);
}

int		ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
