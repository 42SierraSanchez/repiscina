/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asierra <asierra@student.42malaga.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 15:15:42 by asierra           #+#    #+#             */
/*   Updated: 2026/07/28 14:45:58 by asierra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_str_is_printable(char *str)
{
	if (!str[0])
		return (1);
	if (!(str[0] >= 32 && str[0] <= 126))
		return (0);
	return (ft_str_is_printable(str + 1));
}
/*
int	main(int argc, char **argv)
{
	if (argc != 2)
		return (printf("You must use only one argument\n"));
	printf("is printable? : %d\n", ft_str_is_printable(argv[1]));
	return (0);
}
*/
