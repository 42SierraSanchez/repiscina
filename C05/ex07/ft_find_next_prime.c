/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asierra <asierra@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 13:26:27 by asierra           #+#    #+#             */
/*   Updated: 2026/08/05 14:02:23 by asierra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	long	div;

	div = 2;
	if (nb < 2)
		return (0);
	while (div <= nb / div)
	{
		if (nb % div == 0)
			return (0);
		div++;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	int	next_prime;

	if (nb < 2)
		next_prime = 2;
	else
		next_prime = nb;
	while (1)
	{
		if (ft_is_prime(next_prime))
			return (next_prime);
		next_prime++;
	}
}
