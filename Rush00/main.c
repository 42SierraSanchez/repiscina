/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucortes <jucortes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 19:05:31 by jucortes          #+#    #+#             */
/*   Updated: 2026/07/26 20:44:05 by jucortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_first_last_line(int x, char a, char b, char c);
void	ft_center_lines(int x, char b);
void	ft_inverted_first(int x, char a, char b, char c);
void	ft_inverted_last(int x, char a, char b, char c);
void	ft_center_lines(int x, char b);
void	ft_rush_zero(int x, int y, char *str);
void	ft_putchar(char c);
void	ft_first(int x, char a, char b);
void	ft_fill_str(char **str);
void	ft_putstr(char *str);
int		ft_print_welcome(char c);

void	ft_rush_fourth(int x, int y, char *str)
{
	int	i;

	i = 0;
	while (i < y)
	{
		if (i == 0 || i == y - 1)
			ft_first_last_line(x, str[0], str[1], str[2]);
		else
			ft_center_lines(x, str[1]);
		i++;
	}
	ft_putchar('\n');
}

void	ft_rush_second_fifth(int x, int y, char *str)
{
	int	i;

	i = 0;
	while (i < y)
	{
		if (i == 0)
			ft_inverted_first(x, str[0], str[1], str[2]);
		else if (i == y - 1)
			ft_inverted_last(x, str[0], str[1], str[2]);
		else
			ft_center_lines(x, str[1]);
		i++;
	}
	ft_putchar('\n');
}

void	ft_rush_third(int x, int y, char *str)
{
	int	i;

	i = 0;
	while (i < y)
	{
		if (i == 0)
			ft_first(x, str[0], str[1]);
		else if (i == y - 1)
			ft_first(x, str[2], str[1]);
		else
			ft_center_lines(x, str[1]);
		i++;
	}
	ft_putchar('\n');
}

void	rush(int x, int y, char comb)
{
	char	*str[4];

	ft_fill_str(str);
	if (comb == '0')
		ft_rush_zero(x, y, str[0]);
	else if (comb == '1')
		ft_rush_second_fifth(x, y, str[1]);
	else if (comb == '2')
		ft_rush_third(x, y, str[2]);
	else if (comb == '3')
		ft_rush_fourth(x, y, str[2]);
	else if (comb == '4')
		ft_rush_second_fifth(x, y, str[2]);
	else if (comb == '5')
	{
		ft_putstr("Congrats, you found the easter egg, go for the topo ;)\n");
		ft_putstr("All rushes will be printed:\n");
		ft_rush_zero(x, y, str[0]);
		ft_rush_second_fifth(x, y, str[1]);
		ft_rush_third(x, y, str[2]);
		ft_rush_fourth(x, y, str[2]);
		ft_rush_second_fifth(x, y, str[2]);
	}
}

int	main(int argc, char *argv[])
{
	if (argc != 2)
	{
		ft_putstr("You must put at least 1 argument\n");
		return (1);
	}
	if (argv[1][1] != '\0')
	{
		ft_putstr("You must put just one digit to select the rush\n");
		return (1);
	}
	if (argv[1][0] < '0' || argv[1][0] > '5')
	{
		ft_putstr("You must put one digit from 0-5 to use this program\n");
		return (1);
	}
	ft_print_welcome(argv[1][0]);
	rush(50, 50, argv[1][0]);
	return (0);
}
