#include "libft.h"
#include <stddef.h>
#include <stdlib.h>

char    *ft_substr(char const *s, unsigned int start, size_t len)
{
    char    *substr;

    if (s == NULL)
        return (NULL);
    substr = (char *)malloc((len + 1) * sizeof(char));
    if (substr == NULL)
        return (NULL);
    // strncpyをつくる
    ft_strncpy(substr, s + start, len);
    substr[len] = '\0';
    return (substr);
}
