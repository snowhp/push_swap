/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-sous <tde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 17:03:58 by tde-sous          #+#    #+#             */
/*   Updated: 2023/05/28 14:54:58 by tde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_doublerevrotate(t_stack **head_a, t_stack **head_b, int checker)
{
	ft_rotatedown(head_a, 0);
	ft_rotatedown(head_b, 0);
	if (checker != 1)
		ft_printf("rrr\n");
}

void	ft_doubleswap(t_stack **head_a, t_stack **head_b, int checker)
{
	ft_swap(head_a, 0);
	ft_swap(head_b, 0);
	if (checker != 1)
		ft_printf("ss\n");
}
