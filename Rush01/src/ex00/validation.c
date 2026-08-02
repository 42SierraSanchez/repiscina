/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asierra <asierra@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 09:59:27 by asierra-          #+#    #+#             */
/*   Updated: 2026/08/02 10:44:11 by asierra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	count_visible_row_left(int tab[4][4], int row);
int	count_visible_row_right(int tab[4][4], int row);
int	count_visible_col_bottom(int tab[4][4], int col);
int	count_visible_col_top(int tab[4][4], int col);

int	is_row_valid(int tab[4][4], int pos)
{
	int	i;

	i = (pos % 4) - 1;
	while (i >= 0)
	{
		if (tab[pos / 4][pos % 4] == tab[pos / 4][i])
			return (0);
		i--;
	}
	return (1);
}

int	is_col_valid(int tab[4][4], int pos)
{
	int	i;

	i = (pos / 4) - 1;
	while (i >= 0)
	{
		if (tab[pos / 4][pos % 4] == tab[i][pos % 4])
			return (0);
		i--;
	}
	return (1);
}

int	validate_row_clues(int tab[4][4], int row, int *clues)
{
	if (!(count_visible_row_left(tab, row) == clues[8 + row]))
		return (0);
	if (!(count_visible_row_right(tab, row) == clues[12 + row]))
		return (0);
	return (1);
}

int	validate_col_clues(int tab[4][4], int col, int *clues)
{
	if (!(count_visible_col_top(tab, col) == clues[col]))
		return (0);
	if (!(count_visible_col_bottom(tab, col) == clues[4 + col]))
		return (0);
	return (1);
}

int	pos_is_valid(int tab[4][4], int pos, int *clues)
{
	if (!is_row_valid(tab, pos))
		return (0);
	if (!is_col_valid(tab, pos))
		return (0);
	if (pos / 4 == 3)
		if (!validate_col_clues(tab, pos % 4, clues))
			return (0);
	if (pos % 4 == 3)
		if (!validate_row_clues(tab, pos / 4, clues))
			return (0);
	return (1);
}
