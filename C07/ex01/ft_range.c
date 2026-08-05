/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asierra <asierra@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 19:45:35 by asierra           #+#    #+#             */
/*   Updated: 2026/08/05 20:05:36 by asierra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*arr;
	int	len;
	int	i;

	if (min >= max)
		return (NULL);
	len = max - min;
	arr = malloc(len * sizeof(int));
	if (!arr)
		return ((NULL)i = 0);
	while (len)
	{
		arr[i] = min + i;
		i++;
		len--;
	}
	return (arr);
}
