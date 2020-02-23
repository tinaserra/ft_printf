#include <stdio.h>
#include <unistd.h>
#include "ft_printf.h"

int main()
{
	ft_printf("\nft_printf :	coucou {%-25c} ... {%-20.15d}", 'B', 2147483647);
	printf("\nprintf :	coucou {%-25c} ... {%-20.15d}", 'B', 2147483647);
	// ft_printf("\nft_printf :	coucou {%*c} ... {%*c} lala", -9, 'A', 2147483647, 'B');
	// printf("\nprintf :	coucou {%*c} ... {%*c} lala", -9, 'A', 6, 'B');
	return 0;
}

// 2147483647