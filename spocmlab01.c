#include <stdio.h>
#include <stdlib.h>
#include "funclab01.h"

#define MAX_int 1024
#define MAX_char 512

int main(void)
{
    unsigned int number_1[MAX_int], number_2[MAX_int], result[MAX_int*2], *p_number_1, *p_number_2, *p_result, num_of_symbs = 0;
    char hex_num_1[MAX_char], hex_num_2[MAX_char], hex_result[MAX_char*2], *p_hex_num_1, *p_hex_num_2, *p_hex_result, ch;
    p_hex_num_1 = hex_num_1;
    p_hex_num_2 = hex_num_2;
    p_number_1 = number_1;
    p_number_2 = number_2;
    p_result = result;

    puts("\nPlease, type in the first number in hexadecimal form below:\n");
    while ((ch = getchar()) != '\n' && num_of_symbs < (MAX_char + 1))
    {
        *p_hex_num_1 = ch;
        *p_hex_num_1++;
        num_of_symbs++;
    }
    p_hex_num_1--;
    num_of_symbs = 0;

    puts("\n\nPlease, type in the second number in hexadecimal form below:\n");
    while ((ch = getchar()) != '\n' && num_of_symbs < (MAX_char + 1))
    {
        *p_hex_num_2 = ch;
        *p_hex_num_2++;
        num_of_symbs++;
    }
    p_hex_num_2--;

    hex_to_int_conversion(p_hex_num_1, p_number_1, num_of_symbs);
    hex_to_int_conversion(p_hex_num_2, p_number_2, num_of_symbs);

    p_number_1 = number_1;
    p_number_2 = number_2;

    multiplication_of_two(p_number_1, p_number_2, p_result, num_of_symbs);
    
    p_result = result;
    p_hex_result = hex_result + num_of_symbs*2;
    int_to_hex_conversion(p_result, p_hex_result, num_of_symbs*2);

    p_result = result;
    p_hex_result = hex_result;

    int j;
    puts("\n\nResult in int form:\n");
    for (j = 0; j < num_of_symbs*2; j++)
        printf("%d  ", *p_result++);    
 
    puts("\n\nResult in hex form:\n");
    for(j = 0; j < num_of_symbs*2; j++)
    { 
        printf("%c", *p_hex_result++);
    }
    puts("\n");

    system("PAUSE");
    return 0;
}