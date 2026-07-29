/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asierra <asierra@student.42malaga.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 23:08:39 by asierra           #+#    #+#             */
/*   Updated: 2026/07/29 14:52:55 by asierra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	is_print(char c)
{
	return (c >= 32 && c <= 126);
}

void put_non_print_char(char c, char *base)
{
	ft_putchar('\\');
	ft_putchar(base[c / 16]);
	ft_putchar(base[c % 16]);
}

void	print_str(char *str, char *base)
{
	if (!*str)
		return ;
	if (!is_print(*str))
		put_non_print_char(*str, base);
	else
		ft_putchar(*str);
	print_str(str + 1, base);
}

void	ft_putstr_non_printable(char *str)
{
	print_str(str, "0123456789abcdef");
}


#include <stdio.h>

int	main(void)
{
	ft_putstr_non_printable("HOLA \n \b ADIOS \0 esto no lo vas a leer");
	putchar('\n');
	return (0);
}


