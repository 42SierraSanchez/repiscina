/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asierra <asierra@student.42malaga.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 15:02:40 by asierra           #+#    #+#             */
/*   Updated: 2026/07/27 15:13:07 by asierra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_str_is_lowercase(char *str)
{
	if (!str[0])
		return (1);
	if (!(str[0] >= 'a' && str[0] <= 'z'))
		return (0);
	return (ft_str_is_lowercase(str + 1));
}
/*
int	main(int argc, char **argv)
{
	if (argc != 2)
		return (printf("You must use only one argument\n"));
	printf("is lowercase? : %d\n", ft_str_is_lowercase(argv[1]));
	return (0);
}
*/
