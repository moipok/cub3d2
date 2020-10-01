/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarbera <login@student.21-school.ru>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 00:49:20 by fbarbera          #+#    #+#             */
/*   Updated: 2020/05/25 01:00:02 by fbarbera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list *a;
	t_list *b;

	a = new;
	b = *lst;
	if (b)
	{
		while (b->next)
			b = b->next;
		b->next = a;
	}
	else
		*lst = a;
}
