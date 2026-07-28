/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asierra <asierra@student.42malaga.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 19:46:07 by asierra           #+#    #+#             */
/*   Updated: 2026/07/28 16:50:06 by asierra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

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
	int				i;

	i = 0;
	while (src[i] && dest[i] && (unsigned int)i < size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[size] = '\0';
	return (ft_strlen(src));
}

int	main(int argc, char **argv)
{
	unsigned int	size;

	if (argc != 2)
		return (printf("You must use only one argument\n"));
	
	size = ft_strlen(argv[1]) + 1;
	char dest[size];
	ft_strlcpy(dest, argv[1], size);

	printf("src is : %s\n", argv[1]);
	printf("dest es : %s\n", dest);
	return (0);
}
