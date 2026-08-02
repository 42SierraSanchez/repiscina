/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visibility.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asierra <asierra@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 09:59:30 by asierra-          #+#    #+#             */
/*   Updated: 2026/08/02 10:47:53 by asierra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int	count_visible_row_left(int tab[9][9], int row, int size)

{
	int	i;
	int	count;
	int	max;

	i = 0;
	count = 0;
	max = 0;
	while (i < size)
	{
		if (tab[row][i] > max)
		{
			max = tab[row][i];
			count++;
		}
		i++;
	}
	return (count);
}

int	count_visible_row_right(int tab[9][9], int row, int size)

{
	int	i;
	int	count;
	int	max;

	i = size - 1;
	count = 0;
	max = 0;
	while (i >= 0)
	{
		if (tab[row][i] > max)
		{
			max = tab[row][i];
			count++;
		}
		i--;
	}
	return (count);
}

int	count_visible_col_bottom(int tab[9][9], int col, int size)

{
	int	i;
	int	count;
	int	max;

	i = size - 1;
	count = 0;
	max = 0;
	while (i >= 0)
	{
		if (tab[i][col] > max)
		{
			max = tab[i][col];
			count++;
		}
		i--;
	}
	return (count);
}

int	count_visible_col_top(int tab[9][9], int col, int size)

{
	int	i;
	int	count;
	int	max;

	i = 0;
	count = 0;
	max = 0;
	while (i < size)
	{
		if (tab[i][col] > max)
		{
			max = tab[i][col];
			count++;
		}
		i++;
	}
	return (count);
}
