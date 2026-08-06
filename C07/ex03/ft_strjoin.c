/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asierra <asierra@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 20:54:56 by asierra           #+#    #+#             */
/*   Updated: 2026/08/06 13:36:14 by asierra          ###   ########.fr       */
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

int	ft_cat(char *dest, char *src)
{
	unsigned int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	return (i);
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
	return (total_len);
}

char	*fill_empty_line(void)
{
	char	*empty_line;

	empty_line = malloc(1);
	if (!empty_line)
		return (NULL);
	empty_line[0] = '\0';
	return (empty_line);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*res;
	int		i;
	int		k;

	if (size == 0)
		return (fill_empty_line());
	res = malloc((calc_total_len(size, strs, sep) + 1) * sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	k = 0;
	while (i < size)
	{
		k += ft_cat(&res[k], strs[i]);
		if (i < size - 1)
			k += ft_cat(&res[k], sep);
		i++;
	}
	res[k] = '\0';
	return (res);
}

/* #include <stdio.h>

int	main(void)
{
	int size = 4;
	char *strs[] = {"Hola", "", "mundo", "cruel"};
	char *sep = "--";
	char *res = ft_strjoin(size, strs, sep);
	printf("%s\n", res);
	free(res);
	return (0);
} */