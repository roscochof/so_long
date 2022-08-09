/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzana <amarzana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 16:17:08 by amarzana          #+#    #+#             */
/*   Updated: 2022/08/09 17:43:15 by amarzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	ft_check_perim(t_control *control)
{
	char	**aux;
	int		i;

	i = -1;
	aux = control->map;
	while (aux[0][++i])
		if (aux[0][i] != '1')
			control->error = 1;
	control->width = i;
	i = -1;
	while (aux[++i])
		if (aux[i][0] != '1' || aux[i][control->width - 1] != '1')
			control->error = 1;
	i = -1;
	while (aux[control->height - 1][++i])
		if (aux[control->height - 1][i] != '1')
			control->error = 1;
}

static void	ft_check_form(t_control *control)
{
	int		i;
	int		j;
	char	**aux;

	i = 0;
	aux = control->map;
	while (aux[i])
	{
		j = 0;
		while (aux[i][j])
		{
			j++;
		}
		if (j != control->width)
			control->error = 2;
		i++;
	}
	if (i != control->height)
			control->error = 2;
}

static void	ft_check_elem(t_control *control, char c)
{
	char	**aux;
	int		i;
	int		j;
	int		flag;

	aux = control->map;
	flag = 0;
	i = -1;
	while (++i < control->height)
	{
		j = -1;
		while (++j < control->width)
			if (aux[i][j] == c)
				flag = 1;
	}
	if (flag == 0)
		control->error = 3;
}

static void	ft_print_errors(t_control *control)
{
	if (control->error == 1)
	{
		ft_putstr_fd("Error\nThe map must be closed/surrounded by walls.\n", 2);
		ft_free(control->map);
		exit(0);
	}
	if (control->error == 2)
	{
		ft_putstr_fd("Error\nThe map must be rectangular.\n", 2);
		ft_free(control->map);
		exit(0);
	}
	if (control->error == 3)
	{
		ft_putstr_fd("Error\nThe map must contain at least 1 exit,\
 1 collectible, and 1 starting position.\n", 2);
		ft_free(control->map);
		exit(0);
	}
}

void	ft_checks(t_control *control)
{
	ft_check_perim(control);
	ft_check_form(control);
	ft_check_elem(control, 'P');
	ft_check_elem(control, 'C');
	ft_check_elem(control, 'E');
	ft_print_errors(control);
}
