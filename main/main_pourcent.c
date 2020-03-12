/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_pourcent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserra <vserra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 18:15:19 by vserra            #+#    #+#             */
/*   Updated: 2020/03/11 20:56:50 by vserra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>
#include "../includes/ft_printf.h"

int main()
{
	int ret_1 = 0;
	int ret_2 = 0;

	int w = 18; // Change width here !
	int p = 12; // Change precision here !

/* SIMPLE TESTS --------------------------------- */

	printf("\n\n* TYPE %% ------------------------- *\n");

	printf("\n* BLOC 0 - Just % & flags *\n\n");

	ret_1 = printf("{%%}\n");
	ret_2 = ft_printf("{%%}\n");
	printf("%d | %d\n\n", ret_1, ret_2);
	ret_1 = printf("{%0%}\n");
	ret_2 = ft_printf("{%0%}\n");
	printf("%d | %d\n\n", ret_1, ret_2);
	ret_1 = printf("{%-%}\n");
	ret_2 = ft_printf("{%-%}\n");
	printf("%d | %d\n\n", ret_1, ret_2);

	printf("\n* BLOC 1 - Just width *\n\n");

	ret_1 = printf("{%*%}\n", w);
	ret_2 = ft_printf("{%*%}\n", w);
	printf("%d | %d\n\n", ret_1, ret_2);
	ret_1 = printf("{%-*%}\n", w);
	ret_2 = ft_printf("{%-*%}\n", w);
	printf("%d | %d\n\n", ret_1, ret_2);
	ret_1 = printf("{%0*%}\n", w);
	ret_2 = ft_printf("{%0*%}\n", w);
	printf("%d | %d\n\n", ret_1, ret_2);

	printf("\n\n* BLOC 2 - Width & Precision = 0 *\n\n");

	ret_1 = printf("{%.%}\n");
	ret_2 = ft_printf("{%.%}\n");
	printf("%d | %d\n\n", ret_1, ret_2);
	ret_1 = printf("{%*.%}\n", w);
	ret_2 = ft_printf("{%*.%}\n", w);
	printf("%d | %d\n\n", ret_1, ret_2);
	ret_1 = printf("{%0*.%}\n", w);
	ret_2 = ft_printf("{%0*.%}\n", w);
	printf("%d | %d\n\n", ret_1, ret_2);
	ret_1 = printf("{%-*.%}\n", w);
	ret_2 = ft_printf("{%-*.%}\n", w);
	printf("%d | %d\n\n", ret_1, ret_2);

	printf("\n\n* BLOC 3 - Just precision *\n\n");

	ret_1 = printf("{%.*%}\n", p);
	ret_2 = ft_printf("{%.*%}\n", p);
	printf("%d | %d\n\n", ret_1, ret_2);
	ret_1 = printf("{%-.*%}\n", p);
	ret_2 = ft_printf("{%-.*%}\n", p);
	printf("%d | %d\n\n", ret_1, ret_2);
	ret_1 = printf("{%0.*%}\n", p);
	ret_2 = ft_printf("{%0.*%}\n", p);
	printf("%d | %d\n\n", ret_1, ret_2);

	printf("\n\n* BLOC 4 - Width & Precision *\n\n");
	
	ret_1 = printf("{%*.*%}\n", w, p);
	ret_2 = ft_printf("{%*.*%}\n", w, p);
	printf("%d | %d\n\n", ret_1, ret_2);
	ret_1 = printf("{%-*.*%}\n", w, p);
	ret_2 = ft_printf("{%-*.*%}\n", w, p);
	printf("%d | %d\n\n", ret_1, ret_2);
	ret_1 = printf("{%0*.*%}\n", w, p);
	ret_2 = ft_printf("{%0*.*%}\n", w, p);
	printf("%d | %d\n\n", ret_1, ret_2);

	printf("\n😎\n");
	return 0;
}

// INT_MAX 2147483647
// UINT_MAX 4294967295