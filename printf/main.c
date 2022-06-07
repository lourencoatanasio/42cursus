#include <unistd.h>
#include <stdio.h>
#include "ft_printf.h"
#include <limits.h>
int main()
{
  printf(" %d\n", ft_printf(" %p %p ", LONG_MIN, LONG_MAX));
  write(1, "\n", 1);
  //printf(" %d\n", printf(" %p %p ", LONG_MIN, LONG_MAX));
}
