/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decide2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusyamas <yuppiy2000@icloud.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 15:48:59 by yusyamas          #+#    #+#             */
/*   Updated: 2022/12/12 18:25:52 by yusyamas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include "rush02.h"

bool	is_key_decided(t_key *key, int real, int exp)
{
	int	i;

	i = 0;
	while (i < 41)
	{
		if (real == key[i].real && exp == key[i].exp)
		{
			if (key[i].value != NULL)
				return (true);
			else
				return (false);
		}
		i++;
	}
	return (false);
}

int	get_base_num_drun2(int i, char *num, int len)
{
	int	ret;

	ret = 0;
	if (i % 3 == 2)
	{
		if (is_key_decided(key, num[len - 1 - i] - '0', 0))
			ret++;
		if (is_key_decided(key, 100, 0))
			ret++;
	}
	if (i % 3 == 1 && '1' < num[len - 1 - i])
		if (is_key_decided(key, (num[len - 1 - i] - '0') * 10, 0))
			ret++;
	if (i % 3 == 1 && '1' == num[len - 1 - i])
		if (is_key_decided(key, (num[len - i] - '0') + 10, 0))
			ret++;
	if (i % 3 == 0)
		if (is_key_decided(key, num[len - 1 - i] - '0', 0))
			ret++;
	return (ret);
}

int	get_base_num_drun(t_key *key, char *num, int len)
{
	int	i;
	int	ret;

	i = len - 1;
	ret = 0;
	while (i >= 0)
	{
		if (num[len - 1 - i] != '0')
		{
			ret += get_base_num_drun2(i, num, len);
			if (i % 3 == 1 && '1' == num[len - 1 - i])
				i--;
		}
		if (digit1000_check(i, num, len) && i % 3 == 0 && i >= 3)
			if (is_key_decided(key, 1, i))
				ret++;
		i--;
	}
	return (ret);
}

int	get_base_num_dict(t_key *key, char *num)
{
	int	ret;
	int	len;

	len = (int)ft_strlen(num);
	if (len == 1 && num[0] == '0')
		if (is_key_decided(key, 0ull, 0u))
			return (1);
	ret = get_base_num_drun(key, num, len);
	return (ret);
}
