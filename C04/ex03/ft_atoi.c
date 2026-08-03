/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asierra <asierra@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 17:58:06 by asierra           #+#    #+#             */
/*   Updated: 2026/08/03 21:39:27 by asierra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_isspace(int c)
{
	if (c == ' ' || (c >= '\t' && c <= '\r'))
		return (1);
	return (0);
}

int	ft_is_digit(int c)
{
	return (c >= '0' && c <= '9');
}

int	ft_atoi(char *str)
{
	int	i;
	int	neg;
	int	result;

	i = 0;
	neg = 1;
	result = 0;
	while (ft_isspace(str[i]))
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
		{
			neg *= -1;
		}
		i++;
	}
	while (ft_is_digit(str[i]))
	{
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	return (result * neg);
}

/* #include <stdio.h>

int	main(void)
{
	char str[] = "-2147483648";
	printf("num es :%d\n",ft_atoi(str));
	
} */