/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykoseki <ykoseki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 23:55:19 by ykoseki           #+#    #+#             */
/*   Updated: 2023/07/13 21:44:22 by ykoseki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_helper(char const *format, va_list args)
{
	int	count;

	count = 0;
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			count += output_handler(*format, args);
		}
		else
		{
			write(1, format, 1);
			count++;
		}
		format++;
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		number;

	va_start(args, format);
	number = ft_printf_helper(format, args);
	va_end(args);
	return (number);
}

// int main()
// {
// 	char *test = "aaaaa";
// 	// printf("%s", "aaaaaa");
// 	// ft_printf("%c", 'a');
// 	// ft_printf("%c", 'a');
// 	// printf("%s", "");
// 	// printf("%c", '\n');
// 	// printf("%d",printf("%s", tmp));
// 	// printf("%c", '\n');
// 	// printf("%d",ft_printf("%s", tmp));
// 	printf("%d", ft_printf("%p", &test));
// 	printf("%c", '\n');
// 	printf("%d",printf("%p", &test));
// 	// ft_printf("%d", 10);
// 	// ft_printf("%i", 10);
// 	// ft_printf("%u", -10);
// 	// printf("%u", 4294967295);
// 	// ft_printf("%x", 15);
// 	// ft_printf("%X", 15);
// 	// ft_printf("%%", 16);
// }