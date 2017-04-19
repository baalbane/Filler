/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printtool.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/09 16:26:11 by baalbane          #+#    #+#             */
/*   Updated: 2016/10/15 16:07:09 by baalbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/filler.h"

int		ft_putnbr(int nb)
{
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		return (ft_putchar(nb % 10 + '0'));
	}
	ft_putchar(nb + '0');
	return (1);
}

int		ft_putchar(char a)
{
	write(1, &a, 1);
	return (1);
}

int		printcoord(int a, int b)
{
	ft_putnbr(a);
	ft_putchar(' ');
	ft_putnbr(b);
	ft_putchar('\n');
	return (1);
}
