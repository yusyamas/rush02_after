/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusyamas <yuppiy2000@icloud.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 19:24:22 by yusyamas          #+#    #+#             */
/*   Updated: 2022/12/07 01:34:25 by yusyamas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include "rush02.h"

void	my_swap(t_dict *d1, t_dict *d2)
{
	t_dict	*tmp;

	tmp = d1;
	d1 = d2;
	d2 = tmp;
}

void	quicksort_cursor_change(t_dict *dict, int *i, int *j, t_dict *pivot)
{
	while (1)
	{
		while (dict[*i].base_num < pivot->base_num)
			*i += 1;
		while (dict[*j].base_num > pivot->base_num)
			*j -= 1;
		if (*i >= *j)
			break ;
		my_swap(&dict[*i], &dict[*j]);
		*i += 1;
		*j -= 1;
	}
	(void)*i;
	(void)*j;
}

void	quicksort(t_dict *dict, int left, int right)
{
	t_dict	pivot;
	int		i;
	int		j;

	i = left;
	j = right;
	pivot = dict[(left + right) / 2];
	quicksort_cursor_change(dict, &i, &j, &pivot);
	if (left < i - 1)
		quicksort(dict, left, i - 1);
	if (j + 1 < right)
		quicksort(dict, j + 1, right);
}

void	ft_sort_struct(t_dict *dict, int size)
{
	if (size == 1)
		return ;
	quicksort(dict, 0, size - 1);
}
