/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asierra <asierra@student.42malaga.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 19:46:07 by asierra           #+#    #+#             */
/*   Updated: 2026/07/28 23:06:51 by asierra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;

	i = 0;
	if (size > 0)
	{
		while (src[i] && i < size - 1)
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (ft_strlen(src));
}
/*
include <stdio.h>

int	main(int argc, char **argv)
{
	unsigned int	size;
	size = 3;
	char			dest[size];

	if (argc != 2)
		return (printf("You must use only one argument\n"));
	ft_strlcpy(dest, argv[1], size);
	printf("src is : %s\n", argv[1]);
	printf("dest es : %s\n", dest);
	return (0);
}*/
