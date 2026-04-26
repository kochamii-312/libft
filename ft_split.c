#include "libft.h"

size_t  word_length(char const *s, size_t start, char c)
{
    size_t  length;

    length = 0;
    while (s[start + length] != '\0' && s[start + length] != c)
        length++;
    return (length);
}

size_t  count_words(char const *s, char c)
{
    size_t  count;
    size_t  i;

    count = 0;
    i = 0;
    while (s[i] != '\0')
    {
        while (s[i] == c)
            i++;
        if (s[i] != '\0')
        {
            count++;
            i += word_length(s, i, c);
        }
    }
    return (count);
}

void    free_split(char **split)
{
    size_t  i;

    i = 0;
    while (split[i] != NULL)
    {
        free(split[i]);
        i++;
    }
    free(split);
}

char    **ft_split(char const *s, char c)
{
    char    **result;
    size_t  i;
    size_t  j;

    if (s == NULL)
        return (NULL);
    result = (char **)malloc((count_words(s, c) + 1) * sizeof(char *));
    if (result == NULL)
        return (NULL);
    i = 0;
    j = 0;
    while (s[i] != '\0')
    {
        while (s[i] == c)
            i++;
        if (s[i] != '\0')
        {
            result[j] = ft_substr(s, i, word_length(s, i, c));
            if (result[j] == NULL)
            {
                free_split(result);
                return (NULL);
            }
            j++;
            i += word_length(s, i, c);
        }
    }
    result[j] = NULL;
    return (result);
}
