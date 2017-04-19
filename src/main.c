/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/09 16:26:37 by baalbane          #+#    #+#             */
/*   Updated: 2016/10/15 16:22:24 by baalbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/filler.h"

int		main(void)
{
	t_list	*new;

	if ((new = initlst()) == NULL)
		return (-1);
	while (1)
	{
		if (initmap(new) == -1)
			return (-1);
		if (initpiece(new) == -1)
			return (-1);
		if (choosepos(new, -(new->px - 1), -(new->py - 1)) == -1)
			return (-1);
		printcoord(new->best[2], new->best[1]);
		freelst(new);
	}
	free(new);
	return (0);
}
