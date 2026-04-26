#include <libft.h>
#include <unistd.h>

void    ft_itoa(int n, char *str)
{
    long    num;
    size_t  len;

    num = n;
    if (num < 0)
    {
        str[0] = '-';
        num = -num;
    }
    len = 0;
    while (num >= 10)
    {
        str[len] = (num % 10) + '0';
        num = num / 10;
        len++;
    }
    str[len] = num + '0';
    str[len + 1] = '\0';
}
