#include "libft/libft.h"

int main()
{
    // int id = getgid();
    ft_putstr_fd("Server PID:", 1);
    ft_putnbr_fd(getgid(), 1);
}