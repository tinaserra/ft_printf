/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserra <vserra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 18:15:19 by vserra            #+#    #+#             */
/*   Updated: 2020/03/09 16:12:29 by vserra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>
#include "ft_printf.h"

int main()
{
	int w = 12;
	int p = 10;
	char *str = "bonjour yohann";
	int ret_1 = 0;
	int ret_2 = 0;

	// str = NULL;

/* SIMPLE TESTS --------------------------------- */

	printf("\n\n* TYPE S ------------------------- *\n");

	printf("\n* BLOC 1 - Just width *\n");

	ret_1 = printf("coucou {%-0*.*d}\n", INT_MIN, -5, 5);
	ret_2 = ft_printf("coucou {%-0*.*d}\n", INT_MIN, -5, 5);
	printf("ret 1 = %d\nret 2 = %d\n\n", ret_1, ret_2);

	ret_1 = printf("{%s}\n", str);
	ret_2 = ft_printf("{%s}\n", str);
	printf("ret 1 = %d\nret 2 = %d\n\n", ret_1, ret_2);
	ret_1 = printf("{%*s}\n", w, str);
	ret_2 = ft_printf("{%*s}\n", w, str);
	printf("ret 1 = %d\nret 2 = %d\n\n", ret_1, ret_2);
	ret_1 = printf("{%-*s}\n", w, str);
	ret_2 = ft_printf("{%-*s}\n", w, str);
	printf("ret 1 = %d\nret 2 = %d\n\n", ret_1, ret_2);
	ret_1 = printf("{%0*s}\n", w, str);
	ret_2 = ft_printf("{%0*s}\n", w, str);
	printf("ret 1 = %d\nret 2 = %d\n\n", ret_1, ret_2);

	printf("\n\n* BLOC 2 - Width & Precision = 0 *\n");

	ret_1 = printf("{%.s}\n", str);
	ret_2 = ft_printf("{%.s}\n", str);
	printf("ret 1 = %d\nret 2 = %d\n\n", ret_1, ret_2);
	ret_1 = printf("{%*.s}\n", w, str);
	ret_2 = ft_printf("{%*.s}\n", w, str);
	printf("ret 1 = %d\nret 2 = %d\n\n", ret_1, ret_2);
	ret_1 = printf("{%0*.s}\n", w, str);
	ret_2 = ft_printf("{%0*.s}\n", w, str);
	printf("ret 1 = %d\nret 2 = %d\n\n", ret_1, ret_2);
	ret_1 = printf("{%-*.s}\n", w, str);
	ret_2 = ft_printf("{%-*.s}\n", w, str);
	printf("ret 1 = %d\nret 2 = %d\n\n", ret_1, ret_2);

	printf("\n\n* BLOC 3 - Just precision *\n");

	ret_1 = printf("{%.*s}\n", p, str);
	ret_2 = ft_printf("{%.*s}\n", p, str);
	printf("ret 1 = %d\nret 2 = %d\n\n", ret_1, ret_2);
	ret_1 = printf("{%-.*s}\n", p, str);
	ret_2 = ft_printf("{%-.*s}\n", p, str);
	printf("ret 1 = %d\nret 2 = %d\n\n", ret_1, ret_2);
	ret_1 = printf("{%0.*s}\n", p, str);
	ret_2 = ft_printf("{%0.*s}\n", p, str);
	printf("ret 1 = %d\nret 2 = %d\n\n", ret_1, ret_2);

	printf("\n\n* BLOC 4 - Width & Precision *\n");
	
	ret_1 = printf("{%*.*s}\n", w, p, str);
	ret_2 = ft_printf("{%*.*s}\n", w, p, str);
	printf("ret 1 = %d\nret 2 = %d\n\n", ret_1, ret_2);
	ret_1 = printf("{%-*.*s}\n", w, p, str);
	ret_2 = ft_printf("{%-*.*s}\n", w, p, str);
	printf("ret 1 = %d\nret 2 = %d\n\n", ret_1, ret_2);
	ret_1 = printf("{%0*.*s}\n", w, p, str);
	ret_2 = ft_printf("{%0*.*s}\n", w, p, str);
	printf("ret 1 = %d\nret 2 = %d\n\n", ret_1, ret_2);

	printf("\n😎\n");
	return 0;
}

// INT_MAX 2147483647
// UINT_MAX 4294967295