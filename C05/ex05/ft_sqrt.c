/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asierra <asierra@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 11:47:38 by asierra           #+#    #+#             */
/*   Updated: 2026/08/05 12:07:11 by asierra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int		candidate;
	long	candidate_sqr;

	candidate = 0;
	while (candidate <= nb)
	{
		candidate_sqr = (long)candidate * (long)candidate;
		if (candidate_sqr == nb)
			return (candidate);
		if (candidate_sqr > nb)
			return (0);
		candidate++;
	}
	return (0);
}
