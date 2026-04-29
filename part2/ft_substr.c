#include "libft.h"

char    *ft_substr(char const *s, unsigned int start, size_t len)
{
    char    *substr;

    if (s == NULL)
        return (NULL);
    substr = (char *)malloc((len + 1) * sizeof(char));
    if (substr == NULL)
        return (NULL);
    ft_memcpy(substr, s + start, len);
    substr[len] = '\0';
    return (substr);
}
