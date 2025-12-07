/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzebian <kzebian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 23:36:07 by kzebian           #+#    #+#             */
/*   Updated: 2025/05/24 18:09:37 by kzebian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

size_t	ft_strlen(const char *s);

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*st;
	size_t	i;
	size_t	newlen;

	i = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		st = malloc(1);
		st[0] = '\0';
		return (st);
	}
	newlen = ft_strlen(s + start);
	if (len > newlen)
		len = newlen;
	st = (char *)malloc(sizeof(char) * (len + 1));
	if (!st)
		return (NULL);
	while (s[start] && i < len)
	{
		st[i++] = s[start++];
	}
	st[i] = '\0';
	return (st);
}

// int main() {
//     const char str1[] = "felipe de paula alves montes";
//     char *str2 = ft_substr(str1, 6, 14); // Exemplo: extrair "de paula alves"

//     if (str2 != NULL) {
//         printf("Substring: %s\n", str2);
//         free(str2); // Libere a memória alocada
//     } else {
//         printf("Falha na alocação de memória.\n");
//     }

//     return 0;
// }