#include "libft.h"
#include <stdlib.h>

void    *ft_strdup(const char *s)
{
    char *dup;
    size_t len;

    dup = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
    if (dup == NULL)
        return (NULL);
    len = 0;
    while (s[len] != '\0')
    {
        dup[len] = s[len];
        len++;
    }
    dup[len] = '\0';
    return (dup);
}
