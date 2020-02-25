#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include "ft_printf.h"

int main()
{
	int nb = INT_MIN;
	// int ret;



	// ret = ft_printf("\n123456789%c", 'A');

	// printf("\nprintf :	{%.d}\n", nb);
	// ft_printf("ft_printf :	{%.d}\n", nb);
	// printf("\nprintf :	{%0*.*d}\n", -5, -5, 0);
	// ft_printf("ft_printf :	{%0*.*d}\n", -5, -5, 0);
	// printf("\nprintf :	{%-20.15d}\n", 2147483647);
	// ft_printf("ft_printf :	{%-20.15d}\n", 2147483647);

	// printf("\nprintf :	coucou {%*c} lala\n", 6, 'B');
	// ft_printf("ft_printf :	coucou {%*c} lala\n", 6, 'B');
	printf("\nprintf :	coucou {%*c} ... {%*c} lala\n", 9, 'A', -6, 'B');
	ft_printf("ft_printf :	coucou {%*c} ... {%*c} lala\n", 9, 'A', -6, 'B');
	// printf("\nreturn %d", ret);
	return 0;
}

// 2147483647