/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asierra <asierra@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 20:54:56 by asierra           #+#    #+#             */
/*   Updated: 2026/08/06 11:50:37 by asierra          ###   ########.fr       */
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
	int		k;
	int		l;

	if (size == 0)
	{
		res = malloc(1);
		if (!res)
			return (NULL);
		res[0] = '\0';
		return (res);
	}
	i = 0;
	total_len = 0;
	while (i < size)
	{
		total_len += ft_strlen(strs[i]);
		i++;
	}
	total_len += (size - 1) * ft_strlen(sep);
	res = malloc((total_len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	k = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
		{
			res[k] = strs[i][j];
			j++;
			k++;
		}
		l = 0;
		if (i < size - 1)
		{
			while (sep[l])
			{
				res[k] = sep[l];
				l++;
				k++;
			}
		}
		i++;
	}
	res[k] = '\0';
	return (res);
}
#include <stdio.h>

int	main(void)
{
	int size = 4;
	char *strs[] = {"Hola", "", "mundo", "cruel"};
	char *sep = "--";
	char *res = ft_strjoin(size, strs, sep);
	printf("%s\n", res);
	free(res);
	return (0);
}