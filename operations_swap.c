/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maltahay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 20:48:01 by maltahay          #+#    #+#             */
/*   Updated: 2026/11/08 08:35:16 by maltahay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_top(t_stack *s)
{
	t_node	*first;
	t_node	*second;

	if (!s || s->size < 2)
		return ;
	first = s->top;
	second = first->next;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	else
		s->bottom = first;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	s->top = second;
}
