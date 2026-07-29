/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asierra <asierra@student.42malaga.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 15:40:30 by asierra           #+#    #+#             */
/*   Updated: 2026/07/29 18:32:12 by asierra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdint.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	is_printable(char c)
{
	return (c >= 32 && c <= 126);
}

void	ft_printmem(void *addr, unsigned int count)
{
	if (!addr || count >= 16)
		return ;
	else
		ft_putchar(*(char *)addr);
	ft_printmem(addr + 1, count + 1);
}

void *ft_print_memory(void *addr, unsigned int size)
{
	ft_printmem(addr, size);
	printf("printf: puntero es %016lx", (uintptr_t)addr);
	return(addr);
}


int	main(void)
{
	char *test;
	uintptr_t **p;

	test = "0123456789abcdef";
	p = &test;
	
	printf("%016" PRIxPTR "\n", p);

	ft_print_memory(p, 16);

}
