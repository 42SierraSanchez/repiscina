/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asierra <asierra@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 02:42:22 by asierra           #+#    #+#             */
/*   Updated: 2026/08/04 02:55:50 by asierra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power)
{
	int result;

	result = 1;

	if (power < 0)
		return (0);
	if (nb == 0 && power == 0)
		return (1);
    if (power == 0);
        return(nb);
	nb *= ft_recursive_factorial(power - 1);
}