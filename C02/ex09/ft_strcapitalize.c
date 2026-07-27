/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asierra <asierra@student.42malaga.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 15:47:22 by asierra           #+#    #+#             */
/*   Updated: 2026/07/27 19:39:28 by asierra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	is_alphanum(char c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0'
			&& c <= '9'));
}

int	is_lowercase(char c)
{
	return (c >= 'a' && c <= 'z');
}

int	is_uppercase(char c)
{
	return (c >= 'A' && c <= 'Z');
}

int	capitalize(char *str, int first)
{
	if (!str[0])
		return (0);
	if (first == 1 && is_lowercase(str[0]))
		(str[0] -= 32);
	else if (first == 0 && is_uppercase(str[0]))
		(str[0] += 32);
	if (!is_alphanum(str[0]))
		first = 1;
	else
		first = 0;
	return (capitalize(str + 1, first));
}

char	*ft_strcapitalize(char *str)
{
	capitalize(str, 1);
	return (str);
}
/*
int	main(int argc, char **argv)
{
	if (argc != 2)
		return (printf("You must use only one argument\n"));
	printf("argv[1] is : %s\n", argv[1]);
	printf("capitalized : %s\n", ft_strcapitalize(argv[1]));
	return (0);
}*/
