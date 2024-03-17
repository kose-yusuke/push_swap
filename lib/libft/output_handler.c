/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykoseki <ykoseki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 00:40:44 by ykoseki           #+#    #+#             */
/*   Updated: 2023/06/04 05:12:34 by ykoseki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	output_handler(char output_type, va_list args)
{
	int	number;

	number = 0;
	if (output_type == 'c')
		number = ft_char(va_arg(args, int));
	else if (output_type == 's')
		number = ft_string(va_arg(args, char *));
	else if (output_type == 'p')
		number = ft_pointer(va_arg(args, unsigned long long));
	else if (output_type == 'd' || output_type == 'i')
		number = ft_integer(va_arg(args, int));
	else if (output_type == 'u')
		number = ft_unsigned(va_arg(args, unsigned int));
	else if (output_type == 'x')
		number = ft_hexlower(va_arg(args, unsigned int));
	else if (output_type == 'X')
		number = ft_hexupper(va_arg(args, unsigned int));
	else if (output_type == '%')
		number = ft_percent('%');
	return (number);
}
