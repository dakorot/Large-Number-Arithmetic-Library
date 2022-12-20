#include <stdio.h>

void hex_to_int_conversion(char *hex_symbs, unsigned int *dec_symbs, unsigned int length);
void addition_of_two(unsigned int *num1, unsigned int *num2, unsigned int *res, unsigned int length);

void hex_to_int_conversion(char *hex_symbs, unsigned int *dec_symbs, unsigned int length)
{
    unsigned int i;

    for (i = 0; i < length; i++)
    {
        switch (*hex_symbs)
        {
            case '0':
            {
                *dec_symbs = 0;
                break;                
            }
            case '1':
            {
                *dec_symbs = 1;
                break;                
            }
            case '2':
            {
                *dec_symbs = 2;
                break;                
            }
            case '3':
            {
                *dec_symbs = 3;
                break;                
            }
            case '4':
            {
                *dec_symbs = 4;
                break;                
            }
            case '5':
            {
                *dec_symbs = 5;
                break;                
            }
            case '6':
            {
                *dec_symbs = 6;
                break;                
            }
            case '7':
            {
                *dec_symbs = 7;
                break;                
            }
            case '8':
            {
                *dec_symbs = 8;
                break;                
            }
            case '9':
            {
                *dec_symbs = 9;
                break;                
            }
            case 'a':
            {
                *dec_symbs = 10;
                break;
            }
            case 'A':
            {
                *dec_symbs = 10;
                break;                
            }
            case 'b':
            {
                *dec_symbs = 11;
                break;
            }
            case 'B':
            {
                *dec_symbs = 11;
                break;                
            }
            case 'c':
            {
                *dec_symbs = 12;
                break;
            }
            case 'C':
            {
                *dec_symbs = 12;
                break;                
            }
            case 'd':
            {
                *dec_symbs = 13;
                break;
            }
            case 'D':
            {
                *dec_symbs = 13;
                break;                
            }
            case 'e':
            {
                *dec_symbs = 14;
                break;
            }
            case 'E':
            {
                *dec_symbs = 14;
                break;                
            }
            case 'f':
            {
                *dec_symbs = 15;
                break;
            }
            case 'F':
            {
                *dec_symbs = 15;
                break;                
            }
        }

        hex_symbs--;
        dec_symbs++;
    }
}

void addition_of_two(unsigned int *num1, unsigned int *num2, unsigned int *res, unsigned int length)
{
    unsigned int iterator = 0, carry = 0;
    for (iterator = 0; iterator < length; iterator++)
    {
        if (iterator >= length)
        {
            *res = carry;
            break;
        }
        else
        {
            *res = (*num1 + *num2 + carry) % 16;
            carry = ((*num1 + *num2 + carry) >= 16);
        }
        num1++;
        num2++;
        res++;
    }
}