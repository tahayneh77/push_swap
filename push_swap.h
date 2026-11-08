/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maltahay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 20:47:36 by maltahay          #+#    #+#             */
/*   Updated: 2026/11/08 08:43:03 by maltahay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

# define STRAT_DEFAULT 0
# define STRAT_SIMPLE 1
# define STRAT_MEDIUM 2
# define STRAT_COMPLEX 3
# define STRAT_ADAPTIVE 4

typedef struct s_node
{
	int				val;
	int				index;
	int				pos;
	int				cost_a;
	int				cost_b;
	int				above_med;
	struct s_node	*target;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

typedef struct s_stack
{
	t_node			*top;
	t_node			*bottom;
	int				size;
}					t_stack;

typedef struct s_bench
{
	int				enabled;
	int				strat;
	int				chosen;
	double			disorder;
	int				total_ops;
	int				sa;
	int				sb;
	int				ss;
	int				pa;
	int				pb;
	int				ra;
	int				rb;
	int				rr;
	int				rra;
	int				rrb;
	int				rrr;
}					t_bench;

int					ft_strlen(const char *str);
void				ft_putstr_fd(const char *str, int fd);
void				ft_putnbr_fd(long n, int fd);
int					ft_strcmp(const char *s1, const char *s2);
void				ft_error(t_stack *a, t_stack *b);

int					ft_isspace(char c);
int					ft_issign(char c);
int					ft_atol(const char *str, long *out);
void				ft_free_split(char **tab);

char				**ft_split_spaces(const char *s);

int					parse_args(int argc, char **argv, t_stack *a,
						t_bench *bench);

void				stack_init(t_stack *stack);
t_node				*node_new(int val);
int					stack_push_bottom(t_stack *stack, int val);
void				stack_clear(t_stack *stack);
int					stack_is_sorted(t_stack *stack);

t_node				*find_min_node(t_stack *stack);
t_node				*find_max_node(t_stack *stack);
void				assign_positions(t_stack *stack);
void				assign_indices(t_stack *stack);
int					abs_val(int n);

void				swap_top(t_stack *s);

void				push_to(t_stack *dst, t_stack *src);

void				rotate_up(t_stack *s);

void				rotate_down(t_stack *s);

void				record_op(const char *name, t_bench *bench);

void				exec_sa(t_stack *a, t_bench *bench);
void				exec_sb(t_stack *b, t_bench *bench);
void				exec_ss(t_stack *a, t_stack *b, t_bench *bench);
void				exec_pa(t_stack *a, t_stack *b, t_bench *bench);
void				exec_pb(t_stack *a, t_stack *b, t_bench *bench);

void				exec_ra(t_stack *a, t_bench *bench);
void				exec_rb(t_stack *b, t_bench *bench);
void				exec_rr(t_stack *a, t_stack *b, t_bench *bench);

void				exec_rra(t_stack *a, t_bench *bench);
void				exec_rrb(t_stack *b, t_bench *bench);
void				exec_rrr(t_stack *a, t_stack *b, t_bench *bench);

double				compute_disorder(t_stack *stack);

void				bench_print(t_bench *bench);

void				sort_three(t_stack *a, t_bench *bench);
void				sort_small(t_stack *a, t_stack *b, t_bench *bench);

void				sort_simple(t_stack *a, t_stack *b, t_bench *bench);

void				sort_medium(t_stack *a, t_stack *b, t_bench *bench);

t_node				*find_target_b(t_node *a_n, t_stack *b);
void				set_targets_b(t_stack *a, t_stack *b);
t_node				*find_target_a(t_node *b_n, t_stack *a);

void				calc_costs(t_stack *a, t_stack *b);
t_node				*find_cheapest(t_stack *a);
void				rotate_both(t_stack *a, t_stack *b, t_node *cheap,
						t_bench *bench);
void				finish_rotations(t_stack *a, t_stack *b, t_node *cheap,
						t_bench *bench);

void				sort_complex(t_stack *a, t_stack *b, t_bench *bench);

int					read_line(int fd, char **line);
int					apply_op(const char *op, t_stack *a, t_stack *b);
void				read_and_exec(t_stack *a, t_stack *b);

#endif
