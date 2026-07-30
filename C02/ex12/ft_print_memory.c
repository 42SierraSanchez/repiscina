/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asierra <asierra@student.42malaga.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 15:40:30 by asierra           #+#    #+#             */
/*   Updated: 2026/07/30 20:48:05 by asierra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static const char	*hex_base = "0123456789abcdef";

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_hex_line(unsigned char *byte_str, unsigned int count,
		unsigned int size)
{
	if (count >= 16)
		return ;
	if (count < size)
	{
		ft_putchar(hex_base[*byte_str / 16]);
		ft_putchar(hex_base[*byte_str % 16]);
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
	if (size <= 0)
		return ;
	if ((*str < 32 && *str > 126))
		ft_putchar('.');
	else
		ft_putchar(*str);
	ft_putstr_non_printable(str + 1, size - 1);
}

void	ft_print_hex_addr(unsigned long addr, unsigned int cont)
{
	if (cont >= 16)
		return ;
	ft_print_hex_addr(addr / 16, cont + 1);
	ft_putchar(hex_base[addr % 16]);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned char	*byte_str;
	unsigned long	addr_nb;
	if (size <= 0)
		return(addr);
	addr_nb	=	(unsigned long)addr;
	byte_str = (unsigned char *)addr;	
	unsigned int line_size = size;
	int i;
	i = 0;

	while (line_size)
	{
	i++;
	line_size /= 16;
	}
	
	while (i > 0)
	{
		ft_print_hex_addr(addr_nb, 0);
		ft_putchar(':');
		ft_putchar(' ');
		ft_print_hex_line(byte_str, 0, 16);
		ft_putchar(' ');
		ft_putstr_non_printable(byte_str, 16);
		ft_putchar('\n');
		byte_str += 16;
		addr_nb += 16;
		i--;
	}
	return (addr);
}

int	main(void)
{
	char	*test;

	test = "Bonjour\0les\namin Grita DEVASTACION! y suelta a los perros de la guerra";
	ft_print_memory(test, 40);
}
