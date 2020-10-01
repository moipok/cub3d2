/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarbera <login@student.21-school.ru>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 00:43:21 by fbarbera          #+#    #+#             */
/*   Updated: 2020/05/25 01:01:02 by fbarbera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		a;
	t_list	*b;

	a = 1;
	if (lst == 0)
		return (0);
	b = lst;
	while (b->next)
	{
		b = b->next;
		a++;
	}
	return (a);
}
