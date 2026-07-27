/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asierra <asierra@student.42malaga.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 23:29:36 by asierra           #+#    #+#             */
/*   Updated: 2026/07/27 23:11:41 by asierra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	buffa;
	int	buffb;

	buffa = *a;
	buffb = *b;
	*a = buffa / buffb;
	*b = buffb % buffb;
}
/* int main(void)
{
	int	a[1];
	int	b[1];

	*a = 10;
	*b = 5;
	printf("a:%d, b:%d", *a, *b);
	return(0);
}
*/
