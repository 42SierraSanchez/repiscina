/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asierra- <asierra-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/01 17:36:19 by asierra-          #+#    #+#             */
/*   Updated: 2026/08/01 17:48:04 by asierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


int	solve(int **tab, int *clues, int pos)
{
	int	try;

	try = 1;
	if (pos == 16)
		return (1);
	while (try <= 4)
	{
		tab[pos / 4][pos % 4] = try;
		if (pos_is_valid(tab, pos, clues))
			if (solve(tab, clues, pos + 1))
				return (1);
		tab[pos / 4][pos % 4] = 0;
		try++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int clues[16];
	int tab[4][4];

	if (argc != 2)
		return (0);
}