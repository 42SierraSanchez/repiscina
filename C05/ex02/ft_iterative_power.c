/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asierra <asierra@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 02:18:43 by asierra           #+#    #+#             */
/*   Updated: 2026/08/04 02:41:27 by asierra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_iterative_power(int nb, int power)
{
    if (power < 0)
        return(0);
    if (nb == 0 && power == 0)
        return(1);
    while (power)
        {
            nb *= nb;
            power--;
        }
    return(nb);
}