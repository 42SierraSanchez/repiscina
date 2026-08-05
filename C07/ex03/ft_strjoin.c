/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asierra <asierra@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 20:54:56 by asierra           #+#    #+#             */
/*   Updated: 2026/08/05 21:49:01 by asierra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*res;
	int		total_len;
	int		i;
	int		j;
	int k;

	if (size == 0)
		return ("\0");
	i = 0;
	total_len = 0;
	while (i <= size)
	{
		total_len += ft_strlen(strs[i]);
		i++;
	}
	total_len += (size - 1) * ft_strlen(sep);
	res = malloc(total_len + 1 * sizeof(char));
	if (!res)
		return ("\0");
	i = 0;
	k = 0;
	while (i <= size)
	{
		j = 0;
		while (strs[i][j])
		{
			res[k] = strs[i][j];
			j++;
			k++;
		}
		res[k] = *sep;
		k++;
		i++;
	}
	res[k] = '\0';
	 return (res);
}
#include <stdio.h>

int	main(void)
{
	int size = 3;
	char *strs[] = {"Hola", "mundo", "cruel"};
	char sep = 'i'; 
	char *res = ft_strjoin(size, strs, &sep);
	printf("%s\n", res);
	free(res);
	return (0);
}