#include "main.h"

t_node	*init_list(char *line)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (new_node == NULL)
		exit (-666);
	new_node -> line = line;
	new_node -> next_node = NULL;
	return (new_node);
}

void	append_to_list(t_node *head_node, char *line)
{
	t_node	*new_end_node;

	new_end_node = (t_node *)malloc(sizeof(t_node));
	if (new_end_node == NULL)
		exit (-666);
	while (head_node -> next_node != NULL)
		head_node = head_node -> next_node;
	head_node -> next_node = new_end_node;
	new_end_node -> line = line;
	new_end_node -> next_node = NULL;
}

t_node	*remove_head_node(t_node *head_node)
{
	t_node	*new_head_node;

	new_head_node = head_node -> next_node;
	free(head_node);
	return (new_head_node);
}

void	clear_list(t_node *head)
{
	if (!head)
		return ;
	while (head)
	{
		free(head->line);
		head = remove_head_node(head);
	}
}
