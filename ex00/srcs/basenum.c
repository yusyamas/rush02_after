/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basenum.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusyamas <yuppiy2000@icloud.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 15:48:59 by yusyamas          #+#    #+#             */
/*   Updated: 2022/12/12 18:21:40 by yusyamas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include "rush02.h"

int	get_base_num_run(int i, char *num, int len)
{
	int	ret;

	ret = 0;
	if (i % 3 == 2)
		ret += 2;
	else if (i % 3 == 1 && '1' < num[len - 1 - i])
		ret++;
	else if (i % 3 == 1 && '1' == num[len - 1 - i])
		ret++;
	else if (i % 3 == 0)
		ret++;
	return (ret);
}

bool	digit1000_check(int i, char *num, int len)
{
	int	max;

	max = ft_min(len, i + 3);
	while (i < max)
	{
		if (num[len - 1 - i] != '0')
			return (true);
		i++;
	}
	return (false);
}

int	get_base_num(char *num)
{
	int	ret;
	int	i;
	int	len;

	ret = 0;
	len = (int)ft_strlen(num);
	if (len == 1 && num[0] == '0')
		return (1);
	i = len - 1;
	while (i >= 0)
	{
		if (num[len - 1 - i] != '0')
		{
			ret += get_base_num_run(i, num, len);
			if (i % 3 == 1 && '1' == num[len - 1 - i])
				i--;
		}
		if (digit1000_check(i, num, len) && i % 3 == 0 && i >= 3)
			ret++;
		i--;
	}
	return (ret);
}
