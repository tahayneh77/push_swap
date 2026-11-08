/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_record.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maltahay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 20:49:06 by maltahay          #+#    #+#             */
/*   Updated: 2026/11/07 20:52:39 by maltahay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	count_more(const char *name, t_bench *bench)
{
	if (ft_strcmp(name, "rra") == 0)
		bench->rra++;
	else if (ft_strcmp(name, "rrb") == 0)
		bench->rrb++;
	else if (ft_strcmp(name, "rrr") == 0)
		bench->rrr++;
}

static void	count_op(const char *name, t_bench *bench)
{
	bench->total_ops++;
	if (ft_strcmp(name, "sa") == 0)
		bench->sa++;
	else if (ft_strcmp(name, "sb") == 0)
		bench->sb++;
	else if (ft_strcmp(name, "ss") == 0)
		bench->ss++;
	else if (ft_strcmp(name, "pa") == 0)
		bench->pa++;
	else if (ft_strcmp(name, "pb") == 0)
		bench->pb++;
	else if (ft_strcmp(name, "ra") == 0)
		bench->ra++;
	else if (ft_strcmp(name, "rb") == 0)
		bench->rb++;
	else if (ft_strcmp(name, "rr") == 0)
		bench->rr++;
	else
		count_more(name, bench);
}

void	record_op(const char *name, t_bench *bench)
{
	write(1, name, ft_strlen(name));
	write(1, "\n", 1);
	if (bench)
		count_op(name, bench);
}
