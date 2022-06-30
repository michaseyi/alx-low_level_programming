#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "hash_tables.h"

/**
 * main - check the code
 *
 * Return: Always EXIT_SUCCESS.
 */
int main(void)
{
   char *s;
   unsigned long int hash_table_array_size;

   hash_table_array_size = 1024;
   s = "c"; 
   printf("%lu\n", key_index((unsigned char *)s, hash_table_array_size));
   s = "python";
   printf("%lu\n", key_index((unsigned char *)s, hash_table_array_size));
   s = "Bob";
   printf("%lu\n", key_index((unsigned char *)s, hash_table_array_size));
   s = "N";
   printf("%lu\n", key_index((unsigned char *)s, hash_table_array_size));
   s = "Asterix";
   printf("%lu\n", key_index((unsigned char *)s, hash_table_array_size));
   s = "hetairas";
   printf("%lu\n", key_index((unsigned char *)s, hash_table_array_size));
   s = "mentioner";
   printf("%lu\n", key_index((unsigned char *)s, hash_table_array_size));
   return (EXIT_SUCCESS);
}
