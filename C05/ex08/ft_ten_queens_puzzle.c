/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asierra <asierra@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 14:03:36 by asierra           #+#    #+#             */
/*   Updated: 2026/08/07 13:21:03 by asierra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_print_arr(int arr[10])
{
	int	i;

	i = 0;
	while (i < 10)
	{
		write(1, &arr[i] + '0', 1);
		i++;
	}
}

int check_mate(int arr[10], int pos)
{
	
}

int solve(int arr[10], int pos)
{
	int try;
	
	try = 0;
	if (pos == 10)
		return(1); 
	while (try <= 9)
	{
		arr[pos] = try;
		if (check_mate(arr, pos))
			if (solve(arr,  pos + 1))
				return(1);
		arr[pos] = 0;
		try++;
	}
	return(0); //exit?//
}

int	ft_ten_queens_puzzle(void)
{
	int	arr[10];
}

int	main(void)
{
	ft_ten_queens_puzzle();
	return (0);
}