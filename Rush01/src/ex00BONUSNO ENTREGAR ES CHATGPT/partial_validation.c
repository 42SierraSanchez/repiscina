/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   partial_validation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asierra <asierra@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 12:00:00 by asierra           #+#    #+#             */
/*   Updated: 2026/08/02 12:00:00 by asierra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int	largest_missing(int *line, int used, int size)
{
	int	seen[10];
	int	i;

	i = 0;
	while (i <= 9)
		seen[i++] = 0;
	i = 0;
	while (i < used)
	{
		seen[line[i]] = 1;
		i++;
	}
	while (size > 0 && seen[size])
		size--;
	return (size);
}

int	opposite_possible(int *line, int used, int clue, int size)
{
	int	i;
	int	max;
	int	bounds[2];

	max = largest_missing(line, used, size);
	bounds[0] = (used < size);
	bounds[1] = size - used;
	i = used - 1;
	while (i >= 0)
	{
		if (line[i] > max)
		{
			max = line[i];
			bounds[0]++;
			bounds[1]++;
		}
		i--;
	}
	return (clue >= bounds[0] && clue <= bounds[1]);
}

int	column_is_possible(int tab[9][9], int pos, int *clues, int size)
{
	int	column[9];
	int	used;
	int	col;
	int	i;
	int	reversed;

	used = pos / size + 1;
	col = pos % size;
	reversed = candidate_count(size - 1) < candidate_count(0);
	i = 0;
	while (i < used)
	{
		if (reversed)
			column[i] = tab[size - 1 - i][col];
		else
			column[i] = tab[i][col];
		i++;
	}
	if (!partial_visible(column, used, clues[reversed * size + col], size))
		return (0);
	return (opposite_possible(column, used,
			clues[(1 - reversed) * size + col], size));
}
