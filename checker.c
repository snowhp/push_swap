/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-sous <tde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 10:05:32 by tde-sous          #+#    #+#             */
/*   Updated: 2023/05/26 13:58:22 by tde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"
#include "./get_next_line/get_next_line.h"

int	main(int argc, char **argv)
{
	char	**argv2;
	t_stack	*head_a;
	t_stack	*head_b;

	if (argc == 1)
		return (0);
	head_a = 0;
	head_b = 0;
	if (argv[1][0] == 0)
		ft_exit(0, NULL, NULL);
	if (argc == 2)
	{
		argv2 = ft_split(argv[1], ' ');
		if (argv2[0] == 0)
		{
			ft_freearray(argv2);
			ft_exit(0, &head_a, &head_b);
		}
		ft_insertlist(&head_a, argv2, 0);
		ft_freearray(argv2);
	}
	else
		ft_insertlist(&head_a, argv, 1);
	ft_execmove(&head_a, &head_b);
	ft_exit(0, &head_a, &head_b);
}

void	ft_execmove(t_stack **head_a, t_stack **head_b)
{
	char	*move;

	move = ft_strdup("");
	while (move)
	{
		if (move[0] != '\0')
			ft_moves(move, ft_strlen(move), head_a, head_b);
		free(move);
		move = get_next_line(STDIN_FILENO);
	}
	free(move);
	ft_checkerverification(head_a, head_b);
}

int	ft_moves(char *move, int size, t_stack **head_a, t_stack **head_b)
{
	if (!ft_strncmp(move, "sa\n", size))
		ft_swap(head_a, 0);
	else if (!ft_strncmp(move, "sb\n", size))
		ft_swap(head_b, 0);
	else if (!ft_strncmp(move, "ss\n", size))
		ft_doubleswap(head_a, head_b);
	else if (!ft_strncmp(move, "pa\n", size))
		ft_push(head_b, head_a, 0);
	else if (!ft_strncmp(move, "pb\n", size))
		ft_push(head_a, head_b, 0);
	else if (!ft_strncmp(move, "ra\n", size))
		ft_rotateup(head_a, 0);
	else if (!ft_strncmp(move, "rb\n", size))
		ft_rotateup(head_b, 0);
	else if (!ft_strncmp(move, "rr\n", size))
		ft_doublerotate(head_a, head_b);
	else if (!ft_strncmp(move, "rra\n", size))
		ft_rotatedown(head_a, 0);
	else if (!ft_strncmp(move, "rrb\n", size))
		ft_rotatedown(head_b, 0);
	else if (!ft_strncmp(move, "rrr\n", size))
		ft_doublerevrotate(head_a, head_b);
	else
		return (0);
	return (1);
}
