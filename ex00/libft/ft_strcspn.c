/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusyamas <yuppiy2000@icloud.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 01:42:33 by yusyamas          #+#    #+#             */
/*   Updated: 2022/12/07 14:16:03 by yusyamas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

unsigned int	ft_strcspn(char *s1, char *s2)
{
	char	*p;
	char	c;
	char	sc;
	char	*spanp;

	p = s1;
	while (1)
	{
		c = *p++;
		spanp = s2;
		while (1)
		{
			sc = *spanp++;
			if (sc == c)
				return (p - 1 - s1);
			if (sc == '\0')
				break ;
		}
	}
}
