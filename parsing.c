/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserra <vserra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 20:10:25 by vserra            #+#    #+#             */
/*   Updated: 2020/01/10 15:12:42 by vserra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

// toutes les fonctions de tab doivent avoir le meme prototype

// découper
// traiter et aficher
// reset info

void	get_arg(const char *str, va_list ap, t_info *info)
{
	int i;
	// t_info info;

	info->mask = 0;
	info->width_value = 0;
	info->prec_value = 0;
	i = 0;
	while(str[i])
	{

		while (str[i] != '%') // compter le nombre de carateres affichés
		{
			write(1, str, i);
			i++;
		}

			while(str[i] != 'c' || str[i] != 's' || str[i] != 'p' || str[i] != 'd'
					|| str[i] != 'i' || str[i] != 'u' || str[i] != 'x'
					|| str[i] != 'X' || str[i] != '%')
			{
				if (str[i] == '-') // || str[i + 1] == '-'
					info->mask = (info->mask | IS_MINUS);
				if (str[i] == '0' && !info->width_value) // /!\ peut etre avant ou apres le zero
					info->mask = (info->mask | IS_ZERO);


				// /!\ a bien differencier le flag 0 d'un 0 dans un nombre !


				if (str[i] >= '0' && str[i] <= '9') // is_num
				{
					info->mask = (info->mask | IS_WIDTH);
					//prendre la valeur et le stocker dans info->width_value : atoi
					// while (str[i] >= '0' && str[i] < '9') // boucler ? 
					// modifier mon atoi ? envoyer l'index a atoi en param ? 
					// calculer longueur nb ?
					// {
						info->width_value = atoi(str);
					// }
				}
				if (str[i] == '*')
					//prendre la valeur et le stocker dans info->width_value : atoi
						char *temp;
						temp = va_arg(ap, char *);
						info->width_value = atoi(temp);
				if (str[i] == '.')
				{
					info->mask = (info->mask | IS_PRECISION);
					if (str[i + 1] == '*')
					{
						temp = va_arg(ap, char *);
						// ft_atoi && stocker le resultat dans info->prec_value
					}
				}
			}
		i++;
	}

}

void	parsing(const char *str, va_list ap)
{
	int i;
	t_info info;

	// info = NULL;

	i = 0;
	// Parcourir et afficher str jusqu'a %
	get_arg(str, ap, &info);

}