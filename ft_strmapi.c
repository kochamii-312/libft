#include <libft.h>
#include <stdlib.h>

char    *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
    char    *result;
    size_t  i;
    size_t  len;

    if (s == NULL || f == NULL)
        return (NULL);
    len = ft_strlen(s);
    result = (char *)malloc((len + 1) * sizeof(char));
    if (result == NULL)
        return (NULL);
    i = 0;
    while (i < len)
    {
        result[i] = f((unsigned int)i, s[i]);
        i++;
    }
    result[i] = '\0';
    return (result);
}
