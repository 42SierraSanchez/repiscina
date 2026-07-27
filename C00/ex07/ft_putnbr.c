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

int	count_digits(long nb)
{
	int	count;

	count = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
		nb *= -1;
	while (nb)
	{
		nb /= 10;
		count++;
	}
	return (count);
}

void	fill_buffer(int i, char *buffer, long lnb)
{
	if (i < 0)
		return ;
	buffer[i] = lnb % 10 + '0';
	fill_buffer(i - 1, buffer, lnb / 10);
}

void	ft_putnbr(int nb)
{
	int		count;
	long	lnb;
	int		i;
	char	buffer[11];

	lnb = nb;
	count = count_digits(lnb);
	if (lnb < 0)
	{
		write(1, "-", 1);
		lnb *= -1;
	}
	fill_buffer(count - 1, buffer, lnb);
	i = 0;
	while (i < count)
	{
		write(1, &buffer[i], 1);
		i++;
	}
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
