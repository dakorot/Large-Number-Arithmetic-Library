#include <stdio.h>
#include <stdlib.h>
#include "funclab01.h"

#define MAX_int 9
#define MAX_char 7 //the biggest 32-bit sized number is FFFFFFFF = 4294967295 which makes 10 int characters MAX or 8 hex 

int main(void)
{
    unsigned int number_1[MAX_int], number_2[MAX_int], result[MAX_int+1], *p_number_1, *p_number_2, *p_result, num_of_symbs = 0;
    char hex_num_1[MAX_char], hex_num_2[MAX_char], *p_hex_num_1, *p_hex_num_2, ch;
    p_hex_num_1 = hex_num_1;
    p_hex_num_2 = hex_num_2;
    p_number_1 = number_1;
    printf("\nValue of p_number_1 at the start: %d.\n", p_hex_num_1);
    p_number_2 = number_2;
    printf("\nValue of p_number_2 at the start: %d.\n", p_number_2);

    printf("\nValue of pointer p_hex_num_1 before the loop: %d.\n", p_hex_num_1);

    puts("\nPlease, type in first number in hexadecimal form below:\n");
    while ((ch = getchar()) != '\n' && num_of_symbs < (MAX_char + 1))
    {
        *p_hex_num_1 = ch;
        *p_hex_num_1++;
        num_of_symbs++;
    }
    printf("\nValue of pointer p_hex_num_1 after the loop: %d.\n", p_hex_num_1);

    //so far testing for two numbers with the same length
    num_of_symbs = 0;

    printf("\nValue of pointer p_hex_num_1 before the loop: %d.\n", p_hex_num_2);

    puts("\n\nPlease, type in first number in hexadecimal form below:\n");
    while ((ch = getchar()) != '\n' && num_of_symbs < (MAX_char + 1))
    {
        *p_hex_num_2 = ch;
        *p_hex_num_2++;
        num_of_symbs++;
    }
    printf("\nValue of pointer p_hex_num_1 after the loop: %d.\n", p_hex_num_2);

    hex_to_int_conversion(p_hex_num_1, p_number_1, num_of_symbs);
    hex_to_int_conversion(p_hex_num_2, p_number_2, num_of_symbs);

    p_number_1 = number_1;
    printf("\nValue of p_number_1 is %d, value at this address is %d.\n", p_number_1, *p_number_1);
    p_number_2 = number_2; //comment
    printf("\nValue of p_number_2 is %d, value at this address is %d.\n", p_number_2, *p_number_2);

    int j;
    puts("\nNum 1 after hex to int:   \n");
    for (j = 0; j < num_of_symbs; j++)
    {
        printf("%d  ", *p_number_1++);
    }
    
    puts("\nNum 2 after hex to int:   \n");
    for (j = 0; j < num_of_symbs; j++)
    {
        printf("%d  ", *p_number_2++);
    }

    // addition_of_two(p_number_1, p_number_2, p_result, num_of_symbs);

    /* puts("\n");
    int j;
    for (j = 0; j < num_of_symbs; j++)
        printf("%d  ", result[j]); */

    /* p_hex_num_1 = hex_num_1;

    int j;
    for (j = 0; j < num_of_symbs; j++)
    {
        printf("\n%c", *p_hex_num_1++);
    } */

  /*   puts("\n");
    int j;
    for (j = 0; j < num_of_symbs; j++)
        printf("%d  ", *p_number_1++);
    
     */
    system("PAUSE");
    return 0;
}