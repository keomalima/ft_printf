/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kricci-d <kricci-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 17:30:19 by keomalima         #+#    #+#             */
/*   Updated: 2024/11/12 09:21:52 by kricci-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int			sign;
	long long	nb;

	nb = 0;
	sign = 1;
	while ((*(str) >= '\t' && *(str) <= '\r') || *(str) == ' ')
		str++;
	if (*(str) == '-' || *(str) == '+')
	{
		if (*(str) == '-')
			sign *= -1;
		str++;
	}
	while (*(str) >= '0' && *(str) <= '9')
	{
		if (nb > (LONG_MAX - (*(str) - '0')) / 10)
		{
			if (sign == 1)
				return (-1);
			return (0);
		}
		nb = (nb * 10) + *(str) - '0';
		str++;
	}
	return ((int)nb * sign);
}
