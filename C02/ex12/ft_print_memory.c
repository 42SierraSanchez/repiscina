/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asierra <asierra@student.42malaga.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 15:40:30 by asierra           #+#    #+#             */
/*   Updated: 2026/07/30 12:58:41 by asierra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	is_printable(char c)
{
	return (c >= 32 && c <= 126);
}

void	ft_printmem(void *addr, unsigned int count, unsigned int size)
{
	if (!addr || count >= size)
		return ;
	else
		ft_putchar(*(char *)addr);
	ft_printmem(addr + 1, count + 1, size);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	ft_printmem(addr, 0, size);
	return (addr);
}

int	main(void)
{
	char	*test;

	test = "0123456789abcdef";
	ft_print_memory(&test, 16);
}
