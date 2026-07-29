/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asierra <asierra@student.42malaga.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 23:08:39 by asierra           #+#    #+#             */
/*   Updated: 2026/07/29 14:27:51 by asierra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	char_non_print(char c)
{
	if (c >= 32 && c <= 126)
		return (0);
	return(1);
}

void	print_non_print(char *str, char *base)
{
	if (!str[0])
	{
		return;
	}
	if (char_non_print(str[0]))
	{
		ft_putchar('\\');
		ft_putchar(base[str[0] / 16]);
		ft_putchar(base[str[0] % 16]);
	}	
	else 
		ft_putchar(str[0]);
	print_non_print(&str[1], base);
}

void	ft_putstr_non_printable(char *str)
{
	print_non_print(str, "0123456789abcdef");
}

/*
#include <stdio.h>

int	main(void)
{
	ft_putstr_non_printable("HOLA \n \b ADIOS \0 esto no lo vas a leer");
	putchar('\n');
	return (0);
}
*/
