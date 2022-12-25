/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusyamas <yuppiy2000@icloud.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 11:34:51 by yusyamas          #+#    #+#             */
/*   Updated: 2022/12/11 16:19:30 by yusyamas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include "rush02.h"

// int	stdin_run(void)
// {
// }

void	print_rush(t_rush *rush)
{
	int	i;
	int	j;

	i = 0;
	printf("%d\n", rush->state.num);
	while (rush->dict[i].num != NULL)
	{
		printf("dict[%d].strn : %d\n", i, rush->dict[i].strn);
		printf("dict[%d].basenum : %d\n", i, rush->dict[i].base_num);
		printf("dict[%d].num : %s\n", i, rush->dict[i].num);
		j = 0;
		while (rush->dict[i].value[j] != NULL)
		{
			printf("dict[%d].value[%d] : %s\n", i, j, rush->dict[i].value[j]);
			j++;
		}
		i++;
	}
}

int	arg_run(t_rush *rush, char *argnum, char *filepath)
{
	long long	num;

	num = my_atoi(argnum);
	if (num == -1)
		return (print_error(1));
	rush->state.num = (unsigned int)num;
	rush->dict = input_dict(filepath);
	if (rush->dict == NULL)
		return (print_error(0));
	// print_rush(rush);
	rush->key = key_init();
	if (rush->key == NULL)
		return (print_error(0));
	if (!set_dict(rush->dict, rush->key))
		return (print_error(0));
	//print_rush(rush);
	// if (!print_num(rush->state, rush->key))
	// 	return (print_error(0));
	return (0);
}

int	main(int argc, char **argv)
{
	t_rush	rush;

	/*if (argc == 1)
	{
		if (stdin_run())
			return (1);
	}
	else */
	if (argc == 2)
	{
		if (arg_run(&rush, argv[1], "./numbers.dict"))
			return (1);
	}
	else if (argc >= 3)
	{
		if (arg_run(&rush, argv[2], argv[1]))
			return (1);
	}
	return (0);
}
