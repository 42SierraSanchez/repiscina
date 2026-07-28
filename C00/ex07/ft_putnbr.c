/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asierra <asierra@student.42malaga.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 14:01:50 by asierra           #+#    #+#             */
/*   Updated: 2026/07/26 03:34:39 by asierra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb)
{
	long int lnb;
	char c;
	
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
/*
int	main(void)
{
ft_putnbr(0);
write(1, "\n", 1);
ft_putnbr(-42);
write(1, "\n", 1);
ft_putnbr(2147483647);
write(1, "\n", 1);
ft_putnbr(-2147483648);
write(1, "\n", 1);
return(0);
}*/
