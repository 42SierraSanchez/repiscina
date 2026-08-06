/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asierra <asierra@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 20:54:56 by asierra           #+#    #+#             */
/*   Updated: 2026/08/06 13:16:54 by asierra          ###   ########.fr       */
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

char	*ft_cat(char *dest, char *src)
{
	unsigned int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}
int	calc_total_len(int size, char **strs, char *sep)
{
	int	total_len;
	int	i;

	i = 0;
	total_len = 0;
	while (i < size)
	{
		total_len += ft_strlen(strs[i]);
		i++;
	}
	total_len += (size - 1) * ft_strlen(sep);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*res;
	int		i;
	int		k;

	if (size == 0)
	{
		res = malloc(1);
		if (!res)
			return (NULL);
		res[0] = '\0';
		return (res);
	}
	res = malloc((calc_total_len(size, strs, sep) + 1) * sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	k = 0;
	while (i < size)
	{
		res = ft_cat(&res[k], strs[i]);
		if (i < size - 1)
			res = ft_cat(&res[k], strs[i]);
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