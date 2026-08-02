/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asierra <asierra@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 17:59:42 by asierra           #+#    #+#             */
/*   Updated: 2026/08/02 22:32:04 by asierra          ###   ########.fr       */
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
		if (base[i] == '+' || base[i] == '-')
			return (0);
		if ((base[i] >= 9 && base[i] <= 13) || base[i] == ' ')
			return (0);
		i++;
	}
	i = 0;
	j = 0;
	while (base[i])
	{
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

void	ft_print_nbr(int nbr, char *base, int count)
{
	long int	lnb;
	int			base_size;

	base_size = ft_strlen(base);
	lnb = nbr;
	if (lnb < 0)
	{
		write(1, "-", 1);
		lnb = -lnb;
	}
	if (lnb > 10)
	{
		ft_print_nbr(lnb / base_size, base, count + 1);
	}
	ft_putchar(base[lnb % base_size]);
}
void	ft_putnbr_base(int nbr, char *base)
{
	if (!(is_valid_base(base)))
		return ;
	ft_print_nbr(nbr, base, 0);
}
int	main(void)
{
	ft_putnbr_base(-1400, "0123456789");
	return (0);
}
