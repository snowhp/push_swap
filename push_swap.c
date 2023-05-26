/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-sous <tde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 19:49:48 by tde-sous          #+#    #+#             */
/*   Updated: 2023/05/26 11:44:30 by tde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*head_a;
	t_stack	*head_b;
	char	**argv2;

	if (argc == 1)
		return (0);
	head_a = 0;
	head_b = 0;
	if (argv[1][0] == 0)
		ft_exit(0, &head_a, &head_b);
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
	ft_sortlist(&head_a, &head_b);
	ft_exit(0, &head_a, &head_b);
}
