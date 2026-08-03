/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asierra <asierra@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 17:59:42 by asierra           #+#    #+#             */
/*   Updated: 2026/08/04 00:49:33 by asierra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	is_valid_base(char *base)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (base[i])
	{
		if ((base[i] == '+' || base[i] == '-') || (base[i] >= 9
				&& base[i] <= 13))
			return (0);
		i++;
	}
	i = 0;
	j = 0;
	while (base[i])
	{
		j = 0;
		while (base[j])
		{
			if (base[i] == base[j] && i != j)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static void	ft_print_nb(int nbr, char *base, int base_size)
{
	long int	lnb;

	lnb = nbr;
	if (lnb < 0)
	{
		write(1, "-", 1);
		lnb = -lnb;
	}
	if (lnb >= base_size)
	{
		ft_print_nb(lnb / base_size, base, base_size);
	}
	ft_putchar(base[lnb % base_size]);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	base_size;

	if (ft_strlen(base) < 2 || !is_valid_base(base))
		return ;
	base_size = ft_strlen(base);
	ft_print_nb(nbr, base, base_size);
}
