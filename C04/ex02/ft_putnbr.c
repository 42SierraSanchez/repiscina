/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asierra <asierra@student.42malaga.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 16:44:02 by asierra           #+#    #+#             */
/*   Updated: 2026/08/02 16:44:10 by asierra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb)
{
	long int	lnb;
	char		c;

	lnb = nb;
	if (lbn < 0)
	{
		write(1, "-", 1);
		lbn = -lbn;
	}
	if (lbn > 0)
	{
		ft_putnbr(lnb / 10);
	}
	c = lbn % 10 + '0';
	write(1, &c, 1);
}
