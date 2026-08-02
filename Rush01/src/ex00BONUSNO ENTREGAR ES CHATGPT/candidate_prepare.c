/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   candidate_prepare.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asierra <asierra@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 12:00:00 by asierra           #+#    #+#             */
/*   Updated: 2026/08/02 12:00:00 by asierra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

void	find_direction(int *line, int *data)
{
	reset_candidates(data[0]);
	data[37] = 0;
	data[38] = 0;
	data[39] = 0;
	build_candidates(line, 0, 0, data);
	data[37] = data[0] - 1;
	data[39] = 1;
	build_candidates(line, 0, 0, data);
	data[39] = (candidate_count(data[0] - 1) < candidate_count(0));
}

void	prepare_candidates(int clues[36], int size)
{
	int	line[9];
	int	data[40];
	int	i;
	int	row;

	data[0] = size;
	i = 0;
	while (i < 4 * size)
	{
		data[i + 1] = clues[i];
		i++;
	}
	find_direction(line, data);
	reset_candidates(size);
	data[38] = 0;
	while (data[38] < size)
	{
		row = data[38];
		if (data[39])
			row = size - 1 - data[38];
		data[37] = row;
		build_candidates(line, 0, 0, data);
		data[38]++;
	}
}
