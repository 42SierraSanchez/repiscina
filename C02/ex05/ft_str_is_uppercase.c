/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asierra <asierra@student.42malaga.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 15:13:56 by asierra           #+#    #+#             */
/*   Updated: 2026/07/27 15:14:59 by asierra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_str_is_uppercase(char *str)
{
	if (!str[0])
		return (1);
	if (!(str[0] >= 'A' && str[0] <= 'Z'))
		return (0);
	return (ft_str_is_uppercase(str + 1));
}
/*
int	main(int argc, char **argv)
{
	if (argc != 2)
		return (printf("You must use only one argument\n"));
	printf("is uppercase? : %d\n", ft_str_is_uppercase(argv[1]));
	return (0);
}
*/
