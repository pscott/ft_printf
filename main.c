/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscott <pscott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 17:28:09 by pscott            #+#    #+#             */
/*   Updated: 2018/12/19 15:15:37 by pscott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
	char *c;

	c = "%c%c%c\n";

	ft_printf(c, 0, 0, 0); 
	   printf(c, 0, 0, 0); 
	   return (0);
}
