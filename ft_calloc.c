#include <libft.h>
#include <stdlib.h>

void    *ft_calloc(size_t count, size_t size)
{
    void    *ptr;

    if (count == 0 || size == 0)
        ptr == malloc(1);
    else
        ptr = malloc(count * size);
    if (ptr == NULL)
        return (NULL);
    ft_bzero(ptr, count * size);
    return (ptr);
}
