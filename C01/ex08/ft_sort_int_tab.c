/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asierra <asierra@student.42malaga.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 22:26:59 by asierra           #+#    #+#             */
/*   Updated: 2026/07/27 23:08:14 by asierra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

void	ft_sort_int_tab(int *tab, int size)
{
	int	temp;
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < size)
	{
		while (i < size - 1 - j)
		{
			if (tab[i] > tab[i + 1])
			{
				temp = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = temp;
			}
			i++;
		}
		i = 0;
		j++;
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
	ft_sort_int_tab(tab, size);
	for (i = 0; i < size; i++)
		printf("%d ", tab[i]);
	printf("\n");
	return (0);
}*/
