/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asierra <asierra@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 09:59:12 by asierra-          #+#    #+#             */
/*   Updated: 2026/08/02 10:39:27 by asierra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int	main(int argc, char **argv)
{
	int	clues[36];
	int	tab[9][9];
	int	size;

	if (argc != 2)
		return (print_error());
	if (!valid_arg(argv[1], &size))
		return (print_error());
	fill_clues(clues, argv[1]);
	init_tab(tab);
	prepare_candidates(clues, size);
	if (!solve(tab, 0, clues, size))
		return (print_error());
	print_tab(tab, size);
	return (0);
}
