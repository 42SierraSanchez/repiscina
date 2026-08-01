/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rush.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algaldea <algaldea@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/01 17:18:03 by algaldea          #+#    #+#             */
/*   Updated: 2026/08/01 18:15:40 by algaldea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

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

int	*num_en_pos(char *str)
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

int	check_eq_arr(int *s1, int *s2)
{
	int	i;

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
}

void	print_tab(int tablero [4][4])
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
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
	char	str[];
	int		*dev;
	int		tablero[4][4];
	int		i;
	int		arr1[4];
	int		arr2[4];

	str[] = "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2";
	*dev = num_en_pos(str);
	tablero[4][4] = {
	{1, 2, 3, 4},
	{1, 2, 3, 4},
	{1, 2, 3, 4},
	{1, 2, 3, 4}
	};
	printTab(tablero);
	i = 0;
	while (i < 16)
	{
		printf("%d", dev[i]);
		i++;
	}
	printf("\n");
	free(dev);
	arr1[4] = {7, 1, 2, 3};
	arr2[4] = {7, 1, 8, 3};
	printf("%d", check_eq_arr(arr1, arr2));
	return (0);
}
