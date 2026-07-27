/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asierra <asierra@student.42malaga.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 20:11:10 by asierra           #+#    #+#             */
/*   Updated: 2026/07/26 03:42:26 by asierra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_kji(int k, int j, int i)
{
	char	c[3];

	c[0] = k + '0';
	c[1] = j + '0';
	c[2] = i + '0';
	write(1, &c, 3);
	write(1, ", ", 2);
}

void	ft_print_comb(void)
{
	int		k;
	int		j;
	int		i;

	k = 0;
	while (k < 7)
	{
		j = k + 1;
		while (j < 9)
		{
			i = j + 1;
			while (i < 10)
			{
				ft_print_kji(k, j, i);
				i++;
			}
			j++;
		}
		k++;
	}
	write(1, "789", 3);
}
/*
int main(void)
{
	
ft_print_comb();
return(0);
}*/
