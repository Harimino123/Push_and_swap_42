/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_setting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrasolof <hrasolof@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 23:48:48 by hrasolof          #+#    #+#             */
/*   Updated: 2024/09/14 14:08:26 by hrasolof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list_node	*create_node(int data)
{
	t_list_node	*new_node;

	new_node = (t_list_node *)malloc(sizeof(t_list_node));
	if (!new_node)
		exit(1);
	new_node->number = data;
	new_node->index = -1;
	new_node->next = NULL;
	return (new_node);
}

void	insert_at_beginning(t_list_node **head, int data)
{
	t_list_node	*new_node;

	new_node = create_node(data);
	new_node->next = *head;
	*head = new_node;
}

void	insert_at_end(t_list_node **head, int data)
{
	t_list_node	*new_node;
	t_list_node	*temp;

	new_node = create_node(data);
	if (*head == NULL)
	{
		*head = new_node;
		return ;
	}
	temp = *head;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = new_node;
}

void	free_list(t_list_node **list)
{
	t_list_node	*temp;

	while (*list != NULL)
	{
		temp = *list;
		*list = (*list)->next;
		free(temp);
	}
}

int	list_size(t_list_node *list)
{
	int	size;

	size = 0;
	while (list != NULL)
	{
		size++;
		list = list->next;
	}
	return (size);
}
