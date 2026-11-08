/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maltahay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 20:48:08 by maltahay          #+#    #+#             */
/*   Updated: 2026/11/08 08:43:28 by maltahay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_up(t_stack *s)
{
	t_node	*node;

	if (!s || s->size < 2)
		return ;
	node = s->top;
	s->top = node->next;
	s->top->prev = NULL;
	node->next = NULL;
	node->prev = s->bottom;
	s->bottom->next = node;
	s->bottom = node;
}
