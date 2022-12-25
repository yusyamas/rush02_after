/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusyamas <yuppiy2000@icloud.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 15:08:58 by yusyamas          #+#    #+#             */
/*   Updated: 2022/12/05 10:58:03 by yusyamas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include "rush02.h"

int	x10_overflow_check(long long num)
{
	if (num <= UINT_MAX / 10LL)
		return (0);
	return (1);
}

int	plus_overflow_check(long long num, long long x)
{
	if (num <= UINT_MAX - x)
		return (0);
	return (1);
}

long long	my_atoi(char *str)
{
	long long	ret;
	long long	digit_number;

	ret = 0;
	while (*str != '\0')
	{
		if (x10_overflow_check(ret))
			return (-1);
		ret *= 10;
		if (!('0' <= *str && *str <= '9'))
			return (-1);
		digit_number = *str - '0';
		if (plus_overflow_check(ret, digit_number))
			return (-1);
		ret += digit_number;
		str++;
	}
	return (ret);
}
