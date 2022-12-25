/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusyamas <yuppiy2000@icloud.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 00:28:22 by yusyamas          #+#    #+#             */
/*   Updated: 2022/12/10 19:07:44 by yusyamas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include "rush02.h"

int	is_delim(char c, char *charset)
{
	while (*charset != '\0')
	{
		if (c == *charset)
			return (1);
		charset++;
	}
	return (0);
}

int	get_spn_size(char *str, char *charset)
{
	int	ret;

	ret = 0;
	while (*str != '\0')
	{
		while (*str != '\0' && is_delim(*str, charset))
			str++;
		if (*str == '\0')
			break ;
		str += ft_strcspn(str, charset);
		while (*str != '\0' && !is_delim(*str, charset))
			str++;
		ret++;
	}
	return (ret);
}

char	**set_split(char **ret, char *str, char *charset)
{
	int	i;
	int	len;

	i = 0;
	while (*str != '\0')
	{
		while (*str != '\0' && is_delim(*str, charset))
			str++;
		if (*str == '\0')
			break ;
		len = (int)ft_strcspn(str, charset);
		ret[i] = malloc(sizeof(char) * (len + 1));
		(void)ft_strlcpy(ret[i], str, len + 1);
		while (*str != '\0' && !is_delim(*str, charset))
			str++;
		i++;
	}
	return (ret);
}

char	**ft_split(char *str, char *charset)
{
	int		size;
	char	**ret;

	size = get_spn_size(str, charset);
	ret = malloc(sizeof(char *) * (size + 1));
	ret[size] = NULL;
	set_split(ret, str, charset);
	return (ret);
}

// int	main(int argc, char **argv)
// {
// 	char	**buff;
// 	int		i;

// 	buff = ft_split(argv[1], argv[2]);
// 	(void)argc;
// 	i = 0;
// 	while (buff[i] != NULL)
// 	{
// 		printf("buff[%d] : %s\n", i, buff[i]);
// 		i++;
// 	}
// }
