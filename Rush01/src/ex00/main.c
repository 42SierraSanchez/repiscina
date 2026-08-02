/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asierra <asierra@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 09:59:12 by asierra-          #+#    #+#             */
/*   Updated: 2026/08/02 10:01:14 by asierra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	main(int argc, char **argv)
{
	int clues[16];
	int tab[4][4];

	if (argc != 2)
		    return(print_error());
    if (!valid_arg(argv[1]))
          	return(print_error());
	fill_clues(clues, argv[1]);
	init_tab(tab);
    if(!solve(tab, 0, clues))
            return(print_error());
    print_tab(tab);
	return (0);
}