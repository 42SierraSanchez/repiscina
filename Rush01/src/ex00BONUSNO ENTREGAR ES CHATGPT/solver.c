/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asierra <asierra@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 09:59:24 by asierra-          #+#    #+#             */
/*   Updated: 2026/08/02 12:00:00 by asierra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int	columns_are_possible(int tab[9][9], int step, int *clues, int size)
{
	int	col;
	int	row;

	row = step;
	if (candidate_count(size - 1) < candidate_count(0))
		row = size - 1 - step;
	col = 0;
	while (col < size)
	{
		if (!no_repetition(tab, row, col, size))
			return (0);
		if (!column_is_possible(tab, step * size + col, clues, size))
			return (0);
		col++;
	}
	return (1);
}

void	clear_row(int tab[9][9], int row, int size)
{
	int	col;

	col = 0;
	while (col < size)
	{
		tab[row][col] = 0;
		col++;
	}
}

int	greatest_common_divisor(int a, int b)
{
	int	remainder;

	while (b != 0)
	{
		remainder = a % b;
		a = b;
		b = remainder;
	}
	return (a);
}

void	init_order(int order[4], int row, int *clues, int size)
{
	int	i;

	order[0] = candidate_count(row);
	order[1] = 0;
	order[2] = row + size;
	i = 0;
	while (i < 4 * size)
	{
		order[2] = (order[2] * 31 + clues[i]) % order[0];
		i++;
	}
	order[3] = 7919 % order[0];
	if (order[3] < 1)
		order[3] = 1;
	while (greatest_common_divisor(order[3], order[0]) != 1)
		order[3]++;
}

int	solve(int tab[9][9], int step, int clues[36], int size)
{
	int	candidate;
	int	row;
	int	order[4];

	if (step == size)
		return (1);
	row = step;
	if (candidate_count(size - 1) < candidate_count(0))
		row = size - 1 - step;
	if (candidate_count(row) == 0)
		return (0);
	init_order(order, row, clues, size);
	while (order[1] < order[0])
	{
		candidate = (order[2] + order[1] * order[3]) % order[0];
		put_candidate(tab, row, candidate, size);
		if (columns_are_possible(tab, step, clues, size))
		{
			if (solve(tab, step + 1, clues, size))
				return (1);
		}
		order[1]++;
	}
	clear_row(tab, row, size);
	return (0);
}
