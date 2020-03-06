#include "ft_printf.h"

int     ft_strlen(char *str)
{
    int len;

    len = 0;
    while (str[len])
        len++;
    return(len);
}

int		type_s(t_data *data)
{
	char    *s;
	int     len;
	
	s = va_arg(data->ap, char*);
	len = ft_strlen(s);
	check_debug(data);
	print_debug("\n********* TYPE_S *********\n", data, 'S');
    if (s == NULL)
        s = "(null)";
	// if (data->info.mask & IS_PRECISION)
	// {
		// data->info.mask ^= IS_ZERO;
		// calc_precision(data, len, nb);
	// }
	if(data->info.mask & IS_WIDTH)
    {
        if(data->info.mask & IS_MINUS)
        {
            data->nb_char += len;
            // on print la string;
            write(1, &s, len);
            // puis les espaces; // combien ? w - len
            print_flags(data, data->info.w_value, len, ' ');
        }
        if (data->info.mask & IS_ZERO)
        {
            // on print les zeros;
            print_flags(data, data->info.w_value, len, '0');
        }
        else
        {
            // on print les espaces;
            print_flags(data, data->info.w_value, len, ' ');
        }
    }
	if (!(data->info.mask & IS_MINUS)) // else
	{
        data->nb_char += len;
		// on print la string
        write(1, &s, len);
	}
	data->format++;
	return (0);
}