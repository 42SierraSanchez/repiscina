/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asierra <asierra@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 14:13:04 by asierra           #+#    #+#             */
/*   Updated: 2026/08/07 10:53:21 by asierra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_is_space(int c);
int		ft_strlen(char *str);
int		is_valid_base(char *base);
int		convert(char *str, char *base);
int		ft_atoi_base(char *str, char *base);

int	ft_base_number_len(int nbr, char *base)
{
	int		len;
	long	lnb;

	lnb = nbr;
	len = 1;
	if (lnb < 0)
	{
		len++;
		lnb = -lnb;
	}
	while (lnb /= 10)
		len++;
	return (len);
}

void	ft_fill_char(int nbr, char *base, int base_size, char *conversion)
{
	int	len;

	len = ft_base_number_len(nbr, base);
	conversion[len--] = '\0';
	while (len)
	{
		conversion[len] = base[nbr % base_size];
		nbr /= base_size;
		len--;
	}
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char	*conversion;
	int		base_from_size;
	int		base_to_size;
	int		nbr_int;
	int		len;

	nbr_int = ft_atoi_base(nbr, base_from);
	len = ft_base_number_len(nbr_int, base_to);
	conversion = malloc(len);
	if (!conversion)
		return ("ERROR");
	base_from_size = is_valid_base(base_from);
	base_to_size = is_valid_base(base_to);
	if (!base_from_size || !base_to_size)
		return (NULL);
	ft_fill_char(nbr_int, base_to, base_to_size, conversion);
	return (conversion);
}
