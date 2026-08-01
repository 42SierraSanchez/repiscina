/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asierra <asierra@student.42malaga.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/01 15:21:49 by asierra           #+#    #+#             */
/*   Updated: 2026/08/01 15:24:08 by asierra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// TODO: Comprobar que los nums no sean mayor de 4
int	validChars(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!(str[i] == 32 || (str[i] <= '1' && str[i] >= '4')))
			return (1);
		i++;
	}
	return (0);
}

int	validLength(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	if (i != 31)
		return (1);
	return (0);
}

int	validPos(char *str)
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

int	validFormat(char *str)
{
	if (validChars(str))
		return (1);
	if (validLength(str))
		return (1);
	if (validPos(str))
		return (1);
	return (0);
}

int	*numEnPos(char *str)
{
	int	*ret;
	int	i;
	int	j;

	ret = malloc(sizeof(int) * 16);
	i = 0;
	j = 0;
	while (str[i] != '\0' && j < 16)
	{
		if (str[i] >= 48 && str[i] <= 57)
		{
			ret[j] = str[i] - '0';
			j++;
		}
		i++;
	}
	return (ret);
}

void	printTab(int tablero[4][4], int filas, int columnas)
{
	int	i;
	int	j;

	i = 0;
	while (i < filas)
	{
		j = 0;
		while (j < columnas)
		{
			printf("%d ", tablero[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

int	main(void)
{
	char	str[] = "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2";
	int		*dev;
	int		tablero[4][4] = {{1, 2, 3, 4}, {1, 2, 3, 4}, {1, 2, 3, 4}, {1, 2, 3,
				4}};

	dev = numEnPos(str);
	printTab(tablero, 4, 4);
	/*int i = 0;
	while (i < 16)
	{
		printf("%d", dev[i]);
		i++;
	}
	printf("\n");
	free(dev);*/
	return (0);
}
