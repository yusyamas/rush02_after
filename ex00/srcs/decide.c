/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decide.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusyamas <yuppiy2000@icloud.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 00:08:45 by yusyamas          #+#    #+#             */
/*   Updated: 2022/12/12 15:43:21 by yusyamas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include "rush02.h"

int	decide_2(t_dict *dict, t_key *key)
{
	int	max;
	int	n;

	max = dict->base_num;
	n = get_base_num_dict(key, dict->num);
	if (n == max - 1)
	{
		if (decide_key(dict, key))
			return (1);
		else
			return (-1);
	}
	else if (n == max)
	{
		if (from_before_same_check(dict, key, max))
			return (1);
		else
			return (-1);
	}
	else
		return (0);
}

int	decide_1(t_dict *dict, t_key *key, int n)
{
	int	i;
	int	flag;

	i = 0;
	while (dict[i].num != NULL)
	{
		if (dict[i].flag)
		{
			flag = decide_2(&dict[i], key);
			if (flag == 1)
				n--;
			else if (flag == -1)
				return (-1);
		}
		i++;
	}
	return (n);
}

bool	dict_decide(t_dict *dict, t_key *key, int maxn)
{
	int	n;

	n = maxn;
	while (n > 0)
	{
		n = decide_1(dict, key, n);
		if (n == -1)
			return (false);
		if (n == maxn)
			return (false);
		maxn = n;
	}
	return (true);
}
