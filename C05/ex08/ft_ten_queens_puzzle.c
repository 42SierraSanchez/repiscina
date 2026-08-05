/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asierra <asierra@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 14:03:36 by asierra           #+#    #+#             */
/*   Updated: 2026/08/05 17:12:13 by asierra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

ft_print_arr(int arr[10])
{
	int	i;

	i = 0;
	while (i < 10)
	{
		write(1, &arr[i] + '0', 1);
		i++;
	}
}

solve(int arr[10], row)
{

	
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