/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asierra <asierra@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 14:03:36 by asierra           #+#    #+#             */
/*   Updated: 2026/08/07 14:05:19 by asierra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_arr(int arr[10])
{
	int		i;
	char	c;

	i = 0;
	while (i < 10)
	{
		c = arr[i] + '0';
		write(1, &c, 1);
		i++;
	}
}

int	check_mate(int arr[10], int pos)
{
	int	i;

	i = 0;
	while (i < pos)
	{
		if (arr[i] == arr[pos] || arr[pos] - pos == arr[i] - i || arr[pos]
			+ pos == arr[i] + i)
			return (0);
		i++;
	}
	return (1);
}

int	solve(int arr[10], int pos)
{
	int	try;
	if (pos == 10)
	{
		ft_print_arr(arr);
		write(1, "\n", 1);
		return(1);
	}
	try = 0;
	while (try <= 9)
	{
		arr[pos] = try;
		if (check_mate(arr, pos))
			 solve(arr, pos + 1);
		
		try++;
	}
	return (0);
}

int	ft_ten_queens_puzzle(void)
{
	int solutions;
	int	arr[10];
	
	solutions += solve(arr, 0); 
	return (solutions)
}

#include <stdio.h>
int	main(void)
{
	printf("solutions %d\n", ft_ten_queens_puzzle());
	return (0);
}