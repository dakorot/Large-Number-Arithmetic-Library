#include <stdio.h>
#include <stdlib.h>
#include "funclab01.h"

#define MAX_int 9
#define MAX_char 7 //the biggest 32-bit sized number is FFFFFFFF = 4294967295 which makes 10 int characters MAX or 8 hex 

int main(void)
{
    unsigned int number_1[MAX_int], number_2[MAX_int], result[MAX_int+1], *p_number_1, *p_number_2, *p_result, num_of_symbs = 0;
    char hex_num_1[MAX_char], hex_num_2[MAX_char], hex_result[MAX_char+1], *p_hex_num_1, *p_hex_num_2, *p_hex_result, ch;
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

    //so far testing for two numbers with the same length
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
    addition_of_two(p_number_1, p_number_2, p_result, num_of_symbs);

    p_result = result;
    p_hex_result = hex_result + num_of_symbs;
    int_to_hex_conversion(p_result, p_hex_result, num_of_symbs+1);
  
    p_result = result;
    p_hex_result = hex_result;

    int j;
    puts("\n\nResult in int form:\n");
    for (j = 0; j < num_of_symbs+1; j++)
        printf("%d  ", *p_result++);    

    puts("\nResult in hex form:\n");
    for(j = 0; j < num_of_symbs+1; j++)
        printf("%c  ", *p_hex_result++);
    
    system("PAUSE");
    return 0;
}