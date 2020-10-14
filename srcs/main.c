/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpladet <gpladet.student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 23:10:56 by gpladet           #+#    #+#             */
/*   Updated: 2020/10/08 16:58:21 by gpladet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>

size_t	ft_strlen(const char *str);
char	*ft_strcpy(char *dst, const char *src);
int		ft_strcmp(const char *src, const char *dst);
ssize_t	ft_write(int fd, void const *buf, size_t nbyte);
ssize_t	ft_read(int fd, void *buf, size_t nbyte);
char	*ft_strdup(const char *str);

int	main(void)
{
	char	tmp[42];
	char	*str;
	int		errno;

	printf("===========================\n");
	printf("         FT_STRLEN         \n");
	printf("===========================\n\n");

	printf("ft_strlen : %zu\n", ft_strlen(""));
	printf("strlen : %zu\n\n", strlen(""));

	printf("ft_strlen : %zu\n", ft_strlen("abcdef"));
	printf("strlen : %zu\n\n", strlen("abcdef"));

	printf("ft_strlen : %zu\n", ft_strlen("Hello World"));
	printf("strlen : %zu\n\n", strlen("Hello World"));

	printf("ft_strlen : %zu\n", ft_strlen("\n"));
	printf("strlen : %zu\n\n", strlen("\n"));

	printf("ft_strlen : %zu\n", ft_strlen("29281989294924989182891492919090310"));
	printf("strlen : %zu\n\n", strlen("29281989294924989182891492919090310"));

	printf("===========================\n");
	printf("         FT_STRCPY         \n");
	printf("===========================\n\n");

	printf("strcpy : |%s|\n", strcpy(tmp, "world"));
	printf("ft_strcpy : |%s|\n\n", ft_strcpy(tmp, "world"));

	printf("strcpy : |%s|\n", strcpy(tmp, "hello world"));
	printf("ft_strcpy : |%s|\n\n", ft_strcpy(tmp, "hello world"));

	printf("strcpy : |%s|\n", strcpy(tmp, ""));
	printf("ft_strcpy : |%s|\n\n", ft_strcpy(tmp, ""));

	printf("strcpy : |%s|\n", strcpy(tmp, "enjjweiofhfiuhgeiwoijqbvwjfeojefkj"));
	printf("ft_strcpy : |%s|\n\n", ft_strcpy(tmp, "enjjweiofhfiuhgeiwoijqbvwjfeojefkj"));

	printf("strcpy : |%s|\n", strcpy(tmp, "Ceci est un test"));
	printf("ft_strcpy : |%s|\n\n", ft_strcpy(tmp, "Ceci est un test"));

	printf("===========================\n");
	printf("         FT_STRCMP         \n");
	printf("===========================\n\n");

	printf("strcmp : |%d|\n", strcmp("hello", "hello"));
	printf("ft_strcmp : |%d|\n\n", ft_strcmp("hello", "hello"));

	printf("strcmp : |%d|\n", strcmp("azerty", "qwerty"));
	printf("ft_strcmp : |%d|\n\n", ft_strcmp("azerty", "qwerty"));

	printf("strcmp : |%d|\n", strcmp("ecole", "42"));
	printf("ft_strcmp : |%d|\n\n", ft_strcmp("ecole", "42"));

	printf("strcmp : |%d|\n", strcmp("jnevjiviivni", "eiwjioqjwd"));
	printf("ft_strcmp : |%d|\n\n", ft_strcmp("jnevjiviivni", "eiwjioqjwd"));

	printf("strcmp : |%d|\n", strcmp("\n", "\0"));
	printf("ft_strcmp : |%d|\n\n", ft_strcmp("\n", "\0"));

	printf("===========================\n");
	printf("         FT_WRITE          \n");
	printf("===========================\n\n");

	write(1, "Hello world\n", 13);
	ft_write(1, "Hello world\n\n", 13);

	errno = 0;
   	write(0xff, "hello!\n", 7);
	printf("errno : %d\n", errno);
	errno = 0;
	ft_write(0xff, "hello!\n", 7);
	printf("errno : %d\n\n", errno);

	write(0, "Bonjour les amis\n", 18);
	ft_write(0, "Bonjour les amis\n\n", 18);

	errno = 0;
	write(1, "hello!\n", -6);
	printf("errno : %d\n", errno);
	errno = 0;
	ft_write(1, "hello!\n", -6);
	printf("errno : %d\n\n", errno);

	errno = 0;
	write(0, NULL, 0);
	printf("errno : %d\n", errno);
	errno = 0;
	ft_write(0, NULL, 0);
	printf("errno : %d\n", errno);

	printf("===========================\n");
	printf("         FT_READ           \n");
	printf("===========================\n\n");

	char buffer[100];

	read(0, buffer, 29);
	ft_read(0, buffer, 29);

	errno = 0;
   	read(0xff, buffer, 50);
	printf("errno : %d\n", errno);
	errno = 0;
	ft_read(0xff, buffer, 50);
	printf("errno : %d\n\n", errno);

	printf("===========================\n");
	printf("         FT_STRDUP          \n");
	printf("===========================\n\n");

	str = strdup("Hello");
	printf("%s\n", str);
	free(str);
	str = ft_strdup("Hello");
	printf("%s\n\n", str);
	free(str);

	str = strdup("Bonjour les amis !");
	printf("%s\n", str);
	free(str);
	str = ft_strdup("Bonjour les amis !");
	printf("%s\n\n", str);
	free(str);
}
