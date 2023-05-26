/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-sous <tde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 17:03:58 by tde-sous          #+#    #+#             */
/*   Updated: 2023/05/26 11:16:21 by tde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_doublerevrotate(t_stack **head_a, t_stack **head_b)
{
	ft_rotatedown(head_a, 0);
	ft_rotatedown(head_b, 0);
	ft_printf("rrr\n");
}

void	ft_doubleswap(t_stack **head_a, t_stack **head_b)
{
	ft_swap(head_a, 0);
	ft_swap(head_b, 0);
	ft_printf("ss\n");
}
