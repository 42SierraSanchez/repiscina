/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   candidates.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asierra <asierra@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 12:00:00 by asierra           #+#    #+#             */
/*   Updated: 2026/08/02 12:00:00 by asierra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int	line_visibility(int *line, int size, int reverse)
{
	int	i;
	int	max;
	int	visible;

	i = 0;
	max = 0;
	visible = 0;
	while (i < size)
	{
		if (line[(size - 1) * reverse + (1 - 2 * reverse) * i] > max)
		{
			max = line[(size - 1) * reverse + (1 - 2 * reverse) * i];
			visible++;
		}
		i++;
	}
	return (visible);
}

int	candidate_fits(int *line, int *data)
{
	int	col;
	int	row;
	int	size;

	size = data[0];
	row = data[37];
	col = 0;
	while (col < size)
	{
		if (line[col] > size - data[1 + col] + row + 1)
			return (0);
		if (line[col] > 2 * size - data[1 + size + col] - row)
			return (0);
		col++;
	}
	return (1);
}

void	save_candidate(int *line, int *data)
{
	unsigned long long	encoded;
	int					views[2];
	int					row;
	int					i;

	row = data[37];
	views[0] = line_visibility(line, data[0], 0);
	views[1] = line_visibility(line, data[0], 1);
	if (views[0] != data[1 + 2 * data[0] + row]
		|| views[1] != data[1 + 3 * data[0] + row])
		return ;
	if (!candidate_fits(line, data))
		return ;
	encoded = 0;
	i = 0;
	while (i < data[0])
		encoded = (encoded << 4) | line[i++];
	store_candidate(row, encoded);
}

void	build_candidates(int *line, int pos, int used, int *data)
{
	int	value;

	if (pos == data[0])
	{
		save_candidate(line, data);
		return ;
	}
	value = data[0] - data[1 + data[39] * data[0] + pos]
		+ data[38] + 1;
	if (value > data[0])
		value = data[0];
	while (value >= 1)
	{
		if (!(used & (1 << value)))
		{
			line[pos] = value;
			build_candidates(line, pos + 1, used | (1 << value), data);
		}
		value--;
	}
}
