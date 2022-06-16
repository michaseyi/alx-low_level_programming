#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int rand()
{
   char *numbers = "9 8 10 24 75 - 9\n";
   char *jackpot = "Congratulations, you win the Jackpot!\n";
   write(1, numbers, strlen(numbers));
   write(1, jackpot, strlen(jackpot));
   exit(0);
   return (0);
}
