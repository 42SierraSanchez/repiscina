/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asierra- <asierra-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/01 08:24:43 by asierra           #+#    #+#             */
/*   Updated: 2026/08/01 18:30:25 by asierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*VALIDAR/PARSEAR/IMPRIMIR

is_input_valid //

parse_input //

print_tab //

COMPROBAR VALIDEZ

is_col_valid  //

it_row_valid //

count_visible //

count_visible+validate_clues



Backtracking
	-recorrer posiciones
	-probar valores
	-llamadas recursivas
	-borrar cuando fracaso.

pseudo codigo

pruebo un num
	lo coloco
	compruebo validez

	si es valido
		intento resolver la siguiente posicion
			devuelvo exito si  encuentra solucion

	si no funciona
		borro la casilla
			pruebo la siguiente solucion




*/
void	fill_to_check(int tab[4][4], int pos, int *to_check)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < 4)
	{
		while (i < 4)
		{
			i++;
		}:
			i = 0;
	}
}

int	validate_clues(tab[4][4], pos)
{
	int to_check[] fill_to_check()
}

int	pos_is_valid(int tab[4][4], int pos)
{
	if (!is_row_valid(tab, pos))
		return (0);
	if (!is_col_valid(tab, pos))
		return (0);
	// if (pos % 4 == 3)
	if (pos == 16)
		if (!validate_clues(tab, pos))
			return (0);
	return (1);
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
int	solve(int tab[4][4], int *clues, int pos)
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

void	init_tab(int tab[4][4])
{
	int	i;
	int	j;

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
	int	clues[16];
	int	tab[4][4];

	if (argc != 2)
		retur(0);
	clues = numEnPos(argv[1]);
}
