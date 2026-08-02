/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asierra <asierra@student.42malaga.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 17:59:42 by asierra           #+#    #+#             */
/*   Updated: 2026/08/02 18:53:16 by asierra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int is_valid_digit(char c)
{   
	if 	(c == '+' || c == '-')
		return (0);
	if ((c >= 9 && c <= 13) || c == ' ')
		return (0);
	return(1);
}

int is_valid_base(char *base)
{
	unsigned int i;
	unsigned int j

	i = 0;
	
	while(base[i])
	{
		if (base[i] )
	i++;
	}

}


void ft_putnbr_base(int nbr, char *base)
{


}

