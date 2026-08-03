/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asierra <asierra@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 01:25:41 by asierra           #+#    #+#             */
/*   Updated: 2026/08/04 01:41:26 by asierra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


int ft_recursive_factorial(int nb)
{
    int result

    result = 1;
    if (nb > 0)
        result *= ft_recursive_factorial(nb - 1);
    return(result);
}
