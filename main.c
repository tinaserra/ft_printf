#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include "ft_printf.h"

int main()
{
	int nb;
	unsigned int unb;
	char *str;
	int w;
	int p;

	nb = 0;
	unb = 0;
	str = "hola que tal";
	w = -0;
	p = 0;

	/* TYPE S --------------------------------- */

	// printf("\nprintf :	{%.s} {%-.s} {%07.5s} {%-7.5s} {%07.s} {%-7.1s} {%07.1s} {%07.s}\n", str, str, str, str, str, str, str, NULL);

	/* TYPE D & U ----------------------------- */
	
	printf("\nprintf :	{%d} {%*d} {%-*d} {%0*d} {%0*.d} {%-*.d} {%.*d} {%-.*d} {%0.*d} {%0*.*d} {%-*.*d}\n", nb, w, nb, w, nb, w, nb, w, nb, w, nb, p, nb, p, nb, p, nb, w, p, nb, w, p, nb);
	ft_printf("ft_printf :	{%d} {%*d} {%-*d} {%0*d} {%0*.d} {%-*.d} {%.*d} {%-.*d} {%0.*d} {%0*.*d} {%-*.*d}\n", nb, w, nb, w, nb, w, nb, w, nb, w, nb, p, nb, p, nb, p, nb, w, p, nb, w, p, nb);

	printf("\nprintf :	1 {%d} 2 {%7d} 3 {%1d} 4 {%-7d} 5 {%07d} 6 {%.d} 7 {%-.d} 8 {%07.5d} 9 {%-7.5d} 10 {%07.d} 11 {%-7.1d} 12 {%07.1d} 13 {%07.d}\n", nb, nb, nb, nb, nb, nb, nb, nb, nb, nb, nb, nb, 0);
	ft_printf("ft_printf :	1 {%d} 2 {%7d} 3 {%1d} 4 {%-7d} 5 {%07d} 6 {%.d} 7 {%-.d} 8 {%07.5d} 9 {%-7.5d} 10 {%07.d} 11 {%-7.1d} 12 {%07.1d} 13 {%07.d}\n", nb, nb, nb, nb, nb, nb, nb, nb, nb, nb, nb, nb, 0);
	printf("\nprintf :	1 {%u} 2 {%7u} 3 {%1u} 4 {%-7u} 5 {%07u} 6 {%.u} 7 {%-.u} 8 {%07.5u} 9 {%-7.5u} 10 {%07.u} 11 {%-7.1u} 12 {%07.1u} 13 {%07.u}\n", unb, unb, unb, unb, unb, unb, unb, unb, unb, unb, unb, unb, 0);
	ft_printf("ft_printf :	1 {%u} 2 {%7u} 3 {%1u} 4 {%-7u} 5 {%07u} 6 {%.u} 7 {%-.u} 8 {%07.5u} 9 {%-7.5u} 10 {%07.u} 11 {%-7.1u} 12 {%07.1u} 13 {%07.u}\n", unb, unb, unb, unb, unb, unb, unb, unb, unb, unb, unb, unb, 0);

	// printf("\nprintf :	coucou {%*c} lala\n", 6, 'B');
	// ft_printf("ft_printf :	coucou {%*c} lala\n", 6, 'B');
	// printf("\nprintf :	coucou {%*c} ... {%*c} lala\n", 9, 'A', -6, 'B');
	// ft_printf("ft_printf :	coucou {%*c} ... {%*c} lala\n", 9, 'A', -6, 'B');
	// printf("\nreturn %d", ret);
	return 0;
}

// INT_MAX 2147483647
// UINT_MAX 4294967295