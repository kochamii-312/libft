#include <libft.h>
#include <stdlib.h>

char    *ft_strtrim(char const *s1, char const *set)
{
    char    *trimmed;
    size_t  start;
    size_t  end;

    if (s1 == NULL || set == NULL)
        return (NULL);
    start = 0;
    while (s1[start] != '\0' && ft_strchr(set, s1[start]) != NULL)
        start++;
    end = ft_strlen(s1);
    while (end > start && ft_strchr(set, s1[end - 1]) != NULL)
        end--;
    if (start >= end)
        trimmed = ft_substr("", 0, 1);
    else
        trimmed = ft_substr(s1, start, end - start);
    return (trimmed);
}
