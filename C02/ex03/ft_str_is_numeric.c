/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asierra <asierra@student.42malaga.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 14:34:43 by asierra           #+#    #+#             */
/*   Updated: 2026/07/27 15:00:57 by asierra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_str_is_numeric(char *str)
{
	if (!str[0])
		return (1);
	if (!(str[0] >= '0' && str[0] <= '9'))
		return (0);
	return (ft_str_is_numeric(str + 1));
}

/*int	main(int argc, char **argv)
{
	if (argc != 2)
		return (printf("You must use only one argument\n"));
	printf("es numeric? : %d\n", ft_str_is_numeric(argv[1]));
	return (0);
}*/
