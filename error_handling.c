/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykoseki <ykoseki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 01:27:15 by koseki.yusu       #+#    #+#             */
/*   Updated: 2024/06/30 19:42:15 by ykoseki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// 引数のvalidation

int	error_message(void)
{
	ft_printf("%s\n", "Error");
	return (0);
}

int	ft_error_handling(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc == 2 && (argv[1][0] == '\0'
		|| (argv[1][0] == '-' && argv[1][1] == '\0')))
		return (error_message());
	while (i < argc)
	{
		if (!ft_isint(argv[i]))
			return (error_message());
		if (!ft_isunique(argc, argv, argv[i], i))
			return (error_message());
		i++;
	}
	return (1);
}

int	ft_isint(char *argv)
{
	char	*tmp;

	tmp = argv;
	if (*tmp == '-')
		tmp++;
	while (*tmp)
	{
		if (!ft_isdigit(*tmp))
			return (0);
		tmp++;
	}
	if (ft_atoi(argv) < -2147483648 || ft_atoi(argv) > 2147483647)
		return (0);
	return (1);
}

int	ft_isunique(int argc, char **argv, char *str, int index)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (ft_strncmp(str, argv[i], ft_strlen(str)) == 0
			&& ft_strlen(str) == ft_strlen(argv[i]) && i != index)
			return (0);
		i++;
	}
	return (1);
}
