/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asierra <asierra@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 14:13:04 by asierra           #+#    #+#             */
/*   Updated: 2026/08/06 19:59:15 by asierra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_is_space(int c);
int	ft_strlen(char *str);
int	is_valid_base(char *base);
int	convert(char *str, char *base);
int	ft_atoi_base(char *str, char *base);


static void	ft_fill_char(int nbr, char *base, int base_size)
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
		ft_fill_char(lnb / base_size, base, base_size);
	}
	ft_putchar(base[lnb % base_size]);
}

void	ft_putnbr_base(int nbr, char *base, char *conversion)
{
	int	base_size;

	if (ft_strlen(base) < 2 || !is_valid_base(base))
		return ;
	base_size = ft_strlen(base);
	ft_fill_char(nbr, base, base_size, conversion + 1);
}


char *ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char *conversion;
	int base_from_size;
	int base_to_size;
	int num; 

	base_from_size = is_valid_base(base_from)
	base_to_size = is_valid_base(base_to)
		if (!base_from_size || !base_to_size)
			return(NULL);
	ft_fill_char(num, base_to, conversion);
return(conversion);	
}