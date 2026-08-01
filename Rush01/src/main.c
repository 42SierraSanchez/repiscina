/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asierra- <asierra-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/01 17:36:19 by asierra-          #+#    #+#             */
/*   Updated: 2026/08/01 22:02:49 by asierra-         ###   ########.fr       */
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
	while (str[i])
	{
		if (!(str[i] == 32 || (str[i] >= '1' && str[i] <= '4')))
			return (0);
		i++;
	}
	return (1);
}

int	valid_length(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	if (i != 31)
		return (0);
	return (1);
}

int	valid_pos(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (i % 2 == 0)
		{
			if (!(str[i] >= '1' && str[i] <= '4'))
				return (0);
		}
		else
		{
			if (str[i] != 32)
				return (0);
		}
		i++;
	}
	return (1);
}

int	valid_arg(char *str)
{
	if (!valid_chars(str))
		return (0);
	if (!valid_length(str))
		return (0);
	if (!valid_pos(str))
		return (0);
	return (1);
}

void	fill_clues(int clues[16], char *str)
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
			ft_putchar(tab[i][j] + '0');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}
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
int	count_visible_row_left(int tab[4][4], int row)

{
	int i;
	int count;
	int max;
	i = 0;
	count = 0;
	max = 0;
	while (i < 4)
	{
		if (tab[row][i] > max)
		{
			max = tab[row][i];
			count++;
		}
		i++;
	}
	return (count);
}

int	count_visible_row_right(int tab[4][4], int row)

{
	int i;
	int count;
	int max;
	i = 3;
	count = 0;
	max = 0;
	while (i >= 0)
	{
		if (tab[row][i] > max)
		{
			max = tab[row][i];
			count++;
		}
		i--;
	}
	return (count);
}

int	count_visible_col_bottom(int tab[4][4], int col)

{
	int i;
	int count;
	int max;
	i = 3;
	count = 0;
	max = 0;
	while (i >= 0)
	{
		if (tab[i][col] > max)
		{
			max = tab[i][col];
			count++;
		}
		i--;
	}
	return (count);
}
int	count_visible_col_top(int tab[4][4], int col)

{
	int i;
	int count;
	int max;
	i = 0;
	count = 0;
	max = 0;
	while (i < 4)
	{
		if (tab[i][col] > max)
		{
			max = tab[i][col];
			count++;
		}
		i++;
	}
	return (count);
}

int	validate_col_clues(int tab[4][4], int row, int *clues)
{
    int i;
    i = 0;
    while (i < 3)
	{
        if (!(count_visible_row_top(tab, row) == clues[i + 8]))
            return(0);
        if (!(count_visible_row_bottom(tab, row) == clues[i + 12]))
            return(0);
        i++;
    }
}
int	validate_col_clues(int tab[4][4], int col, int *clues)
{
    int i;
    i = 0;
    while (i < 3)
	{
        if (!(count_visible_col_top(tab, col) == clues[i]))
            return(0);
        if (!(count_visible_col_bottom(tab, col) == clues[i + 4]))
            return(0);
        i++;
    }
}

int	pos_is_valid(int tab[4][4], int pos, int *clues)
{
	if (!is_row_valid(tab, pos))
		return (0);
	if (!is_col_valid(tab, pos))
		return (0);
	if (pos % 4 == 3)
	    if (!validate_col_clues(tab, pos % 4, clues))
		    return (0);
    if (pos / 4 == 3)
            if(!validate_row_clues(tab, pos / 4, clues))
	return (1);
}

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
int	main(int argc, char **argv)
{
	int clues[16];
	int tab[4][4];

	if (argc != 2)
		    return (1);
    if (!valid_arg(argv[1]))
           return(1);    
	fill_clues(clues, argv[1]);
	init_tab(tab);
    ft_putstr("Puesta a 0\n");
	print_tab(tab);
    ft_putchar('\n'); 
    ft_putstr("cuadrado latino\n");
    solve(tab, 0);
    print_tab(tab);
	return (0);
}