/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asierra <asierra@student.42malaga.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 15:40:30 by asierra           #+#    #+#             */
/*   Updated: 2026/07/30 15:22:06 by asierra          ###   ########.fr       */
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

void	ft_printmem(unsigned char *byte_str, unsigned int count,
		unsigned int size)
{
	const char	*hex_base;

	hex_base = "0123456789abcdef";
	if (count >= 16)
		return ;
	if (byte_str[0] && count < size)
	{
		ft_putchar(hex_base[*byte_str / 16]);
		ft_putchar(hex_base[*byte_str % 16]);
	}
	else
		write(1, "  ", 2);
	if (count > 0 && count < 16 && (count % 2))
		ft_putchar(' ');
	ft_printmem(byte_str + 1, count + 1, size);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned char	*byte_str;

	byte_str = (unsigned char *)addr;
	ft_printmem(byte_str, 0, size);
	return (addr);
}

int	main(void)
{
	char	*test;

	test = "0123456789";
	ft_print_memory(test, 10);
}
