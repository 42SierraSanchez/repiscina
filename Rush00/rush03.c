/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucortes <jucortes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 18:26:10 by jucortes          #+#    #+#             */
/*   Updated: 2026/07/26 20:44:18 by jucortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);
void	ft_first(int x, char a, char b);

void	ft_first_last_line(int x, char a, char b, char c)
{
	int	i;

	i = 0;
	while (i < x)
	{
		if (i == 0)
			ft_putchar(a);
		else if (i == x - 1)
			ft_putchar(c);
		else
			ft_putchar(b);
		i++;
	}
	ft_putchar('\n');
}

void	ft_inverted_first(int x, char a, char b, char c)
{
	int	i;

	i = 0;
	while (i < x)
	{
		if (i == 0)
			ft_putchar(a);
		else if (i == x - 1)
			ft_putchar(c);
		else
			ft_putchar(b);
		i++;
	}
	ft_putchar('\n');
}

void	ft_inverted_last(int x, char a, char b, char c)
{
	int	i;

	i = 0;
	while (i < x)
	{
		if (i == 0)
			ft_putchar(c);
		else if (i == x - 1)
			ft_putchar(a);
		else
			ft_putchar(b);
		i++;
	}
	ft_putchar('\n');
}

void	ft_center_lines(int x, char b)
{
	int	i;

	i = 0;
	while (i < x)
	{
		if (i == 0 || i == x - 1)
			ft_putchar(b);
		else
			ft_putchar(' ');
		i++;
	}
	ft_putchar('\n');
}

void	ft_rush_zero(int x, int y, char *str)
{
	int	i;

	i = 0;
	while (i < y)
	{
		if (i == 0 || i == y - 1)
			ft_first(x, str[0], str[2]);
		else
			ft_center_lines(x, str[1]);
		i++;
	}
	ft_putchar('\n');
}
