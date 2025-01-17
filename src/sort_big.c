/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrasolof <hrasolof@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 14:53:22 by hrasolof          #+#    #+#             */
/*   Updated: 2024/09/15 09:57:24 by hrasolof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_b_to_a(t_list_node **stack_b, t_list_node **stack_a)
{
	int	i;

	while (*stack_b)
	{
		i = list_size(*stack_b);
		if ((*stack_b)->index == i)
			pa(stack_b, stack_a);
		else if (position_in_list((*stack_b), i) <= (list_size(*stack_b) / 2))
		{
			if ((*stack_a) && first_indice(stack_a) < i)
				rr(stack_a, stack_b);
			else
				rb(stack_b);
		}
		else
			rrb(stack_b);
	}
}

void	push_a_to_b(t_list_node **stack_a, t_list_node **stack_b, int min,
		int max)
{
	int	j;

	j = (min + max) / 2;
	while (1)
	{
		if (check_if_indice(*stack_a, min, max) == 0)
			break ;
		if ((*stack_a)->index >= min && (*stack_a)->index <= max)
		{
			pb(stack_a, stack_b);
			if (list_size(*stack_b) >= 2 && check_f_s(stack_b, j))
			{
				if ((*stack_a) && first_indice(stack_a) > max)
					rr(stack_a, stack_b);
				else
					rb(stack_b);
			}
		}
		else
			ra(stack_a);
	}
}

void	sort_big(t_list_node **stack_a, t_list_node **stack_b)
{
	int	maximum;
	int	average;
	int	minimum;

	maximum = list_size(*stack_a);
	if (maximum <= 100)
		average = maximum / 5 + 1;
	else
		average = maximum / 8 - 2;
	maximum = 0;
	while (*stack_a)
	{
		minimum = maximum;
		maximum = average + maximum;
		push_a_to_b(stack_a, stack_b, minimum, maximum);
	}
	push_b_to_a(stack_b, stack_a);
}
