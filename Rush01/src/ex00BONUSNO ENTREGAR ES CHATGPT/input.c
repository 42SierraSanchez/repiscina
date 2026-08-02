/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asierra <asierra@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 09:59:18 by asierra-          #+#    #+#             */
/*   Updated: 2026/08/02 10:48:10 by asierra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int	count_clues(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (i % 2 == 0 && !(str[i] >= '1' && str[i] <= '9'))
			return (0);
		if (i % 2 == 1 && str[i] != ' ')
			return (0);
		if (i % 2 == 0)
			count++;
		i++;
	}
	if (i == 0 || i % 2 == 0)
		return (0);
	return (count);
}

int	valid_values(char *str, int size)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] - '0' > size)
			return (0);
		if (str[i + 1] == '\0')
			break ;
		i += 2;
	}
	return (1);
}

int	valid_arg(char *str, int *size)
{
	int	count;

	count = count_clues(str);
	if (count < 4 || count > 36 || count % 4 != 0)
		return (0);
	*size = count / 4;
	if (!valid_values(str, *size))
		return (0);
	return (1);
}

void	fill_clues(int clues[36], char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] != '\0' && j < 36)
	{
		if (str[i] >= 48 && str[i] <= 57)
		{
			clues[j] = str[i] - '0';
			j++;
		}
		i++;
	}
}
