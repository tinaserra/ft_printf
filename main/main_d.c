/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserra <vserra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 18:15:19 by vserra            #+#    #+#             */
/*   Updated: 2020/03/10 21:26:46 by vserra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>
#include "ft_printf.h"

// ".1 {%s}  .2 {%-s}  .3 {%0s}\n"
// ".4 {%*s}  .5 {%-*s}  .6 {%0*s}\n"
// ".7 {%.d}  8. {%*.s}  9. {%0*.s}  .10 {%-*.s}\n"
// ".11 {%.*s}  .12 {%-.*s}  .13 {%0.*s}\n"
// ".14 {%*.*s}  .15 {%0*.*s}  .16 {%-*.*s}\n"

int main()
{
	int w = 19;
	int p = 14;
	int nb = 42;
	int ret_1 = 0;
	int ret_2 = 0;

/* SIMPLE TESTS --------------------------------- */

	printf("\n\n* SIMPLE TESTS ------------------------------------------ *\n");

	printf("\n\n* TYPE D ------------------------- *\n");

	printf("\n* BLOC 0 - Just d & flags *\n\n");

	ret_1 = printf("{%d}\n", nb);
	ret_2 = ft_printf("{%d}\n", nb);
	printf("%d | %d\n\n", ret_1, ret_2);
	ret_1 = printf("{%0d}\n", nb);
	ret_2 = ft_printf("{%0d}\n", nb);
	printf("%d | %d\n\n", ret_1, ret_2);
	ret_1 = printf("{%-d}\n", nb);
	ret_2 = ft_printf("{%-d}\n", nb);
	printf("%d | %d\n\n", ret_1, ret_2);

	printf("\n* BLOC 1 - Just width *\n\n");

	ret_1 = printf("{%d}\n", w, nb);
	ret_2 = ft_printf("{%d}\n", w, nb);
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

