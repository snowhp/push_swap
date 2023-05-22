/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-sous <tde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 22:31:49 by tde-sous          #+#    #+#             */
/*   Updated: 2023/05/22 14:08:53 by tde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_exit(char *erromsg, int exitcode)
{
	if (exitcode != 0)
		ft_printf("Error\n%s", erromsg);
	exit (exitcode);
}
