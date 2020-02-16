#include <stdio.h>
#include "ft_printf.h"

int main()
{
	ft_printf("coucou {%-015.5c}", 'B');
	// printf("printf :	coucou |%12c|\n", 'B');
	return 0;
}
