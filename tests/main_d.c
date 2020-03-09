/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserra <vserra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 18:15:19 by vserra            #+#    #+#             */
/*   Updated: 2020/03/09 16:52:24 by vserra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>
#include "ft_printf.h"

int main()
{
	int w = 12;
	int p = 10;
	int nb = 0;
	int ret_1 = 0;
	int ret_2 = 0;

/* SIMPLE TESTS --------------------------------- */

	printf("\n\n* TYPE D ------------------------- *\n");

	printf("\n* BLOC 1 - Just width *\n\n");

	ret_1 = printf("{%d}\n", nb);
	ret_2 = ft_printf("{%d}\n", nb);
	printf("%d | %d\n\n", ret_1, ret_2);
	ret_1 = printf("{%*d}\n", w, nb);
	ret_2 = ft_printf("{%*d}\n", w, nb);
	printf("%d | %d\n\n", ret_1, ret_2);
	ret_1 = printf("{%-*d}\n", w, nb);
	ret_2 = ft_printf("{%-*d}\n", w, nb);
	printf("%d | %d\n\n", ret_1, ret_2);
	ret_1 = printf("{%0*d}\n", w, nb);
	ret_2 = ft_printf("{%0*d}\n", w, nb);
	printf("%d | %d\n\n", ret_1, ret_2);

	printf("\n\n* BLOC 2 - Width & Precision = 0 *\n\n");

	ret_1 = printf("{%.d}\n", nb);
	ret_2 = ft_printf("{%.d}\n", nb);
	printf("%d | %d\n\n", ret_1, ret_2);
	ret_1 = printf("{%*.d}\n", w, nb);
	ret_2 = ft_printf("{%*.d}\n", w, nb);
	printf("%d | %d\n\n", ret_1, ret_2);
	ret_1 = printf("{%0*.d}\n", w, nb);
	ret_2 = ft_printf("{%0*.d}\n", w, nb);
	printf("%d | %d\n\n", ret_1, ret_2);
	ret_1 = printf("{%-*.d}\n", w, nb);
	ret_2 = ft_printf("{%-*.d}\n", w, nb);
	printf("%d | %d\n\n", ret_1, ret_2);

	printf("\n\n* BLOC 3 - Just precision *\n\n");

	ret_1 = printf("{%.*d}\n", p, nb);
	ret_2 = ft_printf("{%.*d}\n", p, nb);
	printf("%d | %d\n\n", ret_1, ret_2);
	ret_1 = printf("{%-.*d}\n", p, nb);
	ret_2 = ft_printf("{%-.*d}\n", p, nb);
	printf("%d | %d\n\n", ret_1, ret_2);
	ret_1 = printf("{%0.*d}\n", p, nb);
	ret_2 = ft_printf("{%0.*d}\n", p, nb);
	printf("%d | %d\n\n", ret_1, ret_2);

	printf("\n\n* BLOC 4 - Width & Precision *\n\n");
	
	ret_1 = printf("{%*.*d}\n", w, p, nb);
	ret_2 = ft_printf("{%*.*d}\n", w, p, nb);
	printf("%d | %d\n\n", ret_1, ret_2);
	ret_1 = printf("{%-*.*d}\n", w, p, nb);
	ret_2 = ft_printf("{%-*.*d}\n", w, p, nb);
	printf("%d | %d\n\n", ret_1, ret_2);
	ret_1 = printf("{%0*.*d}\n", w, p, nb);
	ret_2 = ft_printf("{%0*.*d}\n", w, p, nb);
	printf("%d | %d\n\n", ret_1, ret_2);

	printf("\n😎\n");
	return 0;
}

// INT_MAX 2147483647
// UINT_MAX 4294967295