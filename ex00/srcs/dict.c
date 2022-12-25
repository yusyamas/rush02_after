/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusyamas <yuppiy2000@icloud.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 23:46:00 by yusyamas          #+#    #+#             */
/*   Updated: 2022/12/11 16:04:25 by yusyamas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include "rush02.h"

char	**dict_split_newline(char *filename)
{
	char	**ret;
	char	*buff;

	buff = input_str(filename);
	if (buff == NULL)
		return (NULL);
	ret = ft_split(buff, "\n");
	free(buff);
	return (ret);
}

int	get_bdict_size(char **buff_dict)
{
	int	size;
	int	i;

	size = 0;
	i = 0;
	while (buff_dict[i] != NULL)
	{
		i++;
		size++;
	}
	return (size);
}

bool	dict_format_check(char *str)
{
	while (*str != '\0')
	{
		if (*str == ':')
			return (true);
		str++;
	}
	return (false);
}

t_dict	*storage_dict(t_dict *ret, char **buff_dict, int size)
{
	int		i;
	char	*str;
	int		len;

	i = 0;
	while (i < size)
	{
		str = buff_dict[i];
		if (!dict_format_check(str))
			return (NULL);
		len = (int)ft_strcspn(str, ":");
		ret[i].num = malloc(sizeof(char) * (len + 1));
		(void)ft_strlcpy(ret[i].num, str, (unsigned int)(len + 1));
		if (!num_format_check(ret, i, ret[i].num))
			return (NULL);
		str += len + 1;
		ret[i].value = ft_split(str, " ");
		i++;
	}
	ret[size].num = NULL;
	return (ret);
}

t_dict	*input_dict(char *filename)
{
	t_dict	*ret;
	char	**buff_dict;
	int		size;

	buff_dict = dict_split_newline(filename);
	// ret = NULL;
	// (void)buff_dict;
	// (void)size;
	if (buff_dict == NULL)
		return (NULL);
	size = get_bdict_size(buff_dict);
	ret = malloc(sizeof(t_dict) * (size + 1));
	if (storage_dict(ret, buff_dict, size) == NULL)
	{
		free(buff_dict);
		return (NULL);
	}
	//printf("storage_dict ended\n");
	free(buff_dict);
	set_dict_strn(ret);
	set_dict_base_num(ret);
	return (ret);
}
