/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igvisera <igvisera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 21:24:50 by igvisera          #+#    #+#             */
/*   Updated: 2024/02/27 21:24:50 by igvisera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "stdarg.h"
# include <fcntl.h>
# include <limits.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef HEXLOWER
#  define HEXLOWER "0123456789abcdef"
# endif

# ifndef HEXUPPER
#  define HEXUPPER "0123456789ABCDEF"
# endif

//pertenece a basics
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlcpy(char *dst, char *src, size_t size);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s);

//pertenece a printf
int		ft_printf(char const *format, ...);
int		ft_print_char(int s);
int		ft_print_string(char *s);
int		ft_print_percent(void);
int		ft_print_unsigned(unsigned int n);
int		ft_print_int(int n);
int		ft_print_hex(unsigned long long n, char *baseFormat);
int		ft_print_pointer(unsigned long long n);


//pertenece a utils
char	*get_next_line(int fd);

#endif
