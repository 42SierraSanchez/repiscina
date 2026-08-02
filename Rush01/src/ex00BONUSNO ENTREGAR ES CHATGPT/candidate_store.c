/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   candidate_store.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asierra <asierra@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 12:00:00 by asierra           #+#    #+#             */
/*   Updated: 2026/08/02 12:00:00 by asierra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

unsigned long long	g_candidates[9][41000];
int					g_candidate_counts[9];

void	reset_candidates(int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		g_candidate_counts[i] = 0;
		i++;
	}
}

void	store_candidate(int row, unsigned long long encoded)
{
	g_candidates[row][g_candidate_counts[row]] = encoded;
	g_candidate_counts[row]++;
}

int	candidate_count(int row)
{
	return (g_candidate_counts[row]);
}

void	put_candidate(int tab[9][9], int row, int candidate, int size)
{
	unsigned long long	encoded;
	int					col;

	encoded = g_candidates[row][candidate];
	col = size - 1;
	while (col >= 0)
	{
		tab[row][col] = encoded & 15;
		encoded >>= 4;
		col--;
	}
}
