/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asierra <asierra@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 14:13:04 by asierra           #+#    #+#             */
/*   Updated: 2026/08/07 11:47:00 by asierra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_is_space(int c);
int		ft_strlen(char *str);
int		is_valid_base(char *base);
int		convert(char *str, char *base);
long	ft_atoi_base(char *str, char *base);

int	ft_base_number_len(long nbr, int base_len)
{
	int	len;

	len = 0;
	if (nbr < 0)
	{
		len++;
		nbr = -nbr;
	}
	while (nbr)
	{
		nbr /= base_len;
		len++;
	}
	return (len);
}

void	ft_fill_char(long nbr, char *base, int base_size, char *conversion)
{
	int	len;

	len = ft_base_number_len(nbr, base_size);
	conversion[len--] = '\0';
	if (nbr == 0)
	{
		conversion[0] = 0;
		return ;
	}
	if (nbr < 0)
	{
		nbr = -nbr;
		conversion[0] = '-';
	}
	while (len >= 0 && nbr)
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
	long	nbr_int;
	int		len;

	base_from_size = is_valid_base(base_from);
	base_to_size = is_valid_base(base_to);
	if (!base_from_size || !base_to_size)
		return (NULL);
	nbr_int = ft_atoi_base(nbr, base_from);
	len = ft_base_number_len(nbr_int, base_to_size);
	conversion = malloc(len + 1);
	if (!conversion)
		return (NULL);
	ft_fill_char(nbr_int, base_to, base_to_size, conversion);
	return (conversion);
}
