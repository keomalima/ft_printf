/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kricci-d <kricci-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 14:02:14 by keomalima         #+#    #+#             */
/*   Updated: 2024/11/21 09:04:32 by kricci-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_nbr_len_unsigned(unsigned int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

void	ft_print_uns_to_fd(unsigned int n, int fd)
{
	if (n == 0)
	{
		ft_putchar_fd('0', fd);
		return ;
	}
	if (n > 9)
	{
		ft_print_uns_to_fd(n / 10, fd);
	}
	ft_putchar_fd((n % 10 + '0'), fd);
}

void	ft_print_int(char spec, va_list arg, int *len)
{
	int		nbr;
	char	*str;

	nbr = va_arg(arg, int);
	if (spec == 'd' || spec == 'i')
	{
		str = ft_itoa(nbr);
		(*len) += ft_strlen(str);
		ft_putnbr_fd(nbr, 1);
		free(str);
	}
	else
	{
		(*len) += ft_nbr_len_unsigned((unsigned int)nbr);
		ft_print_uns_to_fd(nbr, 1);
	}
}
