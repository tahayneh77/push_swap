/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_reverse.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maltahay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 20:48:13 by maltahay          #+#    #+#             */
/*   Updated: 2026/11/08 08:43:37 by maltahay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_down(t_stack *s)
{
	t_node	*node;

	if (!s || s->size < 2)
		return ;
	node = s->bottom;
	s->bottom = node->prev;
	s->bottom->next = NULL;
	node->prev = NULL;
	node->next = s->top;
	s->top->prev = node;
	s->top = node;
}
