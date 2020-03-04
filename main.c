#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include "ft_printf.h"

int main()
{
	int w = 18;
	int p = 12;
	char *str = "Hola que tal";
	char c = 'Q';
	int nb = -42;
	unsigned int unb = 1111;
	unsigned int hexa = UINT_MAX;
	void *ptr;

	ptr = -462354;
	// str = NULL;

/* SIMPLE TESTS --------------------------------- */

	// printf("\nprintf :	coucou {%*c} lala\n", 6, 'B');
	// ft_printf("ft_printf :	coucou {%*c} lala\n", 6, 'B');
	// printf("\nprintf :	coucou {%*c} ... {%*c} lala\n", 9, 'A', -6, 'B');
	// ft_printf("ft_printf :	coucou {%*c} ... {%*c} lala\n", 9, 'A', -6, 'B');
	// printf("\nreturn %d", ret);

	// printf("\nprintf :	{%07.1d}\n", nb);
	// ft_printf("ft_printf :	{%07.1d}\n", nb);
	// printf("\nprintf :	{%-7.1d}\n", nb);
	// ft_printf("ft_printf :	{%-7.1d}\n", nb);

/* TYPE S --------------------------------- */

	// printf("\nprintf :	{%.s} {%-.s} {%07.5s} {%-7.5s} {%07.s} {%-7.1s} {%07.1s} {%07.s}\n", str, str, str, str, str, str, str, NULL);

/* TYPE P --------------------------------- */

	printf("\n\n* TYPE P ------------------------- *\n");

	w = 16; p = 11; // str = "Salut !";
	printf("\nprintf :	.1 {%p}  .2 {%*p}  .3 {%-*p}  .4 {%0*p}  .5 {%0*.p}  .6 {%-*.p}  .7 {%*.p}  .8 {%.*p}  .9 {%-.*p}  .10 {%0.*p}  .11 {%*.*p}  .12 {%0*.*p}  .13 {%-*.*p}\n", str, w, str, w, str, w, str, w, str, w, str, w, str, p, str, p, str, p, str, w, p, str, w, p, str, w, p, str);
	ft_printf("ft_printf :	.1 {%p}  .2 {%*p}  .3 {%-*p}  .4 {%0*p}  .5 {%0*.p}  .6 {%-*.p}  .7 {%*.p}  .8 {%.*p}  .9 {%-.*p}  .10 {%0.*p}  .11 {%*.*p}  .12 {%0*.*p}  .13 {%-*.*p}\n", str, w, str, w, str, w, str, w, str, w, str, w, str, p, str, p, str, p, str, w, p, str, w, p, str, w, p, str);

	w = 16; p = 11; str = NULL;
	printf("\nprintf :	.1 {%p}  .2 {%*p}  .3 {%-*p}  .4 {%0*p}  .5 {%0*.p}  .6 {%-*.p}  .7 {%*.p}  .8 {%.*p}  .9 {%-.*p}  .10 {%0.*p}  .11 {%*.*p}  .12 {%0*.*p}  .13 {%-*.*p}\n", str, w, str, w, str, w, str, w, str, w, str, w, str, p, str, p, str, p, str, w, p, str, w, p, str, w, p, str);
	ft_printf("ft_printf :	.1 {%p}  .2 {%*p}  .3 {%-*p}  .4 {%0*p}  .5 {%0*.p}  .6 {%-*.p}  .7 {%*.p}  .8 {%.*p}  .9 {%-.*p}  .10 {%0.*p}  .11 {%*.*p}  .12 {%0*.*p}  .13 {%-*.*p}\n", str, w, str, w, str, w, str, w, str, w, str, w, str, p, str, p, str, p, str, w, p, str, w, p, str, w, p, str);

	ptr = -42; w = 15; p = 12; //ptr = 4294967295;
	printf("\nprintf :	.1 {%p}  .2 {%*p}  .3 {%-*p}  .4 {%0*p}  .5 {%0*.p}  .6 {%-*.p}  .7 {%*.p}  .8 {%.*p}  .9 {%-.*p}  .10 {%0.*p}  .11 {%*.*p}  .12 {%0*.*p}  .13 {%-*.*p}\n", ptr, w, ptr, w, ptr, w, ptr, w, ptr, w, ptr, w, ptr, p, ptr, p, ptr, p, ptr, w, p, ptr, w, p, ptr, w, p, ptr);
	ft_printf("ft_printf :	.1 {%p}  .2 {%*p}  .3 {%-*p}  .4 {%0*p}  .5 {%0*.p}  .6 {%-*.p}  .7 {%*.p}  .8 {%.*p}  .9 {%-.*p}  .10 {%0.*p}  .11 {%*.*p}  .12 {%0*.*p}  .13 {%-*.*p}\n", ptr, w, ptr, w, ptr, w, ptr, w, ptr, w, ptr, w, ptr, p, ptr, p, ptr, p, ptr, w, p, ptr, w, p, ptr, w, p, ptr);

/* TYPE D & U ----------------------------- */

	printf("\n\n* TYPE D ------------------------- *\n");

	nb = -56; w = 15; p = 10;
	printf("\nprintf :	.1 {%d}  .2 {%*d}  .3 {%-*d}  .4 {%0*d}  .5 {%0*.d}  .6 {%-*.d}  .7 {%*.d}  .8 {%.*d}  .9 {%-.*d}  .10 {%0.*d}  .11 {%*.*d}  .12 {%0*.*d}  .13 {%-*.*d}\n", nb, w, nb, w, nb, w, nb, w, nb, w, nb, w, nb, p, nb, p, nb, p, nb, w, p, nb, w, p, nb, w, p, nb);
	ft_printf("ft_printf :	.1 {%d}  .2 {%*d}  .3 {%-*d}  .4 {%0*d}  .5 {%0*.d}  .6 {%-*.d}  .7 {%*.d}  .8 {%.*d}  .9 {%-.*d}  .10 {%0.*d}  .11 {%*.*d}  .12 {%0*.*d}  .13 {%-*.*d}\n", nb, w, nb, w, nb, w, nb, w, nb, w, nb, w, nb, p, nb, p, nb, p, nb, w, p, nb, w, p, nb, w, p, nb);

	nb = 0; w = 0; p = 0;
	printf("\nprintf :	.1 {%d}  .2 {%*d}  .3 {%-*d}  .4 {%0*d}  .5 {%0*.d}  .6 {%-*.d}  .7 {%*.d}  .8 {%.*d}  .9 {%-.*d}  .10 {%0.*d}  .11 {%*.*d}  .12 {%0*.*d}  .13 {%-*.*d}\n", nb, w, nb, w, nb, w, nb, w, nb, w, nb, w, nb, p, nb, p, nb, p, nb, w, p, nb, w, p, nb, w, p, nb);
	ft_printf("ft_printf :	.1 {%d}  .2 {%*d}  .3 {%-*d}  .4 {%0*d}  .5 {%0*.d}  .6 {%-*.d}  .7 {%*.d}  .8 {%.*d}  .9 {%-.*d}  .10 {%0.*d}  .11 {%*.*d}  .12 {%0*.*d}  .13 {%-*.*d}\n", nb, w, nb, w, nb, w, nb, w, nb, w, nb, w, nb, p, nb, p, nb, p, nb, w, p, nb, w, p, nb, w, p, nb);

	printf("\nprintf :	1 {%d} 2 {%7d} 3 {%1d} 4 {%-7d} 5 {%07d} 6 {%.d} 7 {%-.d} 8 {%07.5d} 9 {%-7.5d} 10 {%07.d} 11 {%-7.1d} 12 {%07.1d} 13 {%07.d}\n", nb, nb, nb, nb, nb, nb, nb, nb, nb, nb, nb, nb, 0);
	ft_printf("ft_printf :	1 {%d} 2 {%7d} 3 {%1d} 4 {%-7d} 5 {%07d} 6 {%.d} 7 {%-.d} 8 {%07.5d} 9 {%-7.5d} 10 {%07.d} 11 {%-7.1d} 12 {%07.1d} 13 {%07.d}\n", nb, nb, nb, nb, nb, nb, nb, nb, nb, nb, nb, nb, 0);
	printf("\n😎\n"); 

	// printf("\n\n* TYPE U ------------------------- *\n");

	printf("\n\n* TYPE U ------------------------- *\n");

	unb = 1111; w = 15; p = 10;
	printf("\nprintf :	.1 {%u}  .2 {%*u}  .3 {%-*u}  .4 {%0*u}  .5 {%0*.u}  .6 {%-*.u}  .7 {%*.u}  .8 {%.*u}  .9 {%-.*u}  .10 {%0.*u}  .11 {%*.*u}  .12 {%0*.*u}  .13 {%-*.*u}\n", unb, w, unb, w, unb, w, unb, w, unb, w, unb, w, unb, p, unb, p, unb, p, unb, w, p, unb, w, p, unb, w, p, unb);
	ft_printf("ft_printf :	.1 {%u}  .2 {%*u}  .3 {%-*u}  .4 {%0*u}  .5 {%0*.u}  .6 {%-*.u}  .7 {%*.u}  .8 {%.*u}  .9 {%-.*u}  .10 {%0.*u}  .11 {%*.*u}  .12 {%0*.*u}  .13 {%-*.*u}\n", unb, w, unb, w, unb, w, unb, w, unb, w, unb, w, unb, p, unb, p, unb, p, unb, w, p, unb, w, p, unb, w, p, unb);

	unb = 0; w = 0; p = 10;
	printf("\nprintf :	.1 {%u}  .2 {%*u}  .3 {%-*u}  .4 {%0*u}  .5 {%0*.u}  .6 {%-*.u}  .7 {%*.u}  .8 {%.*u}  .9 {%-.*u}  .10 {%0.*u}  .11 {%*.*u}  .12 {%0*.*u}  .13 {%-*.*u}\n", unb, w, unb, w, unb, w, unb, w, unb, w, unb, w, unb, p, unb, p, unb, p, unb, w, p, unb, w, p, unb, w, p, unb);
	ft_printf("ft_printf :	.1 {%u}  .2 {%*u}  .3 {%-*u}  .4 {%0*u}  .5 {%0*.u}  .6 {%-*.u}  .7 {%*.u}  .8 {%.*u}  .9 {%-.*u}  .10 {%0.*u}  .11 {%*.*u}  .12 {%0*.*u}  .13 {%-*.*u}\n", unb, w, unb, w, unb, w, unb, w, unb, w, unb, w, unb, p, unb, p, unb, p, unb, w, p, unb, w, p, unb, w, p, unb);

	printf("\nprintf :	1 {%u} 2 {%7u} 3 {%1u} 4 {%-7u} 5 {%07u} 6 {%.u} 7 {%-.u} 8 {%07.5u} 9 {%-7.5u} 10 {%07.u} 11 {%-7.1u} 12 {%07.1u} 13 {%07.u}\n", unb, unb, unb, unb, unb, unb, unb, unb, unb, unb, unb, unb, 0);
	ft_printf("ft_printf :	1 {%u} 2 {%7u} 3 {%1u} 4 {%-7u} 5 {%07u} 6 {%.u} 7 {%-.u} 8 {%07.5u} 9 {%-7.5u} 10 {%07.u} 11 {%-7.1u} 12 {%07.1u} 13 {%07.u}\n", unb, unb, unb, unb, unb, unb, unb, unb, unb, unb, unb, unb, 0);
	printf("\n😎\n");

	/* BIG_MAIN */
	// printf("\nTEST nb = 0 | width = 4 | precision = 0\n");
	// printf("-----\n");
	// printf("printf\n|%d| |%.d| |%0d| |%-d| |%04d| |%-04d| |%0-4d| |%04.d| |%-04.d| |%0-4.d|\n", nb, nb, nb, nb, nb, nb, nb, nb, nb, nb);
	// ft_printf("ft_printf\n|%d| |%.d| |%0d| |%-d| |%04d| |%-04d| |%0-4d| |%04.d| |%-04.d| |%0-4.d|\n", nb, nb, nb, nb, nb, nb, nb, nb, nb, nb);
	// printf("printf\n|%.0d| |%04.0d| |%-04.0d| |%0-4.0d|\n", nb, nb, nb, nb);
	// ft_printf("ft_printf\n|%.0d| |%04.0d| |%-04.0d| |%0-4.0d|\n", nb, nb, nb, nb);

/* TYPE x & X ----------------------------- */

	printf("\n\n* TYPE x ------------------------- *\n");

	hexa = 255; w = 15; p = 10;
	printf("\nprintf :	.1 {%x}  .2 {%*x}  .3 {%-*x}  .4 {%0*x}  .5 {%0*.x}  .6 {%-*.x}  .7 {%*.x}  .8 {%.*x}  .9 {%-.*x}  .10 {%0.*x}  .11 {%*.*x}  .12 {%0*.*d}  .13 {%-*.*x}\n", hexa, w, hexa, w, hexa, w, hexa, w, hexa, w, hexa, w, hexa, p, hexa, p, hexa, p, hexa, w, p, hexa, w, p, hexa, w, p, hexa);
	ft_printf("ft_printf :	.1 {%x}  .2 {%*x}  .3 {%-*x}  .4 {%0*x}  .5 {%0*.x}  .6 {%-*.x}  .7 {%*.x}  .8 {%.*x}  .9 {%-.*x}  .10 {%0.*x}  .11 {%*.*x}  .12 {%0*.*d}  .13 {%-*.*x}\n", hexa, w, hexa, w, hexa, w, hexa, w, hexa, w, hexa, w, hexa, p, hexa, p, hexa, p, hexa, w, p, hexa, w, p, hexa, w, p, hexa);

	hexa = 255; w = -15; p = -10;
	printf("\nprintf :	.1 {%x}  .2 {%*x}  .3 {%-*x}  .4 {%0*x}  .5 {%0*.x}  .6 {%-*.x}  .7 {%*.x}  .8 {%.*x}  .9 {%-.*x}  .10 {%0.*x}  .11 {%*.*x}  .12 {%0*.*d}  .13 {%-*.*x}\n", hexa, w, hexa, w, hexa, w, hexa, w, hexa, w, hexa, w, hexa, p, hexa, p, hexa, p, hexa, w, p, hexa, w, p, hexa, w, p, hexa);
	ft_printf("ft_printf :	.1 {%x}  .2 {%*x}  .3 {%-*x}  .4 {%0*x}  .5 {%0*.x}  .6 {%-*.x}  .7 {%*.x}  .8 {%.*x}  .9 {%-.*x}  .10 {%0.*x}  .11 {%*.*x}  .12 {%0*.*d}  .13 {%-*.*x}\n", hexa, w, hexa, w, hexa, w, hexa, w, hexa, w, hexa, w, hexa, p, hexa, p, hexa, p, hexa, w, p, hexa, w, p, hexa, w, p, hexa);

	hexa = 0; w = 0; p = 0;
	printf("\nprintf :	.1 {%x}  .2 {%*x}  .3 {%-*x}  .4 {%0*x}  .5 {%0*.x}  .6 {%-*.x}  .7 {%*.x}  .8 {%.*x}  .9 {%-.*x}  .10 {%0.*x}  .11 {%*.*x}  .12 {%0*.*d}  .13 {%-*.*x}\n", hexa, w, hexa, w, hexa, w, hexa, w, hexa, w, hexa, w, hexa, p, hexa, p, hexa, p, hexa, w, p, hexa, w, p, hexa, w, p, hexa);
	ft_printf("ft_printf :	.1 {%x}  .2 {%*x}  .3 {%-*x}  .4 {%0*x}  .5 {%0*.x}  .6 {%-*.x}  .7 {%*.x}  .8 {%.*x}  .9 {%-.*x}  .10 {%0.*x}  .11 {%*.*x}  .12 {%0*.*d}  .13 {%-*.*x}\n", hexa, w, hexa, w, hexa, w, hexa, w, hexa, w, hexa, w, hexa, p, hexa, p, hexa, p, hexa, w, p, hexa, w, p, hexa, w, p, hexa);

	hexa = 1; w = 5; p = 3;
	printf("\nprintf :	.1 {%x}  .2 {%*x}  .3 {%-*x}  .4 {%0*x}  .5 {%0*.x}  .6 {%-*.x}  .7 {%*.x}  .8 {%.*x}  .9 {%-.*x}  .10 {%0.*x}  .11 {%*.*x}  .12 {%0*.*d}  .13 {%-*.*x}\n", hexa, w, hexa, w, hexa, w, hexa, w, hexa, w, hexa, w, hexa, p, hexa, p, hexa, p, hexa, w, p, hexa, w, p, hexa, w, p, hexa);
	ft_printf("ft_printf :	.1 {%x}  .2 {%*x}  .3 {%-*x}  .4 {%0*x}  .5 {%0*.x}  .6 {%-*.x}  .7 {%*.x}  .8 {%.*x}  .9 {%-.*x}  .10 {%0.*x}  .11 {%*.*x}  .12 {%0*.*d}  .13 {%-*.*x}\n", hexa, w, hexa, w, hexa, w, hexa, w, hexa, w, hexa, w, hexa, p, hexa, p, hexa, p, hexa, w, p, hexa, w, p, hexa, w, p, hexa);

	hexa = 1; w = 1; p = 1;
	printf("\nprintf :	.1 {%x}  .2 {%*x}  .3 {%-*x}  .4 {%0*x}  .5 {%0*.x}  .6 {%-*.x}  .7 {%*.x}  .8 {%.*x}  .9 {%-.*x}  .10 {%0.*x}  .11 {%*.*x}  .12 {%0*.*d}  .13 {%-*.*x}\n", hexa, w, hexa, w, hexa, w, hexa, w, hexa, w, hexa, w, hexa, p, hexa, p, hexa, p, hexa, w, p, hexa, w, p, hexa, w, p, hexa);
	ft_printf("ft_printf :	.1 {%x}  .2 {%*x}  .3 {%-*x}  .4 {%0*x}  .5 {%0*.x}  .6 {%-*.x}  .7 {%*.x}  .8 {%.*x}  .9 {%-.*x}  .10 {%0.*x}  .11 {%*.*x}  .12 {%0*.*d}  .13 {%-*.*x}\n", hexa, w, hexa, w, hexa, w, hexa, w, hexa, w, hexa, w, hexa, p, hexa, p, hexa, p, hexa, w, p, hexa, w, p, hexa, w, p, hexa);

	hexa = 1; w = 3; p = 7;
	printf("\nprintf :	.1 {%x}  .2 {%*x}  .3 {%-*x}  .4 {%0*x}  .5 {%0*.x}  .6 {%-*.x}  .7 {%*.x}  .8 {%.*x}  .9 {%-.*x}  .10 {%0.*x}  .11 {%*.*x}  .12 {%0*.*d}  .13 {%-*.*x}\n", hexa, w, hexa, w, hexa, w, hexa, w, hexa, w, hexa, w, hexa, p, hexa, p, hexa, p, hexa, w, p, hexa, w, p, hexa, w, p, hexa);
	ft_printf("ft_printf :	.1 {%x}  .2 {%*x}  .3 {%-*x}  .4 {%0*x}  .5 {%0*.x}  .6 {%-*.x}  .7 {%*.x}  .8 {%.*x}  .9 {%-.*x}  .10 {%0.*x}  .11 {%*.*x}  .12 {%0*.*d}  .13 {%-*.*x}\n", hexa, w, hexa, w, hexa, w, hexa, w, hexa, w, hexa, w, hexa, p, hexa, p, hexa, p, hexa, w, p, hexa, w, p, hexa, w, p, hexa);

	hexa = 254; w = 10; p = 5;
	printf("\nprintf :	.1 {%x}  .2 {%*x}  .3 {%-*x}  .4 {%0*x}  .5 {%0*.x}  .6 {%-*.x}  .7 {%*.x}  .8 {%.*x}  .9 {%-.*x}  .10 {%0.*x}  .11 {%*.*x}  .12 {%0*.*d}  .13 {%-*.*x}\n", hexa, w, hexa, w, hexa, w, hexa, w, hexa, w, hexa, w, hexa, p, hexa, p, hexa, p, hexa, w, p, hexa, w, p, hexa, w, p, hexa);
	ft_printf("ft_printf :	.1 {%x}  .2 {%*x}  .3 {%-*x}  .4 {%0*x}  .5 {%0*.x}  .6 {%-*.x}  .7 {%*.x}  .8 {%.*x}  .9 {%-.*x}  .10 {%0.*x}  .11 {%*.*x}  .12 {%0*.*d}  .13 {%-*.*x}\n", hexa, w, hexa, w, hexa, w, hexa, w, hexa, w, hexa, w, hexa, p, hexa, p, hexa, p, hexa, w, p, hexa, w, p, hexa, w, p, hexa);

	hexa = 201; w = 7; p = 4;
	printf("\nprintf :	.1 {%x}  .2 {%*x}  .3 {%-*x}  .4 {%0*x}  .5 {%0*.x}  .6 {%-*.x}  .7 {%*.x}  .8 {%.*x}  .9 {%-.*x}  .10 {%0.*x}  .11 {%*.*x}  .12 {%0*.*d}  .13 {%-*.*x}\n", hexa, w, hexa, w, hexa, w, hexa, w, hexa, w, hexa, w, hexa, p, hexa, p, hexa, p, hexa, w, p, hexa, w, p, hexa, w, p, hexa);
	ft_printf("ft_printf :	.1 {%x}  .2 {%*x}  .3 {%-*x}  .4 {%0*x}  .5 {%0*.x}  .6 {%-*.x}  .7 {%*.x}  .8 {%.*x}  .9 {%-.*x}  .10 {%0.*x}  .11 {%*.*x}  .12 {%0*.*d}  .13 {%-*.*x}\n", hexa, w, hexa, w, hexa, w, hexa, w, hexa, w, hexa, w, hexa, p, hexa, p, hexa, p, hexa, w, p, hexa, w, p, hexa, w, p, hexa);

	hexa = 33;
	printf("\nprintf :	1 {%x} 2 {%7x} 3 {%1x} 4 {%-7x} 5 {%07x} 6 {%.x} 7 {%-.x} 8 {%07.5x} 9 {%-7.5x} 10 {%07.x} 11 {%-7.1x} 12 {%07.1x} 13 {%07.x}\n", hexa, hexa, hexa, hexa, hexa, hexa, hexa, hexa, hexa, hexa, hexa, hexa, 0);
	ft_printf("ft_printf :	1 {%x} 2 {%7x} 3 {%1x} 4 {%-7x} 5 {%07x} 6 {%.x} 7 {%-.x} 8 {%07.5x} 9 {%-7.5x} 10 {%07.x} 11 {%-7.1x} 12 {%07.1x} 13 {%07.x}\n", hexa, hexa, hexa, hexa, hexa, hexa, hexa, hexa, hexa, hexa, hexa, hexa, 0);
	printf("\n😎\n");

	// printf("\n\n* TYPE X ------------------------- *\n");

	hexa = 255; w = 15; p = 10;
	printf("\nprintf :	.1 {%X}  .2 {%*X}  .3 {%-*X}  .4 {%0*X}  .5 {%0*.X}  .6 {%-*.X}  .7 {%*.X}  .8 {%.*X}  .9 {%-.*X}  .10 {%0.*X}  .11 {%*.*X}  .12 {%0*.*X}  .13 {%-*.*X}\n", hexa, w, hexa, w, hexa, w, hexa, w, hexa, w, hexa, w, hexa, p, hexa, p, hexa, p, hexa, w, p, hexa, w, p, hexa, w, p, hexa);
	ft_printf("ft_printf :	.1 {%X}  .2 {%*X}  .3 {%-*X}  .4 {%0*X}  .5 {%0*.X}  .6 {%-*.X}  .7 {%*.X}  .8 {%.*X}  .9 {%-.*X}  .10 {%0.*X}  .11 {%*.*X}  .12 {%0*.*X}  .13 {%-*.*X}\n", hexa, w, hexa, w, hexa, w, hexa, w, hexa, w, hexa, w, hexa, p, hexa, p, hexa, p, hexa, w, p, hexa, w, p, hexa, w, p, hexa);

	hexa = 255; w = -15; p = -10;
	printf("\nprintf :	.1 {%X}  .2 {%*X}  .3 {%-*X}  .4 {%0*X}  .5 {%0*.X}  .6 {%-*.X}  .7 {%*.X}  .8 {%.*X}  .9 {%-.*X}  .10 {%0.*X}  .11 {%*.*X}  .12 {%0*.*X}  .13 {%-*.*X}\n", hexa, w, hexa, w, hexa, w, hexa, w, hexa, w, hexa, w, hexa, p, hexa, p, hexa, p, hexa, w, p, hexa, w, p, hexa, w, p, hexa);
	ft_printf("ft_printf :	.1 {%X}  .2 {%*X}  .3 {%-*X}  .4 {%0*X}  .5 {%0*.X}  .6 {%-*.X}  .7 {%*.X}  .8 {%.*X}  .9 {%-.*X}  .10 {%0.*X}  .11 {%*.*X}  .12 {%0*.*X}  .13 {%-*.*X}\n", hexa, w, hexa, w, hexa, w, hexa, w, hexa, w, hexa, w, hexa, p, hexa, p, hexa, p, hexa, w, p, hexa, w, p, hexa, w, p, hexa);

	hexa = 0; w = 0; p = 0;
	printf("\nprintf :	.1 {%X}  .2 {%*X}  .3 {%-*X}  .4 {%0*X}  .5 {%0*.X}  .6 {%-*.X}  .7 {%*.X}  .8 {%.*X}  .9 {%-.*X}  .10 {%0.*X}  .11 {%*.*X}  .12 {%0*.*X}  .13 {%-*.*X}\n", hexa, w, hexa, w, hexa, w, hexa, w, hexa, w, hexa, w, hexa, p, hexa, p, hexa, p, hexa, w, p, hexa, w, p, hexa, w, p, hexa);
	ft_printf("ft_printf :	.1 {%X}  .2 {%*X}  .3 {%-*X}  .4 {%0*X}  .5 {%0*.X}  .6 {%-*.X}  .7 {%*.X}  .8 {%.*X}  .9 {%-.*X}  .10 {%0.*X}  .11 {%*.*X}  .12 {%0*.*X}  .13 {%-*.*X}\n", hexa, w, hexa, w, hexa, w, hexa, w, hexa, w, hexa, w, hexa, p, hexa, p, hexa, p, hexa, w, p, hexa, w, p, hexa, w, p, hexa);

	hexa = 1; w = 5; p = 3;
	printf("\nprintf :	.1 {%X}  .2 {%*X}  .3 {%-*X}  .4 {%0*X}  .5 {%0*.X}  .6 {%-*.X}  .7 {%*.X}  .8 {%.*X}  .9 {%-.*X}  .10 {%0.*X}  .11 {%*.*X}  .12 {%0*.*X}  .13 {%-*.*X}\n", hexa, w, hexa, w, hexa, w, hexa, w, hexa, w, hexa, w, hexa, p, hexa, p, hexa, p, hexa, w, p, hexa, w, p, hexa, w, p, hexa);
	ft_printf("ft_printf :	.1 {%X}  .2 {%*X}  .3 {%-*X}  .4 {%0*X}  .5 {%0*.X}  .6 {%-*.X}  .7 {%*.X}  .8 {%.*X}  .9 {%-.*X}  .10 {%0.*X}  .11 {%*.*X}  .12 {%0*.*X}  .13 {%-*.*X}\n", hexa, w, hexa, w, hexa, w, hexa, w, hexa, w, hexa, w, hexa, p, hexa, p, hexa, p, hexa, w, p, hexa, w, p, hexa, w, p, hexa);

	hexa = 1; w = 1; p = 1;
	printf("\nprintf :	.1 {%X}  .2 {%*X}  .3 {%-*X}  .4 {%0*X}  .5 {%0*.X}  .6 {%-*.X}  .7 {%*.X}  .8 {%.*X}  .9 {%-.*X}  .10 {%0.*X}  .11 {%*.*X}  .12 {%0*.*X}  .13 {%-*.*X}\n", hexa, w, hexa, w, hexa, w, hexa, w, hexa, w, hexa, w, hexa, p, hexa, p, hexa, p, hexa, w, p, hexa, w, p, hexa, w, p, hexa);
	ft_printf("ft_printf :	.1 {%X}  .2 {%*X}  .3 {%-*X}  .4 {%0*X}  .5 {%0*.X}  .6 {%-*.X}  .7 {%*.X}  .8 {%.*X}  .9 {%-.*X}  .10 {%0.*X}  .11 {%*.*X}  .12 {%0*.*X}  .13 {%-*.*X}\n", hexa, w, hexa, w, hexa, w, hexa, w, hexa, w, hexa, w, hexa, p, hexa, p, hexa, p, hexa, w, p, hexa, w, p, hexa, w, p, hexa);

	hexa = 1; w = 3; p = 7;
	printf("\nprintf :	.1 {%X}  .2 {%*X}  .3 {%-*X}  .4 {%0*X}  .5 {%0*.X}  .6 {%-*.X}  .7 {%*.X}  .8 {%.*X}  .9 {%-.*X}  .10 {%0.*X}  .11 {%*.*X}  .12 {%0*.*X}  .13 {%-*.*X}\n", hexa, w, hexa, w, hexa, w, hexa, w, hexa, w, hexa, w, hexa, p, hexa, p, hexa, p, hexa, w, p, hexa, w, p, hexa, w, p, hexa);
	ft_printf("ft_printf :	.1 {%X}  .2 {%*X}  .3 {%-*X}  .4 {%0*X}  .5 {%0*.X}  .6 {%-*.X}  .7 {%*.X}  .8 {%.*X}  .9 {%-.*X}  .10 {%0.*X}  .11 {%*.*X}  .12 {%0*.*X}  .13 {%-*.*X}\n", hexa, w, hexa, w, hexa, w, hexa, w, hexa, w, hexa, w, hexa, p, hexa, p, hexa, p, hexa, w, p, hexa, w, p, hexa, w, p, hexa);

	hexa = 254; w = 10; p = 5;
	printf("\nprintf :	.1 {%X}  .2 {%*X}  .3 {%-*X}  .4 {%0*X}  .5 {%0*.X}  .6 {%-*.X}  .7 {%*.X}  .8 {%.*X}  .9 {%-.*X}  .10 {%0.*X}  .11 {%*.*X}  .12 {%0*.*X}  .13 {%-*.*X}\n", hexa, w, hexa, w, hexa, w, hexa, w, hexa, w, hexa, w, hexa, p, hexa, p, hexa, p, hexa, w, p, hexa, w, p, hexa, w, p, hexa);
	ft_printf("ft_printf :	.1 {%X}  .2 {%*X}  .3 {%-*X}  .4 {%0*X}  .5 {%0*.X}  .6 {%-*.X}  .7 {%*.X}  .8 {%.*X}  .9 {%-.*X}  .10 {%0.*X}  .11 {%*.*X}  .12 {%0*.*X}  .13 {%-*.*X}\n", hexa, w, hexa, w, hexa, w, hexa, w, hexa, w, hexa, w, hexa, p, hexa, p, hexa, p, hexa, w, p, hexa, w, p, hexa, w, p, hexa);

	hexa = 201; w = 7; p = 4;
	printf("\nprintf :	.1 {%X}  .2 {%*X}  .3 {%-*X}  .4 {%0*X}  .5 {%0*.X}  .6 {%-*.X}  .7 {%*.X}  .8 {%.*X}  .9 {%-.*X}  .10 {%0.*X}  .11 {%*.*X}  .12 {%0*.*X}  .13 {%-*.*X}\n", hexa, w, hexa, w, hexa, w, hexa, w, hexa, w, hexa, w, hexa, p, hexa, p, hexa, p, hexa, w, p, hexa, w, p, hexa, w, p, hexa);
	ft_printf("ft_printf :	.1 {%X}  .2 {%*X}  .3 {%-*X}  .4 {%0*X}  .5 {%0*.X}  .6 {%-*.X}  .7 {%*.X}  .8 {%.*X}  .9 {%-.*X}  .10 {%0.*X}  .11 {%*.*X}  .12 {%0*.*X}  .13 {%-*.*X}\n", hexa, w, hexa, w, hexa, w, hexa, w, hexa, w, hexa, w, hexa, p, hexa, p, hexa, p, hexa, w, p, hexa, w, p, hexa, w, p, hexa);

	hexa = 33;
	printf("\nprintf :	.1 {%X}  .2 {%*X}  .3 {%-*X}  .4 {%0*X}  .5 {%0*.X}  .6 {%-*.X}  .7 {%*.X}  .8 {%.*X}  .9 {%-.*X}  .10 {%0.*X}  .11 {%*.*X}  .12 {%0*.*X}  .13 {%-*.*X}\n", hexa, w, hexa, w, hexa, w, hexa, w, hexa, w, hexa, w, hexa, p, hexa, p, hexa, p, hexa, w, p, hexa, w, p, hexa, w, p, hexa);
	ft_printf("ft_printf :	.1 {%X}  .2 {%*X}  .3 {%-*X}  .4 {%0*X}  .5 {%0*.X}  .6 {%-*.X}  .7 {%*.X}  .8 {%.*X}  .9 {%-.*X}  .10 {%0.*X}  .11 {%*.*X}  .12 {%0*.*X}  .13 {%-*.*X}\n", hexa, w, hexa, w, hexa, w, hexa, w, hexa, w, hexa, w, hexa, p, hexa, p, hexa, p, hexa, w, p, hexa, w, p, hexa, w, p, hexa);
	printf("\n😎\n");

/* TYPE C --------------------------------- */

	printf("\n\n* TYPE C ------------------------- *\n");

	c = 'Q'; w = 15;
	printf("\nprintf :	.1 {%c}  .2 {%*c}  .3 {%-*c}  .4 {%0*c}  .5 {%-0*c}\n", c, w, c, w, c, w, c, w, c, w, c);
	ft_printf("ft_printf :	.1 {%c}  .2 {%*c}  .3 {%-*c}  .4 {%0*c}  .5 {%-0*c}\n", c, w, c, w, c, w, c, w, c, w, c);
	printf("\n😎\n");
	return 0;
}

// INT_MAX 2147483647
// UINT_MAX 4294967295