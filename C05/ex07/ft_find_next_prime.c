/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asierra <asierra@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 13:26:27 by asierra           #+#    #+#             */
/*   Updated: 2026/08/05 13:49:13 by asierra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_find_next_prime(int nb)
{
	int	next_prime;
	int	i;

	next_prime = nb;
	while (1)
	{
		i = next_prime;
		while (i != 0)
		{
			if (!(next_prime % i))
				break ;
			i--;
		}
		if (i == 0)
			return(next_prime);
		next_prime++;
	}
}
