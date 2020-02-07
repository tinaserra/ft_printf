/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gorilla.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserra <vserra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 14:26:47 by vserra            #+#    #+#             */
/*   Updated: 2020/01/24 19:09:56 by vserra           ###   ########.fr       */
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

// % [INDICATEUR][WIDTH][.PRECISION][SIZE]TYPE

// 0 : PRINT CE QUI N'EST PAS %...cspdiuxX%
// 1 : LE PARSING
// 2 : TRAITEMENT & AFFICHAGE
// 
// -			-> Alligner a gauche le resultat en fonction de la width donnée.
// 					Alligner a droite par defaut.
// 
// 0			-> Si width est préfixée de 0, ajouter des 0 jusqu'a que la width soit atteinte.
// - & 0		-> Le 0 est ignoré.
// 0 & .		-> Pour un format d, le 0 est ignoré. (%04.d)
// *			-> Recuperer la valeur en int donnée en argument.
// 0 & *		-> * est la width
// - & *		-> * est la width
// . & *		-> * est la précision