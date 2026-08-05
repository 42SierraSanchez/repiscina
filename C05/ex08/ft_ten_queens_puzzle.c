/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asierra <asierra@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 14:03:36 by asierra           #+#    #+#             */
/*   Updated: 2026/08/05 14:25:26 by asierra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

ft_print_arr(int arr[10])
	{
		int	i;
		
		i = 0;
		while (i < 10)
		{
			write(1, &arr[i], 1);
		} 
	}

int check_col(int arr[10])
{
		int	i;
		
		i = 0;
		while (i < 9)
		{
			if (arr[i] == arr[i + 1])
				return(0);
		} 
		return(1);
}
	
int ft_ten_queens_puzzle(void)
{
	int arr[10];
		
	
}