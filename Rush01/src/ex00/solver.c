/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asierra <asierra@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 09:59:24 by asierra-          #+#    #+#             */
/*   Updated: 2026/08/02 10:08:05 by asierra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	solve(int tab[4][4], int pos, int *clues)
{
	int	try;

	try = 1;
	if (pos == 16)
		return (1);
	while (try <= 4)
	{
		tab[pos / 4][pos % 4] = try;
		if (pos_is_valid(tab, pos, clues))
			if (solve(tab, pos + 1, clues))
				return (1);
		tab[pos / 4][pos % 4] = 0;
		try++;
	}
	return (0);
}

void	init_tab(int tab[4][4])
{
    int i;
    int j;
    
	i = 0;
	j = 0;
	while (i <= 3)
	{
		while (j <= 3)
		{
			tab[i][j] = 0;
			j++;
		}
        j = 0;
		i++;
	}
}