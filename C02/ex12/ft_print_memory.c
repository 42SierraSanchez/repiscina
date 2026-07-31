/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asierra <asierra@student.42malaga.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 15:40:30 by asierra           #+#    #+#             */
/*   Updated: 2026/07/31 10:22:17 by asierra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static const char	g_hex_base[] = "0123456789abcdef";

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_hex_addr(unsigned long addr, unsigned int cont)
{
	if (cont >= 16)
		return ;
	ft_print_hex_addr(addr / 16, cont + 1);
	ft_putchar(g_hex_base[addr % 16]);
}
void	ft_print_hex_line(unsigned char *byte_str, unsigned int count,
		unsigned int size)
{
	if (count >= 16)
		return ;
	if (count < size)
	{
		ft_putchar(g_hex_base[*byte_str / 16]);
		ft_putchar(g_hex_base[*byte_str % 16]);
	}
	else
		write(1, "  ", 2);
	if (count < 14 && (count % 2))
		ft_putchar(' ');
	if (count < size)
		ft_print_hex_line(byte_str + 1, count + 1, size);
	else
		ft_print_hex_line(byte_str, count + 1, size);
}

void	ft_putstr_non_printable(unsigned char *str, unsigned int size)
{
	if (!size)
		return ;
	if (*str < 32 || *str > 126)
		ft_putchar('.');
	else
		ft_putchar(*str);
	ft_putstr_non_printable(str + 1, size - 1);
}


void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned char	*byte_str;
	unsigned int	line_size;

	byte_str = (unsigned char *)addr;
	while (size)
	{
		if (size > 16)
			line_size = 16;
		else
			line_size = size;
		ft_print_hex_addr((unsigned long)byte_str, 0);
		ft_putchar(':');
		ft_putchar(' ');
		ft_print_hex_line(byte_str, 0, line_size);
		ft_putchar(' ');
		ft_putstr_non_printable(byte_str, line_size);
		ft_putchar('\n');
		byte_str += line_size;
		size -= line_size;
	}
	return (addr);
}
/*
#include <stdio.h>
int	main(void)
{
	char	*test;

	test = "Grita\0<<¡DEVASTACION!>>\ny suelta a\blos\aperros de la guerra";
	printf("Empiezan los tests:\n");
	printf("Size = 0:\n");
	ft_print_memory(test, 0);
	printf("Size = 1:\n");
	ft_print_memory(test, 1);
	printf("Size = 15:\n");
	ft_print_memory(test, 15);
	printf("Size = 16:\n");
	ft_print_memory(test, 16);
	printf("Size = 17:\n");
	ft_print_memory(test, 17);
	printf("Size = 31:\n");
	ft_print_memory(test, 31);
	printf("Size = 32:\n");
	ft_print_memory(test, 32);
}*/
