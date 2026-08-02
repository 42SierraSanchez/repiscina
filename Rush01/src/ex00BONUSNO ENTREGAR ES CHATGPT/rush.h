/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asierra <asierra@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 12:00:00 by asierra           #+#    #+#             */
/*   Updated: 2026/08/02 12:00:00 by asierra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH_H
# define RUSH_H

int		print_error(void);
int		valid_arg(char *str, int *size);
void	fill_clues(int clues[36], char *str);
void	init_tab(int tab[9][9]);
int		solve(int tab[9][9], int pos, int clues[36], int size);
void	print_tab(int tab[9][9], int size);
void	prepare_candidates(int clues[36], int size);
void	build_candidates(int *line, int pos, int used, int *data);
void	reset_candidates(int size);
void	store_candidate(int row, unsigned long long encoded);
int		candidate_count(int row);
void	put_candidate(int tab[9][9], int row, int candidate, int size);

int		count_visible_row_left(int tab[9][9], int row, int size);
int		count_visible_row_right(int tab[9][9], int row, int size);
int		count_visible_col_bottom(int tab[9][9], int col, int size);
int		count_visible_col_top(int tab[9][9], int col, int size);
int		partial_visible(int *line, int used, int clue, int size);
int		opposite_possible(int *line, int used, int clue, int size);
int		column_is_possible(int tab[9][9], int pos, int *clues, int size);
int		no_repetition(int tab[9][9], int row, int col, int size);

#endif
