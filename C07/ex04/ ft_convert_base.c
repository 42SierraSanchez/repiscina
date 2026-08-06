/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    ft_convert_base.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asierra <asierra@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 14:09:42 by asierra           #+#    #+#             */
/*   Updated: 2026/08/06 19:47:01 by asierra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


int	ft_is_space(int c)
{
	if (c == ' ' || (c >= '\t' && c <= '\r'))
		return (1);
	return (0);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	is_valid_base(char *base)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (base[i])
	{
		if ((base[i] == '+' || base[i] == '-') || (base[i] >= 9
				&& base[i] <= 13) || base[i] == ' ')
			return (0);
		i++;
	}
	i = 0;
	while (base[i])
	{
		j = 0;
		while (base[j])
		{
			if (base[i] == base[j] && i != j)
				return (0);
			j++;
		}
		i++;
	}
	return (i);
}

int	convert(char *str, char *base)
{
	int	result;
	int	i;
	int	j;
	int	base_size;

	base_size = ft_strlen(base);
	i = 0;
	result = 0;
	while (str[i])
	{
		j = 0;
		while (base[j])
		{
			if (str[i] == base[j])
				break ;
			j++;
		}
		if (base[j])
			result = (result * base_size) + j;
		else
			return (result);
		i++;
	}
	return (result);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	neg;
	int	result;

	i = 0;
	neg = 1;
	result = 0;
	if (ft_strlen(base) < 2 || !is_valid_base(base))
		return (0);
	while (ft_is_space(str[i]))
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
		{
			neg *= -1;
		}
		i++;
	}
	result = convert(&str[i], base);
	return (result * neg);
}
