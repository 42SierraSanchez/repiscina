/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asierra <asierra@student.42malaga.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 01:32:08 by asierra           #+#    #+#             */
/*   Updated: 2026/07/27 22:23:54 by asierra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int	temp;
	int	i;
	int	j;

	i = 0;
	j = size - 1;
	while (i < j)
	{
		temp = tab[j];
		tab[j] = tab[i];
		tab[i] = temp;
		i++;
		j--;
	}
}
/*
int	main(void)
{
	int	size;
	int	tab[10] = {3, 1, 7, 8, 6, 5, 4, 0, 9, 2};
	int	i;

	size = 10;
	for (i = 0; i < size; i++)
		printf("%d ", tab[i]);
	printf("\n");
	ft_rev_int_tab(tab, size);
	for (i = 0; i < size; i++)
		printf("%d ", tab[i]);
	printf("\n");
	return (0);
}
*/
