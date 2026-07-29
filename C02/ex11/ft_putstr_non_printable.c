/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asierra <asierra@student.42malaga.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 23:08:39 by asierra           #+#    #+#             */
/*   Updated: 2026/07/29 15:02:14 by asierra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	is_printable(char c)
{
	return (c >= 32 && c <= 126);
}

void	put_non_printable(unsigned char c)
{
	char	*hex_base;

	hex_base = "0123456789abcdef";
	ft_putchar('\\');
	ft_putchar(hex_base[c / 16]);
	ft_putchar(hex_base[c % 16]);
}

void	ft_putstr_non_printable(char *str)
{
	if (!*str)
		return ;
	if (!is_printable(*str))
		put_non_printable(*str);
	else
		ft_putchar(*str);
	ft_putstr_non_printable(str + 1);
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
