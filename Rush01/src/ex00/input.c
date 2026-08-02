/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asierra <asierra@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 09:59:18 by asierra           #+#    #+#             */
/*   Updated: 2026/08/02 12:49:01 by asierra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
