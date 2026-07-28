/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asierra <asierra@student.42malaga.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 23:08:39 by asierra           #+#    #+#             */
/*   Updated: 2026/07/28 23:17:19 by asierra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int	ft_str_is_printable(char *str)
{
	if (!str[0])
		return (1);
	if (!(str[0] >= 32 && str[0] <= 127))
		return (0);
	return (ft_str_is_printable(str + 1));
}

int	print_non_print(char *str)
{
	if
	return(0)
}

void	ft_putstr_non_printable(char *str)
{
	print_non_print(str);
}
