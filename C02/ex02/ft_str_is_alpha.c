/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asierra <asierra@student.42malaga.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 00:14:33 by asierra           #+#    #+#             */
/*   Updated: 2026/07/27 14:48:42 by asierra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_str_is_alpha(char *str)
{
	if (!str[0])
		return (1);
	if (!((str[0] >= 'A' && str[0] <= 'Z') || (str[0] >= 'a' && str[0] <= 'z')))
		return (0);
	return (ft_str_is_alpha(str + 1));
}

/*int	main(int argc, char **argv)
{
	if (argc != 2)
		return (printf("You must use only one argument\n"));
	printf("is alpha? : %d\n", ft_str_is_alpha(argv[1]));
	return (0);
}*/
