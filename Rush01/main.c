/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asierra <asierra@student.42malaga.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/01 08:24:43 by asierra           #+#    #+#             */
/*   Updated: 2026/08/01 15:24:28 by asierra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*VALIDAR/PARSEAR/IMPRIMIR

is_input_valid

parse_input

print_tab

COMPROBAR VALIDEZ

is_col_valid

it_row_valid

count_visible

validate_clues



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

int	is_row_valid(int **tab, int pos)
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

int	is_col_valid(int **tab, int *pos)
{
	int	i;

	i = (pos / 4) - 1;
	while (i >= 0)
	{
		if (tab[pos / 4][pos % 4] == tab[i][pos / 4])
			return (0);
		i--;
	}
	return (1);
}

int count_visible_row_left(int **tab, int pos)
{
	int i;
	int count;
	i = 0;
	count = 1;
		while (i < pos % 4)
		{
			if (tab[pos / 4][pos % 4] == 4)
				break;
			
		}
	return (count);
}


int	solve(int **tab, int *clues, int pos)
{
	int	try;

	try = 1;
	if (pos == 16)
		return (1);
	while (try <= 4)
	{
		tab[pos / 4][pos % 4] = try;
		if (is_pos_valid(tab, pos, clues))
			if (solve(tab, clues, pos + 1))
				return (1);
		tab[pos / 4][pos % 4] = 0;
		try++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int	clues[16];
	int	tab[4][4];

	if (argc != 2)
		retur(0);
}
