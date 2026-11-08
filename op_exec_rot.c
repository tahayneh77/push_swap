/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_exec_rot.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maltahay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 20:48:30 by maltahay          #+#    #+#             */
/*   Updated: 2026/11/08 08:41:56 by maltahay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exec_ra(t_stack *a, t_bench *bench)
{
	rotate_up(a);
	record_op("ra", bench);
}

void	exec_rb(t_stack *b, t_bench *bench)
{
	rotate_up(b);
	record_op("rb", bench);
}

void	exec_rr(t_stack *a, t_stack *b, t_bench *bench)
{
	rotate_up(a);
	rotate_up(b);
	record_op("rr", bench);
}
