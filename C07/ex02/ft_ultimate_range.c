/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asierra <asierra@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 20:09:13 by asierra           #+#    #+#             */
/*   Updated: 2026/08/05 20:28:29 by asierra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	len;
	int	i;
	
	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	len = max - min;
	*range = malloc(len * sizeof(int));
	if (!*range)
		return (-1);
	i = 0;
	while (len)
	{
		*range[i] = min + i;
		i++;
		len--;
	}
	return (max - min);
}

int	main(void)
{
	int **range = NULL;
	int i = ft_ultimate_range(range, 10, 20);
	int j = 0;
	while (i)
	{
		printf("%d\n", *range[j]);
		j++;
		i--;
	}
}