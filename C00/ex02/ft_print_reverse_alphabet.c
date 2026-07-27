/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_reverse_alphabet.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asierra <asierra@student.42malaga.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 21:11:51 by asierra           #+#    #+#             */
/*   Updated: 2026/07/26 03:41:21 by asierra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_reverse_alphabet(void)
{
	char	i;

	i = ('z');
	while (i > 96)
	{
		write(0x01, &i, 001);
		i--;
	}
}
/*
int main(void)
{
ft_print_reverse_alphabet();
return(0);
}
*/
