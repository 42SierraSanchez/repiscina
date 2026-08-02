/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asierra <asierra@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 09:59:27 by asierra-          #+#    #+#             */
/*   Updated: 2026/08/02 12:00:00 by asierra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int	no_repetition(int tab[9][9], int row, int col, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (i != col && tab[row][col] == tab[row][i])
			return (0);
		i++;
	}
	i = 0;
	while (i < size)
	{
		if (i != row && tab[row][col] == tab[i][col])
			return (0);
		i++;
	}
	return (1);
}

int	partial_visible(int *line, int used, int clue, int size)
{
	int	i;
	int	max;
	int	visible;

	i = 0;
	max = 0;
	visible = 0;
	while (i < used)
	{
		if (line[i] > max)
		{
			max = line[i];
			visible++;
		}
		i++;
	}
	if (clue < visible + (max < size))
		return (0);
	if (clue > visible + size - max)
		return (0);
	return (1);
}
