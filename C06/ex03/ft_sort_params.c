/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asierra <asierra@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 23:28:19 by asierra           #+#    #+#             */
/*   Updated: 2026/08/05 00:07:50 by asierra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_swap_str(char **a, char **b)
{
	char	*buf;

	buf = *a;
	*a = *b;
	*b = buf;
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	ft_sort_str_tab(char **tab, int size)
{
	int	i;
	int	j;

	j = 0;
	while (j < size)
	{
		i = 0;
		while (i < size - 1 - j)
		{
			if (ft_strcmp(tab[i], tab[i + 1]) > 0)
				ft_swap_str(&tab[i], &tab[i + 1]);
			i++;
		}
		j++;
	}
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

int	main(int argc, char **argv)
{
	int	i;

	i = 1;
	ft_sort_str_tab(&argv[1], argc - 1);
	while (i < argc)
	{
		ft_putstr(argv[i]);
		ft_putstr("\n");
		i++;
	}
	return (0);
}
