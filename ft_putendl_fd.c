#include "libft.h"
#include <unistd.h>

void    ft_putendl_fd(char *s, int fd)
{
    if (s == NULL)
        return ;
    ft_putstr_fd(s, fd);
    ft_putchar_fd('\n', fd);
}