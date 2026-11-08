/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_exec_rev.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maltahay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 20:48:37 by maltahay          #+#    #+#             */
/*   Updated: 2026/11/08 08:42:38 by maltahay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exec_rra(t_stack *a, t_bench *bench)
{
	rotate_down(a);
	record_op("rra", bench);
}

void	exec_rrb(t_stack *b, t_bench *bench)
{
	rotate_down(b);
	record_op("rrb", bench);
}

void	exec_rrr(t_stack *a, t_stack *b, t_bench *bench)
{
	rotate_down(a);
	rotate_down(b);
	record_op("rrr", bench);
}