/* OTHER TESTS --------------------------------- */

	printf("\n\n* OTHER TESTS ------------------------------------------- *\n");

	nb = 0; w = 0; p = 0;
	printf("\n🔥  TEST nb = %d | width = %d | precision = %d 🔥\n", nb, w, p);
	printf("-----\n");
	ret_1 = printf(".1 {%d}  .2 {%-d}  .3 {%0d}\n", nb, nb, nb);
	ret_2 = ft_printf(".1 {%d}  .2 {%-d}  .3 {%0d}\n", nb, nb, nb);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);
	ret_1 = printf(".4 {%*d}  .5 {%-*d}  .6 {%0*d}\n", w, nb, w, nb, w, nb);
	ret_2 = ft_printf(".4 {%*d}  .5 {%-*d}  .6 {%0*d}\n", w, nb, w, nb, w, nb);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);
	ret_1 = printf(".7 {%.d}  8. {%*.d}  9. {%0*.d}  .10 {%-*.d}\n", nb, w, nb, w, nb, w, nb);
	ret_2 = ft_printf(".7 {%.d}  8. {%*.d}  9. {%0*.d}  .10 {%-*.d}\n", nb, w, nb, w, nb, w, nb);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);
	ret_1 = printf(".11 {%.*d}  .12 {%-.*d}  .13 {%0.*d}\n", p, nb, p, nb, p, nb);
	ret_2 = ft_printf(".11 {%.*d}  .12 {%-.*d}  .13 {%0.*d}\n", p, nb, p, nb, p, nb);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);
	ret_1 = printf(".14 {%*.*d}  .15 {%0*.*d}  .16 {%-*.*d}  .17 {%-0*.*d}\n", w, p, nb, w, p, nb, w, p, nb, w, p, nb);
	ret_2 = ft_printf(".14 {%*.*d}  .15 {%0*.*d}  .16 {%-*.*d}  .17 {%-0*.*d}\n", w, p, nb, w, p, nb, w, p, nb, w, p, nb);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);


	nb = 1; w = 0; p = 0;
	printf("\n😘  TEST nb = %d | width = %d | precision = %d 😘\n", nb, w, p);
	printf("-----\n");
	ret_1 = printf(".1 {%d}  .2 {%-d}  .3 {%0d}\n", nb, nb, nb);
	ret_2 = ft_printf(".1 {%d}  .2 {%-d}  .3 {%0d}\n", nb, nb, nb);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);
	ret_1 = printf(".4 {%*d}  .5 {%-*d}  .6 {%0*d}\n", w, nb, w, nb, w, nb);
	ret_2 = ft_printf(".4 {%*d}  .5 {%-*d}  .6 {%0*d}\n", w, nb, w, nb, w, nb);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);
	ret_1 = printf(".7 {%.d}  8. {%*.d}  9. {%0*.d}  .10 {%-*.d}\n", nb, w, nb, w, nb, w, nb);
	ret_2 = ft_printf(".7 {%.d}  8. {%*.d}  9. {%0*.d}  .10 {%-*.d}\n", nb, w, nb, w, nb, w, nb);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);
	ret_1 = printf(".11 {%.*d}  .12 {%-.*d}  .13 {%0.*d}\n", p, nb, p, nb, p, nb);
	ret_2 = ft_printf(".11 {%.*d}  .12 {%-.*d}  .13 {%0.*d}\n", p, nb, p, nb, p, nb);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);
	ret_1 = printf(".14 {%*.*d}  .15 {%0*.*d}  .16 {%-*.*d}  .17 {%-0*.*d}\n", w, p, nb, w, p, nb, w, p, nb, w, p, nb);
	ret_2 = ft_printf(".14 {%*.*d}  .15 {%0*.*d}  .16 {%-*.*d}  .17 {%-0*.*d}\n", w, p, nb, w, p, nb, w, p, nb, w, p, nb);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);


	nb = 4568; w = 20; p = 9;
	printf("\n🌸  TEST nb = %d | width = %d | precision = %d 🌸\n", nb, w, p);
	printf("-----\n");
	ret_1 = printf(".1 {%d}  .2 {%-d}  .3 {%0d}\n", nb, nb, nb);
	ret_2 = ft_printf(".1 {%d}  .2 {%-d}  .3 {%0d}\n", nb, nb, nb);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);
	ret_1 = printf(".4 {%*d}  .5 {%-*d}  .6 {%0*d}\n", w, nb, w, nb, w, nb);
	ret_2 = ft_printf(".4 {%*d}  .5 {%-*d}  .6 {%0*d}\n", w, nb, w, nb, w, nb);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);
	ret_1 = printf(".7 {%.d}  8. {%*.d}  9. {%0*.d}  .10 {%-*.d}\n", nb, w, nb, w, nb, w, nb);
	ret_2 = ft_printf(".7 {%.d}  8. {%*.d}  9. {%0*.d}  .10 {%-*.d}\n", nb, w, nb, w, nb, w, nb);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);
	ret_1 = printf(".11 {%.*d}  .12 {%-.*d}  .13 {%0.*d}\n", p, nb, p, nb, p, nb);
	ret_2 = ft_printf(".11 {%.*d}  .12 {%-.*d}  .13 {%0.*d}\n", p, nb, p, nb, p, nb);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);
	ret_1 = printf(".14 {%*.*d}  .15 {%0*.*d}  .16 {%-*.*d}  .17 {%-0*.*d}\n", w, p, nb, w, p, nb, w, p, nb, w, p, nb);
	ret_2 = ft_printf(".14 {%*.*d}  .15 {%0*.*d}  .16 {%-*.*d}  .17 {%-0*.*d}\n", w, p, nb, w, p, nb, w, p, nb, w, p, nb);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);


	nb = 4568; w = -12; p = -9;
	printf("\n👀  TEST nb = %d | width = %d | precision = %d 👀\n", nb, w, p);
	printf("-----\n");
	ret_1 = printf(".1 {%d}  .2 {%-d}  .3 {%0d}\n", nb, nb, nb);
	ret_2 = ft_printf(".1 {%d}  .2 {%-d}  .3 {%0d}\n", nb, nb, nb);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);
	ret_1 = printf(".4 {%*d}  .5 {%-*d}  .6 {%0*d}\n", w, nb, w, nb, w, nb);
	ret_2 = ft_printf(".4 {%*d}  .5 {%-*d}  .6 {%0*d}\n", w, nb, w, nb, w, nb);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);
	ret_1 = printf(".7 {%.d}  8. {%*.d}  9. {%0*.d}  .10 {%-*.d}\n", nb, w, nb, w, nb, w, nb);
	ret_2 = ft_printf(".7 {%.d}  8. {%*.d}  9. {%0*.d}  .10 {%-*.d}\n", nb, w, nb, w, nb, w, nb);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);
	ret_1 = printf(".11 {%.*d}  .12 {%-.*d}  .13 {%0.*d}\n", p, nb, p, nb, p, nb);
	ret_2 = ft_printf(".11 {%.*d}  .12 {%-.*d}  .13 {%0.*d}\n", p, nb, p, nb, p, nb);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);
	ret_1 = printf(".14 {%*.*d}  .15 {%0*.*d}  .16 {%-*.*d}  .17 {%-0*.*d}\n", w, p, nb, w, p, nb, w, p, nb, w, p, nb);
	ret_2 = ft_printf(".14 {%*.*d}  .15 {%0*.*d}  .16 {%-*.*d}  .17 {%-0*.*d}\n", w, p, nb, w, p, nb, w, p, nb, w, p, nb);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);


	nb = -4568; w = -15; p = -10;
	printf("\n🐒  TEST nb = %d | width = %d | precision = %d 🐒\n", nb, w, p);
	printf("-----\n");
	ret_1 = printf(".1 {%d}  .2 {%-d}  .3 {%0d}\n", nb, nb, nb);
	ret_2 = ft_printf(".1 {%d}  .2 {%-d}  .3 {%0d}\n", nb, nb, nb);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);
	ret_1 = printf(".4 {%*d}  .5 {%-*d}  .6 {%0*d}\n", w, nb, w, nb, w, nb);
	ret_2 = ft_printf(".4 {%*d}  .5 {%-*d}  .6 {%0*d}\n", w, nb, w, nb, w, nb);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);
	ret_1 = printf(".7 {%.d}  8. {%*.d}  9. {%0*.d}  .10 {%-*.d}\n", nb, w, nb, w, nb, w, nb);
	ret_2 = ft_printf(".7 {%.d}  8. {%*.d}  9. {%0*.d}  .10 {%-*.d}\n", nb, w, nb, w, nb, w, nb);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);
	ret_1 = printf(".11 {%.*d}  .12 {%-.*d}  .13 {%0.*d}\n", p, nb, p, nb, p, nb);
	ret_2 = ft_printf(".11 {%.*d}  .12 {%-.*d}  .13 {%0.*d}\n", p, nb, p, nb, p, nb);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);
	ret_1 = printf(".14 {%*.*d}  .15 {%0*.*d}  .16 {%-*.*d}  .17 {%-0*.*d}\n", w, p, nb, w, p, nb, w, p, nb, w, p, nb);
	ret_2 = ft_printf(".14 {%*.*d}  .15 {%0*.*d}  .16 {%-*.*d}  .17 {%-0*.*d}\n", w, p, nb, w, p, nb, w, p, nb, w, p, nb);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);


	nb = 4568; w = 15; p = -7;
	printf("\n🦁  TEST nb = %d | width = %d | precision = %d 🦁\n", nb, w, p);
	printf("-----\n");
	ret_1 = printf(".1 {%d}  .2 {%-d}  .3 {%0d}\n", nb, nb, nb);
	ret_2 = ft_printf(".1 {%d}  .2 {%-d}  .3 {%0d}\n", nb, nb, nb);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);
	ret_1 = printf(".4 {%*d}  .5 {%-*d}  .6 {%0*d}\n", w, nb, w, nb, w, nb);
	ret_2 = ft_printf(".4 {%*d}  .5 {%-*d}  .6 {%0*d}\n", w, nb, w, nb, w, nb);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);
	ret_1 = printf(".7 {%.d}  8. {%*.d}  9. {%0*.d}  .10 {%-*.d}\n", nb, w, nb, w, nb, w, nb);
	ret_2 = ft_printf(".7 {%.d}  8. {%*.d}  9. {%0*.d}  .10 {%-*.d}\n", nb, w, nb, w, nb, w, nb);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);
	ret_1 = printf(".11 {%.*d}  .12 {%-.*d}  .13 {%0.*d}\n", p, nb, p, nb, p, nb);
	ret_2 = ft_printf(".11 {%.*d}  .12 {%-.*d}  .13 {%0.*d}\n", p, nb, p, nb, p, nb);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);
	ret_1 = printf(".14 {%*.*d}  .15 {%0*.*d}  .16 {%-*.*d}  .17 {%-0*.*d}\n", w, p, nb, w, p, nb, w, p, nb, w, p, nb);
	ret_2 = ft_printf(".14 {%*.*d}  .15 {%0*.*d}  .16 {%-*.*d}  .17 {%-0*.*d}\n", w, p, nb, w, p, nb, w, p, nb, w, p, nb);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);


	nb = -4568; w = 20; p = 1;
	printf("\n😉  TEST nb = %d | width = %d | precision = %d 😉\n", nb, w, p);
	printf("-----\n");
	ret_1 = printf(".1 {%d}  .2 {%-d}  .3 {%0d}\n", nb, nb, nb);
	ret_2 = ft_printf(".1 {%d}  .2 {%-d}  .3 {%0d}\n", nb, nb, nb);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);
	ret_1 = printf(".4 {%*d}  .5 {%-*d}  .6 {%0*d}\n", w, nb, w, nb, w, nb);
	ret_2 = ft_printf(".4 {%*d}  .5 {%-*d}  .6 {%0*d}\n", w, nb, w, nb, w, nb);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);
	ret_1 = printf(".7 {%.d}  8. {%*.d}  9. {%0*.d}  .10 {%-*.d}\n", nb, w, nb, w, nb, w, nb);
	ret_2 = ft_printf(".7 {%.d}  8. {%*.d}  9. {%0*.d}  .10 {%-*.d}\n", nb, w, nb, w, nb, w, nb);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);
	ret_1 = printf(".11 {%.*d}  .12 {%-.*d}  .13 {%0.*d}\n", p, nb, p, nb, p, nb);
	ret_2 = ft_printf(".11 {%.*d}  .12 {%-.*d}  .13 {%0.*d}\n", p, nb, p, nb, p, nb);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);
	ret_1 = printf(".14 {%*.*d}  .15 {%0*.*d}  .16 {%-*.*d}  .17 {%-0*.*d}\n", w, p, nb, w, p, nb, w, p, nb, w, p, nb);
	ret_2 = ft_printf(".14 {%*.*d}  .15 {%0*.*d}  .16 {%-*.*d}  .17 {%-0*.*d}\n", w, p, nb, w, p, nb, w, p, nb, w, p, nb);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);


	nb = -42; w = 0; p = 0;
	printf("\n🏓  TEST nb = %d | width = %d | precision = %d 🏓\n", nb, w, p);
	printf("-----\n");
	ret_1 = printf(".1 {%d}  .2 {%-d}  .3 {%0d}\n", nb, nb, nb);
	ret_2 = ft_printf(".1 {%d}  .2 {%-d}  .3 {%0d}\n", nb, nb, nb);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);
	ret_1 = printf(".4 {%*d}  .5 {%-*d}  .6 {%0*d}\n", w, nb, w, nb, w, nb);
	ret_2 = ft_printf(".4 {%*d}  .5 {%-*d}  .6 {%0*d}\n", w, nb, w, nb, w, nb);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);
	ret_1 = printf(".7 {%.d}  8. {%*.d}  9. {%0*.d}  .10 {%-*.d}\n", nb, w, nb, w, nb, w, nb);
	ret_2 = ft_printf(".7 {%.d}  8. {%*.d}  9. {%0*.d}  .10 {%-*.d}\n", nb, w, nb, w, nb, w, nb);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);
	ret_1 = printf(".11 {%.*d}  .12 {%-.*d}  .13 {%0.*d}\n", p, nb, p, nb, p, nb);
	ret_2 = ft_printf(".11 {%.*d}  .12 {%-.*d}  .13 {%0.*d}\n", p, nb, p, nb, p, nb);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);
	ret_1 = printf(".14 {%*.*d}  .15 {%0*.*d}  .16 {%-*.*d}  .17 {%-0*.*d}\n", w, p, nb, w, p, nb, w, p, nb, w, p, nb);
	ret_2 = ft_printf(".14 {%*.*d}  .15 {%0*.*d}  .16 {%-*.*d}  .17 {%-0*.*d}\n", w, p, nb, w, p, nb, w, p, nb, w, p, nb);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);


	nb = -42; w = 16; p = 5;
	printf("\n🍣  TEST nb = %d | width = %d | precision = %d 🍣\n", nb, w, p);
	printf("-----\n");
	ret_1 = printf(".1 {%d}  .2 {%-d}  .3 {%0d}\n", nb, nb, nb);
	ret_2 = ft_printf(".1 {%d}  .2 {%-d}  .3 {%0d}\n", nb, nb, nb);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);
	ret_1 = printf(".4 {%*d}  .5 {%-*d}  .6 {%0*d}\n", w, nb, w, nb, w, nb);
	ret_2 = ft_printf(".4 {%*d}  .5 {%-*d}  .6 {%0*d}\n", w, nb, w, nb, w, nb);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);
	ret_1 = printf(".7 {%.d}  8. {%*.d}  9. {%0*.d}  .10 {%-*.d}\n", nb, w, nb, w, nb, w, nb);
	ret_2 = ft_printf(".7 {%.d}  8. {%*.d}  9. {%0*.d}  .10 {%-*.d}\n", nb, w, nb, w, nb, w, nb);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);
	ret_1 = printf(".11 {%.*d}  .12 {%-.*d}  .13 {%0.*d}\n", p, nb, p, nb, p, nb);
	ret_2 = ft_printf(".11 {%.*d}  .12 {%-.*d}  .13 {%0.*d}\n", p, nb, p, nb, p, nb);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);
	ret_1 = printf(".14 {%*.*d}  .15 {%0*.*d}  .16 {%-*.*d}  .17 {%-0*.*d}\n", w, p, nb, w, p, nb, w, p, nb, w, p, nb);
	ret_2 = ft_printf(".14 {%*.*d}  .15 {%0*.*d}  .16 {%-*.*d}  .17 {%-0*.*d}\n", w, p, nb, w, p, nb, w, p, nb, w, p, nb);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);


	nb = -189; w = 8; p = 0;
	printf("\n🍑  TEST nb = %d | width = %d | precision = %d 🍑\n", nb, w, p);
	printf("-----\n");
	ret_1 = printf(".1 {%d}  .2 {%-d}  .3 {%0d}\n", nb, nb, nb);
	ret_2 = ft_printf(".1 {%d}  .2 {%-d}  .3 {%0d}\n", nb, nb, nb);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);
	ret_1 = printf(".4 {%*d}  .5 {%-*d}  .6 {%0*d}\n", w, nb, w, nb, w, nb);
	ret_2 = ft_printf(".4 {%*d}  .5 {%-*d}  .6 {%0*d}\n", w, nb, w, nb, w, nb);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);
	ret_1 = printf(".7 {%.d}  8. {%*.d}  9. {%0*.d}  .10 {%-*.d}\n", nb, w, nb, w, nb, w, nb);
	ret_2 = ft_printf(".7 {%.d}  8. {%*.d}  9. {%0*.d}  .10 {%-*.d}\n", nb, w, nb, w, nb, w, nb);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);
	ret_1 = printf(".11 {%.*d}  .12 {%-.*d}  .13 {%0.*d}\n", p, nb, p, nb, p, nb);
	ret_2 = ft_printf(".11 {%.*d}  .12 {%-.*d}  .13 {%0.*d}\n", p, nb, p, nb, p, nb);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);
	ret_1 = printf(".14 {%*.*d}  .15 {%0*.*d}  .16 {%-*.*d}  .17 {%-0*.*d}\n", w, p, nb, w, p, nb, w, p, nb, w, p, nb);
	ret_2 = ft_printf(".14 {%*.*d}  .15 {%0*.*d}  .16 {%-*.*d}  .17 {%-0*.*d}\n", w, p, nb, w, p, nb, w, p, nb, w, p, nb);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);


	nb = -256; w = 0; p = 8;
	printf("\n🌵  TEST nb = %d | width = %d | precision = %d 🌵\n", nb, w, p);
	printf("-----\n");
	ret_1 = printf(".1 {%d}  .2 {%-d}  .3 {%0d}\n", nb, nb, nb);
	ret_2 = ft_printf(".1 {%d}  .2 {%-d}  .3 {%0d}\n", nb, nb, nb);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);
	ret_1 = printf(".4 {%*d}  .5 {%-*d}  .6 {%0*d}\n", w, nb, w, nb, w, nb);
	ret_2 = ft_printf(".4 {%*d}  .5 {%-*d}  .6 {%0*d}\n", w, nb, w, nb, w, nb);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);
	ret_1 = printf(".7 {%.d}  8. {%*.d}  9. {%0*.d}  .10 {%-*.d}\n", nb, w, nb, w, nb, w, nb);
	ret_2 = ft_printf(".7 {%.d}  8. {%*.d}  9. {%0*.d}  .10 {%-*.d}\n", nb, w, nb, w, nb, w, nb);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);
	ret_1 = printf(".11 {%.*d}  .12 {%-.*d}  .13 {%0.*d}\n", p, nb, p, nb, p, nb);
	ret_2 = ft_printf(".11 {%.*d}  .12 {%-.*d}  .13 {%0.*d}\n", p, nb, p, nb, p, nb);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);
	ret_1 = printf(".14 {%*.*d}  .15 {%0*.*d}  .16 {%-*.*d}  .17 {%-0*.*d}\n", w, p, nb, w, p, nb, w, p, nb, w, p, nb);
	ret_2 = ft_printf(".14 {%*.*d}  .15 {%0*.*d}  .16 {%-*.*d}  .17 {%-0*.*d}\n", w, p, nb, w, p, nb, w, p, nb, w, p, nb);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);


	nb = -256; w = 0; p = 8;
	printf("\n🍌  TEST nb = %d | width = %d | precision = %d 🍌\n", nb, w, p);
	printf("-----\n");
	ret_1 = printf(".1 {%d}  .2 {%-d}  .3 {%0d}\n", nb, nb, nb);
	ret_2 = ft_printf(".1 {%d}  .2 {%-d}  .3 {%0d}\n", nb, nb, nb);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);
	ret_1 = printf(".4 {%*d}  .5 {%-*d}  .6 {%0*d}\n", w, nb, w, nb, w, nb);
	ret_2 = ft_printf(".4 {%*d}  .5 {%-*d}  .6 {%0*d}\n", w, nb, w, nb, w, nb);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);
	ret_1 = printf(".7 {%.d}  8. {%*.d}  9. {%0*.d}  .10 {%-*.d}\n", nb, w, nb, w, nb, w, nb);
	ret_2 = ft_printf(".7 {%.d}  8. {%*.d}  9. {%0*.d}  .10 {%-*.d}\n", nb, w, nb, w, nb, w, nb);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);
	ret_1 = printf(".11 {%.*d}  .12 {%-.*d}  .13 {%0.*d}\n", p, nb, p, nb, p, nb);
	ret_2 = ft_printf(".11 {%.*d}  .12 {%-.*d}  .13 {%0.*d}\n", p, nb, p, nb, p, nb);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);
	ret_1 = printf(".14 {%*.*d}  .15 {%0*.*d}  .16 {%-*.*d}  .17 {%-0*.*d}\n", w, p, nb, w, p, nb, w, p, nb, w, p, nb);
	ret_2 = ft_printf(".14 {%*.*d}  .15 {%0*.*d}  .16 {%-*.*d}  .17 {%-0*.*d}\n", w, p, nb, w, p, nb, w, p, nb, w, p, nb);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);

	nb = -666; w = 6; p = 6;
	printf("\n☠️  TEST nb = %d | width = %d | precision = %d ☠️\n", nb, w, p);
	printf("-----\n");
	ret_1 = printf(".1 {%d}  .2 {%-d}  .3 {%0d}\n", nb, nb, nb);
	ret_2 = ft_printf(".1 {%d}  .2 {%-d}  .3 {%0d}\n", nb, nb, nb);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);
	ret_1 = printf(".4 {%*d}  .5 {%-*d}  .6 {%0*d}\n", w, nb, w, nb, w, nb);
	ret_2 = ft_printf(".4 {%*d}  .5 {%-*d}  .6 {%0*d}\n", w, nb, w, nb, w, nb);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);
	ret_1 = printf(".7 {%.d}  8. {%*.d}  9. {%0*.d}  .10 {%-*.d}\n", nb, w, nb, w, nb, w, nb);
	ret_2 = ft_printf(".7 {%.d}  8. {%*.d}  9. {%0*.d}  .10 {%-*.d}\n", nb, w, nb, w, nb, w, nb);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);
	ret_1 = printf(".11 {%.*d}  .12 {%-.*d}  .13 {%0.*d}\n", p, nb, p, nb, p, nb);
	ret_2 = ft_printf(".11 {%.*d}  .12 {%-.*d}  .13 {%0.*d}\n", p, nb, p, nb, p, nb);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);
	ret_1 = printf(".14 {%*.*d}  .15 {%0*.*d}  .16 {%-*.*d}  .17 {%-0*.*d}\n", w, p, nb, w, p, nb, w, p, nb, w, p, nb);
	ret_2 = ft_printf(".14 {%*.*d}  .15 {%0*.*d}  .16 {%-*.*d}  .17 {%-0*.*d}\n", w, p, nb, w, p, nb, w, p, nb, w, p, nb);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);


	nb = INT_MAX; w = 13; p = 15;
	printf("\n🌲  TEST nb = %d | width = %d | precision = %d 🌲\n", nb, w, p);
	printf("-----\n");
	ret_1 = printf(".1 {%d}  .2 {%-d}  .3 {%0d}\n", nb, nb, nb);
	ret_2 = ft_printf(".1 {%d}  .2 {%-d}  .3 {%0d}\n", nb, nb, nb);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);
	ret_1 = printf(".4 {%*d}  .5 {%-*d}  .6 {%0*d}\n", w, nb, w, nb, w, nb);
	ret_2 = ft_printf(".4 {%*d}  .5 {%-*d}  .6 {%0*d}\n", w, nb, w, nb, w, nb);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);
	ret_1 = printf(".7 {%.d}  8. {%*.d}  9. {%0*.d}  .10 {%-*.d}\n", nb, w, nb, w, nb, w, nb);
	ret_2 = ft_printf(".7 {%.d}  8. {%*.d}  9. {%0*.d}  .10 {%-*.d}\n", nb, w, nb, w, nb, w, nb);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);
	ret_1 = printf(".11 {%.*d}  .12 {%-.*d}  .13 {%0.*d}\n", p, nb, p, nb, p, nb);
	ret_2 = ft_printf(".11 {%.*d}  .12 {%-.*d}  .13 {%0.*d}\n", p, nb, p, nb, p, nb);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);
	ret_1 = printf(".14 {%*.*d}  .15 {%0*.*d}  .16 {%-*.*d}  .17 {%-0*.*d}\n", w, p, nb, w, p, nb, w, p, nb, w, p, nb);
	ret_2 = ft_printf(".14 {%*.*d}  .15 {%0*.*d}  .16 {%-*.*d}  .17 {%-0*.*d}\n", w, p, nb, w, p, nb, w, p, nb, w, p, nb);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);


	nb = INT_MAX; w = 22; p = 15;
	printf("\n🤡  TEST nb = %d | width = %d | precision = %d 🤡\n", nb, w, p);
	printf("-----\n");
	ret_1 = printf(".1 {%d}  .2 {%-d}  .3 {%0d}\n", nb, nb, nb);
	ret_2 = ft_printf(".1 {%d}  .2 {%-d}  .3 {%0d}\n", nb, nb, nb);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);
	ret_1 = printf(".4 {%*d}  .5 {%-*d}  .6 {%0*d}\n", w, nb, w, nb, w, nb);
	ret_2 = ft_printf(".4 {%*d}  .5 {%-*d}  .6 {%0*d}\n", w, nb, w, nb, w, nb);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);
	ret_1 = printf(".7 {%.d}  8. {%*.d}  9. {%0*.d}  .10 {%-*.d}\n", nb, w, nb, w, nb, w, nb);
	ret_2 = ft_printf(".7 {%.d}  8. {%*.d}  9. {%0*.d}  .10 {%-*.d}\n", nb, w, nb, w, nb, w, nb);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);
	ret_1 = printf(".11 {%.*d}  .12 {%-.*d}  .13 {%0.*d}\n", p, nb, p, nb, p, nb);
	ret_2 = ft_printf(".11 {%.*d}  .12 {%-.*d}  .13 {%0.*d}\n", p, nb, p, nb, p, nb);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);
	ret_1 = printf(".14 {%*.*d}  .15 {%0*.*d}  .16 {%-*.*d}  .17 {%-0*.*d}\n", w, p, nb, w, p, nb, w, p, nb, w, p, nb);
	ret_2 = ft_printf(".14 {%*.*d}  .15 {%0*.*d}  .16 {%-*.*d}  .17 {%-0*.*d}\n", w, p, nb, w, p, nb, w, p, nb, w, p, nb);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);


	nb = INT_MAX; w = 22; p = -15;
	printf("\n🤙  TEST nb = %d | width = %d | precision = %d 🤙\n", nb, w, p);
	printf("-----\n");
	ret_1 = printf(".1 {%d}  .2 {%-d}  .3 {%0d}\n", nb, nb, nb);
	ret_2 = ft_printf(".1 {%d}  .2 {%-d}  .3 {%0d}\n", nb, nb, nb);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);
	ret_1 = printf(".4 {%*d}  .5 {%-*d}  .6 {%0*d}\n", w, nb, w, nb, w, nb);
	ret_2 = ft_printf(".4 {%*d}  .5 {%-*d}  .6 {%0*d}\n", w, nb, w, nb, w, nb);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);
	ret_1 = printf(".7 {%.d}  8. {%*.d}  9. {%0*.d}  .10 {%-*.d}\n", nb, w, nb, w, nb, w, nb);
	ret_2 = ft_printf(".7 {%.d}  8. {%*.d}  9. {%0*.d}  .10 {%-*.d}\n", nb, w, nb, w, nb, w, nb);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);
	ret_1 = printf(".11 {%.*d}  .12 {%-.*d}  .13 {%0.*d}\n", p, nb, p, nb, p, nb);
	ret_2 = ft_printf(".11 {%.*d}  .12 {%-.*d}  .13 {%0.*d}\n", p, nb, p, nb, p, nb);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);
	ret_1 = printf(".14 {%*.*d}  .15 {%0*.*d}  .16 {%-*.*d}  .17 {%-0*.*d}\n", w, p, nb, w, p, nb, w, p, nb, w, p, nb);
	ret_2 = ft_printf(".14 {%*.*d}  .15 {%0*.*d}  .16 {%-*.*d}  .17 {%-0*.*d}\n", w, p, nb, w, p, nb, w, p, nb, w, p, nb);
	if (ret_1 == ret_2)
		printf("Good !!! %d | %d\n\n", ret_1, ret_2);
	else
		printf("🖕 FUCK YOU BITCH 🖕\n %d | %d\n\n", ret_1, ret_2);

	return 0;
}

// INT_MAX 2147483647
// UINT_MAX 4294967295