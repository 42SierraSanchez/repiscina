/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asierra- <asierra-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/01 17:36:19 by asierra-          #+#    #+#             */
/*   Updated: 2026/08/01 19:43:05 by asierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	valid_chars(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!(str[i] == 32 || (str[i] >= 48 && str[i] <= 52)))
			return (1);
		i++;
	}
	return (0);
}

int	valid_length(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	if (i != 31)
		return (1);
	return (0);
}

int	valid_pos(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (i % 2 == 0)
		{
			if (!(str[i] >= 48 && str[i] <= 57))
				return (1);
		}
		else
		{
			if (str[i] != 32)
				return (1);
		}
		i++;
	}
	return (0);
}

int	valid_format(char *str)
{
	if (valid_chars(str))
		return (1);
	if (valid_length(str))
		return (1);
	if (valid_pos(str))
		return (1);
	return (0);
}

void	num_en_pos(int clues[16], char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] != '\0' && j < 16)
	{
		if (str[i] >= 48 && str[i] <= 57)
		{
			clues[j] = str[i] - '0';
			j++;
		}
		i++;
	}
}
/*
int	check_eq_arr(int *s1, int *s2)
{
	int	i;
	int	i;
	int	j;
	int	i;
	int	j;
	int	i;
	int	j;

	i = 0;
	while (i <= 3)
	{
		if (!(s1[i] == s2[i]))
		{
			return (0);
		}
		i++;
	}
	return (1);
}*/
void	print_tab(int tab[4][4])
{
    int i;
    int j;
    
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			ft_putchar(tab[i][j] - '0');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

int	pos_is_valid(int tab[4][4], int pos)
{
	if (!is_row_valid(tab, pos))
		return (0);
	if (!is_col_valid(tab, pos))
		return (0);
	// if (pos % 4 == 3)
	if (pos == 16)
		// if (!validate_clues(tab, pos))
		return (0);
	return (1);
}

int	solve(int tab[4][4], int pos)
{
	int	try;

	try = 1;
	if (pos == 16)
		return (1);
	while (try <= 4)
	{
		tab[pos / 4][pos % 4] = try;
		if (pos_is_valid(tab, pos))
			if (solve(tab, pos + 1))
				return (1);
		tab[pos / 4][pos % 4] = 0;
		try++;
	}
	return (0);
}
/* int	solve(int tab[4][4], int *clues, int pos)
{
	int	try;
	int	i;
	int	j;
	int	i;
	int	j;

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
} */
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
		i++;
	}
}
int	main(int argc, char **argv)
{
	int clues[16];
	int tab[4][4];

	if (argc != 2)
		return (0);

	num_en_pos(clues, argv[1]);
	init_tab(tab);
	printTab(tab);
	return (0);
}