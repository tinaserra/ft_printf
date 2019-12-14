/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserra <vserra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 03:52:56 by vserra            #+#    #+#             */
/*   Updated: 2019/12/13 17:40:51 by vserra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>

int		main(int ac, char **av)
{
	char *nombre; //int
	char *width; //int
	char *precision; //int
	char *str; //char* string av[4]
	
	unsigned int unb;
	int nb;

	if (ac > 1)
	{
		printf("\n******************************************* int --> %% d *******************************************\n\n");
		printf("AUGUMENTS : av[1] -> int || av[2] -> width || av[3] -> precision\n");
		nombre = av[1];
		printf("\nTEST width = 4\n");
		printf("-----\n");
		printf("printf\n|%04d| |%-04d| |%0-4d| |%04.d| |%-04.d| |%0-4.d|\n", atoi(nombre), atoi(nombre), atoi(nombre), atoi(nombre), atoi(nombre), atoi(nombre));
		// fr_printf("ft_printf\n|%04d| |%-04d| |%0-4d| |%04.d| |%-04.d| |%0-4.d|\n", atoi(nombre), atoi(nombre), atoi(nombre), atoi(nombre), atoi(nombre), atoi(nombre));
		if (ac > 2)
		{
			width = av[2];
			printf("\nTEST width = * %s\n", av[2]);
			printf("-----\n");
			printf("printf\n|%0*d| |%-0*d| |%0-*d| |%0*.d| |%-0*.d| |%0-*.d|\n", atoi(width), atoi(nombre), atoi(width), atoi(nombre), atoi(width), atoi(nombre), atoi(width), atoi(nombre), atoi(width), atoi(nombre), atoi(width), atoi(nombre));
			// ft_printf("ft_printf\n|%0*d| |%-0*d| |%0-*d| |%0*.d| |%-0*.d| |%0-*.d|\n", atoi(width), atoi(nombre), atoi(width), atoi(nombre), atoi(width), atoi(nombre), atoi(width), atoi(nombre), atoi(width), atoi(nombre), atoi(width), atoi(nombre));

			printf("\nTEST precision = * %s\n", av[2]);
			printf("-----\n");
			printf("printf\n|%0.*d| |%-0.*d| |%0-.*d| |%.*d| |%-.*d|\n", atoi(width), atoi(nombre), atoi(width), atoi(nombre), atoi(width), atoi(nombre), atoi(width), atoi(nombre), atoi(width), atoi(nombre));
			// ft_printf("ft_printf\n|%0.*d| |%-0.*d| |%0-.*d| |%.*d| |%-.*d|\n", atoi(width), atoi(nombre), atoi(width), atoi(nombre), atoi(width), atoi(nombre), atoi(width), atoi(nombre), atoi(width), atoi(nombre));
		}
		if (ac > 3)
		{
			precision = av[3];
			printf("\nTEST width = * %s | precision = * %s\n", av[2], av[3]);
			printf("-----\n");
			printf("printf\n|%d| |%*.*d| |%0*.*d| |%-*.*d| |%-0*.*d|\n", atoi(nombre), atoi(width), atoi(precision), atoi(nombre), atoi(width), atoi(precision), atoi(nombre), atoi(width), atoi(precision), atoi(nombre), atoi(width), atoi(precision), atoi(nombre));
			// ft_printf("ft_printf\n|%d| |%*.*d| |%0*.*d| |%-*.*d|\n", atoi(nombre), atoi(width), atoi(precision), atoi(nombre), atoi(width), atoi(precision), atoi(nombre), atoi(width), atoi(precision), atoi(nombre));
		}

		if (ac > 4)
		{
			printf("\n\n******************************************* string --> %% s *******************************************\n\n");
			printf("AUGUMENTS : av[4] -> string\n");
			str = av[4];
			printf("\nTEST width = * %s | precision = * %s | str = * %s\n", av[2], av[3], av[4]);
			printf("-----\n");
			printf("printf\n|%s| |%*.*s| |%-*.*s| |%0*.*s| |%-0*.*s|\n", str, atoi(width), atoi(precision), str, atoi(width), atoi(precision), str, atoi(width), atoi(precision), str, atoi(width), atoi(precision), str);
			// ft_printf("ft_printf\n|%s| |%*.*s| |%-*.*s| |%0*.*s|\n", str, atoi(width), atoi(precision), str, atoi(width), atoi(precision), str, atoi(width), atoi(precision), str);
		}

	}
	else if (ac == 1)
	{
		printf("\n******************************************* int --> %% d *******************************************\n\n");
		// printf("\n  ////////////////////////////////////////\n // Met un int en 1er argument ta race //\n////////////////////////////////////////\n");
		nb = 12;
		printf("\nTEST nb = 12 | width = 4\n");
		printf("-----\n");
		printf("printf\n|%04d| |%-04d| |%0-4d| |%04.d| |%-04.d| |%0-4.d|\n", nb, nb, nb, nb, nb, nb);
		// ft_printf("ft_printf\n|%04d| |%-04d| |%0-4d| |%04.d| |%-04.d| |%0-4.d|\n", nb, nb, nb, nb, nb, nb);

		nb = 12345;
		printf("\nTEST nb = 12345 | width = 20 | precision = 9\n");
		printf("-----\n");
		printf("printf\n|%d| |%020d| |%-020d| |%0-20d| |%020.9d| |%-020.9d| |%0-20.9d|\n", nb, nb, nb, nb, nb, nb, nb);

		nb = 0;
		printf("\nTEST nb = 0 | width = 4\n");
		printf("-----\n");
		printf("printf\n|%04d| |%-04d| |%0-4d| |%04.d| |%-04.d| |%0-4.d|\n", nb, nb, nb, nb, nb, nb);
		// ft_printf("ft_printf\n|%04d| |%-04d| |%0-4d| |%04.d| |%-04.d| |%0-4.d|\n", nb, nb, nb, nb, nb, nb);

		nb = INT_MAX;
		printf("\nTEST nb = int max | width = 20\n");
		printf("-----\n");
		printf("printf\n|%020d| |%-020d| |%0-20d| |%020.d| |%-020.d| |%0-20.d|\n", nb, nb, nb, nb, nb, nb);
		// ft_printf("ft_printf\n|%020d| |%-020d| |%0-20d| |%020.d| |%-020.d| |%0-20.d|\n", nb, nb, nb, nb, nb, nb);

		nb = INT_MIN;
		printf("\nTEST nb = int min | width = 20\n");
		printf("------\n");
		printf("printf\n|%020d| |%-020d| |%0-20d| |%020.d| |%-020.d| |%0-20.d|\n", nb, nb, nb, nb, nb, nb);
		// ft_printf("ft_printf\n|%020d| |%-020d| |%0-20d| |%020.d| |%-020.d| |%0-20.d|\n", nb, nb, nb, nb, nb, nb);

		printf("\n\n\n******************************************* string --> %% s *******************************************\n\n");
		str = "Hello world";
		printf("\nTEST str = Hello word | width = 20 | precision = 5\n");
		printf("-----\n");
		printf("printf\n|%s| |%20.5s| |%-20.5s| |%020.5s|\n", str, str, str, str);
		// ft_printf("ft_printf\n|%s| |%20.5s| |%-20.5s| |%020.5s|\n", str, str, str, str);

		printf("\nTEST str = Hello word | width = 20 | precision = 0\n");
		printf("-----\n");
		printf("printf\n|%s| |%20.0s| |%-20.0s| |%020.0s|\n", str, str, str, str);
		// ft_printf("ft_printf\n|%s| |%20.0s| |%-20.0s| |%020.0s|\n", str, str, str, str);

		printf("\nTEST str = Hello word | width = 4 | precision = 0\n");
		printf("-----\n");
		printf("printf\n|%s| |%4.0s| |%-4.0s| |%04.0s|\n", str, str, str, str);
		// ft_printf("ft_printf\n|%s| |%4.0s| |%-4.0s| |%04.0s|\n", str, str, str, str);

		printf("\nTEST str = Hello word | width = 20 | precision = -12\n");
		printf("-----\n");
		printf("printf\n|%s| |%20.*s| |%-20.*s| |%020.*s|\n", str, -12, str, -12, str, -12, str);
		// ft_printf("ft_printf\n|%s| |%20.*s| |%-20.*s| |%020.*s|\n", str, -12, str, -12, str, -12, str);

		printf("\nTEST str = Hello word | width = 10 | precision = -12\n");
		printf("-----\n");
		printf("printf\n|%s| |%10.*s| |%-10.*s| |%010.*s|\n", str, -12, str, -12, str, -12, str);
		// ft_printf("ft_printf\n|%s| |%10.*s| |%-10.*s| |%010.*s|\n", str, -12, str, -12, str, -12, str);

		str = "";
		printf("\nTEST str = "" | width = 20 | precision = 5\n");
		printf("-----\n");
		printf("printf\n|%s| |%20.5s| |%-20.5s| |%020.5s|\n", str, str, str, str);
		// ft_printf("ft_printf\n|%s| |%20.5s| |%-20.5s| |%020.5s|\n", str, str, str, str);

		printf("\nTEST str = "" | width = 20 | precision = 0\n");
		printf("-----\n");
		printf("printf\n|%s| |%20.0s| |%-20.0s| |%020.0s|\n", str, str, str, str);
		// ft_printf("ft_printf\n|%s| |%20.0s| |%-20.0s| |%020.0s|\n", str, str, str, str);

		printf("\nTEST str = "" | width = 20 | precision = -12\n");
		printf("-----\n");
		printf("printf\n|%s| |%20.*s| |%-20.*s| |%020.*s|\n", str, -12, str, -12, str, -12, str);
		// ft_printf("ft_printf\n|%s| |%20.*s| |%-20.*s| |%020.*s|\n", str, -12, str, -12, str, -12, str);

		str = NULL;
		printf("\nTEST str = "" | width = 20 | precision = 3\n");
		printf("-----\n");
		printf("printf\n|%s| |%20.3s| |%-20.3s| |%020.3s|\n", str, str, str, str);
		// ft_printf("ft_printf\n|%s| |%20.3s| |%-20.3s| |%020.3s|\n", str, str, str, str);

		printf("\nTEST str = "" | width = 20 | precision = 0\n");
		printf("-----\n");
		printf("printf\n|%s| |%20.0s| |%-20.0s| |%020.0s|\n", str, str, str, str);
		// ft_printf("ft_printf\n|%s| |%20.0s| |%-20.0s| |%020.0s|\n", str, str, str, str);

		printf("\nTEST str = "" | width = 20 | precision = -12\n");
		printf("-----\n");
		printf("printf\n|%s| |%20.*s| |%-20.*s| |%020.*s|\n", str, -12, str, -12, str, -12, str);
		// ft_printf("ft_printf\n|%s| |%20.*s| |%-20.*s| |%020.*s|\n", str, -12, str, -12, str, -12, str);
		
	}
	printf("\n😎\n");
	return (0);
}
