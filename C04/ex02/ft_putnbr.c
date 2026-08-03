/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asierra <asierra@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 16:44:02 by asierra           #+#    #+#             */
/*   Updated: 2026/08/04 00:47:15 by asierra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb)
{
	long int	lnb;
	char		c;

	lnb = nb;
	if (lnb < 0)
	{
		write(1, "-", 1);
		lnb = -lnb;
	}
	if (lnb >= 10)
	{
		ft_putnbr(lnb / 10);
	}
	c = lnb % 10 + '0';
	write(1, &c, 1);
}
