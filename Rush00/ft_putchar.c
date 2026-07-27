/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucortes <jucortes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 18:50:51 by jucortes          #+#    #+#             */
/*   Updated: 2026/07/26 20:43:10 by jucortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}

void	ft_fill_str(char **str)
{
	str[0] = "o|-";
	str[1] = "/*\\";
	str[2] = "ABC";
}

void	ft_first(int x, char a, char b)
{
	int	i;

	{
		i = 0;
		while (i < x)
		{
			if (i == 0 || i == x - 1)
				ft_putchar(a);
			else
				ft_putchar(b);
			i++;
		}
		ft_putchar('\n');
	}
}

int	ft_print_welcome(char c)
{
	if (c == '5')
		return (1);
	ft_putstr("Rush 0");
	if (c == '0')
		ft_putstr("0:\n");
	else if (c == '1')
		ft_putstr("1\n");
	else if (c == '2')
		ft_putstr("2\n");
	else if (c == '3')
		ft_putstr("3\n");
	else if (c == '4')
		ft_putstr("4\n");
	return (0);
}
