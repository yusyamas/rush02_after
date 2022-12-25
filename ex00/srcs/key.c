/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusyamas <yuppiy2000@icloud.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 01:50:55 by yusyamas          #+#    #+#             */
/*   Updated: 2022/12/25 19:41:48 by yusyamas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include "rush02.h"

void	key_init_set_num1(t_key *key)
{
	int	cnt;
	int	real;

	real = 0;
	cnt = 0;
	while (real < 20)
	{
		key[cnt].real = real;
		key[cnt].exp = 0;
		key[cnt].value = NULL;
		cnt++;
		real++;
	}
	while (real <= 100)
	{
		key[cnt].real = real;
		key[cnt].exp = 0;
		key[cnt].value = NULL;
		cnt++;
		real += 10;
	}
}

void	key_init_set_num2(t_key *key)
{
	int	cnt;

	cnt = 0;
	while (cnt < 12)
	{
		key[cnt + 29].real = 1;
		key[cnt + 29].exp = cnt;
		key[cnt + 29].value = NULL;
		cnt++;
	}
}

t_key	*key_init(void)
{
	t_key	*ret;

	ret = malloc(sizeof(t_key) * 41);
	if (ret == NULL)
		return (NULL);
	key_init_set_num1(ret);
	key_init_set_num2(ret);
	return (ret);
}

int	set_dict(t_dict *dict, t_key *key)
{
	int	i;
	int	j;

	i = 0;
	while (dict[i].num != NULL)
		i++;
	ft_sort_struct(dict, i);
	if (!dict_decide(dict, key, i))
		return (0);
	return (1);
}
