/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusyamas <yuppiy2000@icloud.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 01:35:58 by yusyamas          #+#    #+#             */
/*   Updated: 2022/12/11 21:10:07 by yusyamas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include "rush02.h"

char	*change_str_num(char *num, int digit)
{
	char	*ret;

	ret = malloc(sizeof(char) * (digit + 1));
	(void)ft_strlcpy(ret, num, (unsigned int)(digit + 1));
	free(num);
	return (ret);
}

bool	num_format_check(t_dict *dict, int i, char *num)
{
	int		digit;
	char	*str;

	digit = 0;
	str = num;
	while (*str != '\0' && ft_isdigit(*str))
	{
		digit++;
		str++;
	}
	if (digit > 39)
		return (false);
	while (*str != '\0')
	{
		if (*str != ' ')
			return (false);
		str++;
	}
	dict[i].num = change_str_num(num, digit);
	if ((int)ft_strlen(dict[i].num) != 1 && dict[i].num[0] == '0')
		return (false);
	return (true);
}

void	set_dict_strn(t_dict *dict)
{
	int	i;
	int	j;

	i = 0;
	while (dict[i].num != NULL)
	{
		j = 0;
		while (dict[i].value[j] != NULL)
			j++;
		dict[i].strn = j;
		i++;
	}
}

bool	multiple_1000_check(char *num)
{
	int	maxlen;
	int	i;
	int	ni;

	maxlen = (int)ft_strlen(num);
	if (maxlen == 3 && ft_strcmp(num, "100") == 0)
		return (true);
	i = 0;
	while (i >= 0 && num[maxlen - 1 - i] == '0')
		i++;
	ni = maxlen - i;
	ni += i % 3;
	if (ni == 1 && num[0] == '1')
		return (true);
	return (false);
}

void	set_dict_base_num(t_dict *dict)
{
	int	i;

	i = 0;
	while (dict[i].num != NULL)
	{
		if (multiple_1000_check(dict[i].num))
			dict[i].base_num = 1;
		else
			dict[i].base_num = get_base_num(dict[i].num);
		i++;
	}
}
