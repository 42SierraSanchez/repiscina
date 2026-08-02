/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asierra <asierra@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 14:21:59 by asierra           #+#    #+#             */
/*   Updated: 2026/08/02 15:21:03 by asierra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strstr(char *str, char *to_find)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	to_find_len;

	i = 0;
	j = 0;
	if (!to_find[0])
		return(0);
	to_find_len = ft_strlen(to_find);
	while (str[i])
	{
		if (str[i] == to_find[i])
		{
			while (str[i + j] == to_find[i + j])
			{
				if (!to_find[i + j])
					return (&str[i]);
				j++;
			}
			j = 0;
		}
		i++;
	}
	return ((void *)0);
}

int	main(void)
{
	char	str[] = "perr pe perros salvajes";
	char	to_find[] = "perros";

	printf("to find en str es %s", ft_strstr(str, to_find));
}
