/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusyamas <yuppiy2000@icloud.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 23:34:26 by yusyamas          #+#    #+#             */
/*   Updated: 2022/12/07 11:49:20 by yusyamas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include "rush02.h"

int	print_error(int err_no)
{
	if (err_no == 0)
	{
		ft_putstr("Dict Error\n");
		return (1);
	}
	if (err_no == 1)
	{
		ft_putstr("Error\n");
		return (1);
	}
	return (0);
}
