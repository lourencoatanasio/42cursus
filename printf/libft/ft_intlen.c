/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldiogo <ldiogo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 17:59:59 by ldiogo            #+#    #+#             */
/*   Updated: 2022/05/03 16:38:11 by ldiogo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_intlen(unsigned long i)
{
	int	n;

	n = 0;
	if (i == 0)
	{
		n++;
	}
	while (i != 0)
	{
		i /= 16;
		n++;
	}
	return (n);
}
