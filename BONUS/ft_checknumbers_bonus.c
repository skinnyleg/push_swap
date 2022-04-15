/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checknumbers_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoubal <hmoubal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 23:18:43 by haitam            #+#    #+#             */
/*   Updated: 2022/04/15 08:56:21 by hmoubal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

void	ft_cont_bonus(char **num, int k, int j, int *sum)
{
	while (num[k])
	{
		j = 0;
		while (num[k][j])
		{
			j = ft_count_bonus(num, k, j);
			if (ft_isdigit(num[k][j]) == 0)
				ft_error_bonus(num);
			j++;
		}
		k++;
	}
	(*sum) += k;
}

int	ft_count_bonus(char **str, int k, int j)
{
	while (str[k][j] == ' ')
		j++;
	if (str[k][j] == '-' || str[k][j] == '+')
		j++;
	return (j);
}

void	ft_free_all_bonus(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}

int	ft_checknumbers_bonus(char **av)
{
	t_int	var;
	char	**num;
	int		sum;

	var.i = 1;
	sum = 0;
	num = NULL;
	var.j = 0;
	while (av[var.i])
	{
		var.k = 0;
		num = ft_split(av[var.i], 32);
		ft_malloc_bonus(num);
		if (num[var.k] == NULL)
			ft_error_bonus(num);
		ft_cont_bonus(num, var.k, var.j, &sum);
		ft_free_all_bonus(num);
		(var.i)++;
	}
	return (sum);
}