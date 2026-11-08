/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maltahay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 20:48:24 by maltahay          #+#    #+#             */
/*   Updated: 2026/11/08 08:40:38 by maltahay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exec_sa(t_stack *a, t_bench *bench)
{
	swap_top(a);
	record_op("sa", bench);
}

void	exec_sb(t_stack *b, t_bench *bench)
{
	swap_top(b);
	record_op("sb", bench);
}

void	exec_ss(t_stack *a, t_stack *b, t_bench *bench)
{
	swap_top(a);
	swap_top(b);
	record_op("ss", bench);
}

void	exec_pa(t_stack *a, t_stack *b, t_bench *bench)
{
	push_to(a, b);
	record_op("pa", bench);
}

void	exec_pb(t_stack *a, t_stack *b, t_bench *bench)
{
	push_to(b, a);
	record_op("pb", bench);
}
