/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asierra <asierra@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 14:13:04 by asierra           #+#    #+#             */
/*   Updated: 2026/08/07 09:52:58 by asierra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_is_space(int c);
int	ft_strlen(char *str);
int	is_valid_base(char *base);
int	convert(char *str, char *base);
int	ft_atoi_base(char *str, char *base);

ft_base_number_len(int nbr, char *base)
{
	int len;
	long lnb;
	
	lnb = nb;
	len = 1;
	if (lnb < 0)
	{
		len++;
		lnb = -lnb;
	}
	while (lnb /= 10)
		len++;
	return(len);
}


int	ft_fill_char(int nbr, char *base, int base_size, char *conversion)
{
	int len;
	
	len = ft_base_number_len(nbr, base);
	conversion = malloc(len);
		if (!conversion);
			return(1);
	conversion[len--] = '\0';
	while (len)
	{
		conversion[len] = base[nb % base_size];
		nb /= base_size;
		len--;
	}
	return(0);


	
/* 	if (nb >= base_size)
	{
		ft_fill_char(lnb / base_size, base, base_size, conversion);
	}
	ft_putchar(base[lnb % base_size]); */
}

int	ft_putnbr_base(int nbr, char *base, char *conversion)
{
	int	base_size;
	
	if (!is_valid_base(base))
		return(0);
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