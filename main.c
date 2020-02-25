#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include "ft_printf.h"

int main()
{
	int nb = -15;

	ft_printf("\nft_printf :	{%0.*d}", -7, nb);
	printf("\nprintf :	{%0.*d}", -7, nb);
	// ft_printf("\nft_printf :	{%0*.*d}", -5, -5, 0);
	// printf("\nprintf :	{%0*.*d}", -5, -5, 0);
	// ft_printf("\nft_printf :	{%-20.15d}", 2147483647);
	// printf("\nprintf :	{%-20.15d}", 2147483647);
	// ft_printf("\nft_printf :	coucou {%*c} ... {%*c} lala", -9, 'A', 2147483647, 'B');
	// printf("\nprintf :	coucou {%*c} ... {%*c} lala", -9, 'A', 6, 'B');
	return 0;
}

// 2147483647