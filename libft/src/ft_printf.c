/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcazac <pcazac@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 09:41:44 by pcazac            #+#    #+#             */
/*   Updated: 2023/06/03 23:45:35 by pcazac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

static int	element_finder(va_list ap, const char *format, int *count);
static int	putptr(void *input, char *base, int *count);
static int	ft_putint(long input, char *base, int *count);
int			putbase_pf(size_t input, char *base, size_t b_len, int *count);

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] != '%')
		{
			if (write(1, &format[i], 1) < 0)
				return (-1);
			count++;
		}
		if (format[i] == '%' && format[i + 1])
		{
			if (element_finder(ap, &format[++i], &count) < 0)
				return (-1);
		}
		i++;
	}
	va_end(ap);
	return (count);
}

static int	element_finder(va_list ap, const char *format, int *count)
{
	int	i;

	i = 0;
	if (*format == '%')
	{
		i = write(1, format, 1);
		(*count)++;
	}
	if (*format == 'c')
		i = ft_putchar_pf(va_arg(ap, int), count);
	if (*format == 's')
		i = ft_putstr_pf(va_arg(ap, char *), count);
	if (*format == 'p')
		i = putptr(va_arg(ap, void *), "0123456789abcdef", count);
	if (*format == 'd' || *format == 'i')
		i = ft_putint((long) va_arg(ap, int), "0123456789", count);
	if (*format == 'u')
		i = putbase_pf(va_arg(ap, unsigned int), "0123456789", 10, count);
	if (*format == 'x')
		i = putbase_pf(va_arg(ap, unsigned int), "0123456789abcdef", 16, count);
	if (*format == 'X')
		i = putbase_pf(va_arg(ap, unsigned int), "0123456789ABCDEF", 16, count);
	return (i);
}

static int	putptr(void *input, char *base, int *count)
{
	size_t	ptr;
	int		i;

	i = 0;
	ptr = (size_t) input;
	if (write(1, "0x", 2) < 0)
		return (-1);
	*count = *count + 2;
	i = putbase_pf(ptr, base, 16, count);
	return (i);
}

static int	ft_putint(long input, char *base, int *count)
{
	int	i;

	i = 0;
	if (input < 0)
	{
		if (write(1, "-", 1) < 0)
			return (-1);
		(*count)++;
		i = putbase_pf(input * -1, base, 10, count);
	}
	if (input >= 0)
		i = putbase_pf(input, base, 10, count);
	return (i);
}
