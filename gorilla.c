/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gorilla.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserra <vserra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 14:26:47 by vserra            #+#    #+#             */
/*   Updated: 2019/12/09 18:38:12 by vserra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


// MAKEFILE
// **
// -> Nom du programme : libftprintf.a
// -> all, clean, fclean, re, bonus
// Fichiers de rendu *.c, */*.c, *.h, */*.h, Makefile
// Libft autorisée

// PROTOTYPE
// **
// int ft_printf(const char *, ...);

// FONCTIONS EXTERNES
// **
// malloc, free, write, va_start, va_arg, va_copy,
// va_end

// LES CAS
// **
// Gérer les conversions suivantes : cspdiuxX%
// Gérer n’importe quelle combinaison de flags ’-0.*’ et la taille de champ minimale
// Pas de buffer à gérer

#include <stdio.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_printf(char *first)
{
	int i;

	i = 0;
	if (first) 
	{
		while(first[i] != '\0')
		{
			//parcourir et afficher la string jusqua '%'
			while(first[i] != '%')
			{
				ft_putchar(first[i]);
				i++;
			}
			while (first[i] == '%' || first[i] == 's')
				i++;
			ft_putchar(first[i]);
			i++;
		}
		return(1);
	}
	return (0);
}

int		main()
{
	// char	*str;
	// char	c;

	// str = "Bonjour maman";
	// c = 'a';
	ft_printf("ft_printf =	%s, %%, coucou\n");
	printf("printf =	%s, %%, coucou\n");
}