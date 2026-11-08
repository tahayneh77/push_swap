/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maltahay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 20:48:48 by maltahay          #+#    #+#             */
/*   Updated: 2026/11/07 20:48:50 by maltahay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	if (argc < 2)
		return (0);
	stack_init(&a);
	stack_init(&b);
	if (!parse_args(argc, argv, &a, NULL))
		ft_error(&a, &b);
	if (a.size == 0)
		return (0);
	read_and_exec(&a, &b);
	if (stack_is_sorted(&a) && b.size == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	stack_clear(&a);
	stack_clear(&b);
	return (0);
}
