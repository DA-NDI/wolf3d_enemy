/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_bits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolgin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 17:41:20 by avolgin           #+#    #+#             */
/*   Updated: 2018/01/30 17:42:42 by avolgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		count_bits(unsigned long long nbr)
{
	int		i;

	i = 0;
	while (nbr)
	{
		nbr >>= 1;
		i++;
	}
	return (i);
}
