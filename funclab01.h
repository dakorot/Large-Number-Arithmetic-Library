#include <stdio.h>
#include <math.h>

void hex_to_int_conversion(char *hex_symbs, unsigned int *dec_symbs, unsigned int length);
void int_to_hex_conversion(unsigned int *dec_symbs, char *hex_symbs, unsigned int length);
void addition_of_two(unsigned int *num1, unsigned int *num2, unsigned int *res, unsigned int length);
int comparison_of_two(unsigned int *num1, unsigned int *num2, unsigned int length);
void subtraction_of_two(unsigned int *num1, unsigned int *num2, unsigned int *res, unsigned int length);

void hex_to_int_conversion(char *hex_symbs, unsigned int *dec_symbs, unsigned int length)
{
    unsigned int iterator;

    for (iterator = 0; iterator < length; iterator++)
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
            default:
                break;
        }

        hex_symbs--;
        dec_symbs++;
    }
}

void int_to_hex_conversion(unsigned int *dec_symbs, char *hex_symbs, unsigned int length)
{
    unsigned int iterator;
    
    for (iterator = 0; iterator < (length + 1); iterator++)
    {
        if ((iterator == length) && (*dec_symbs == 0))
            break;
        switch (*dec_symbs)
        {
            case 0:
            {
                *hex_symbs = '0';
                break;                
            }
            case 1:
            {
                *hex_symbs = '1';
                break;                
            }
            case 2:
            {
                *hex_symbs = '2';
                break;                
            }
            case 3:
            {
                *hex_symbs = '3';
                break;                
            }
            case 4:
            {
                *hex_symbs = '4';
                break;                
            }
            case 5:
            {
                *hex_symbs = '5';
                break;                
            }
            case 6:
            {
                *hex_symbs = '6';
                break;                
            }
            case 7:
            {
                *hex_symbs = '7';
                break;                
            }
            case 8:
            {
                *hex_symbs = '8';
                break;                
            }
            case 9:
            {
                *hex_symbs = '9';
                break;                
            }
            case 10:
            {
                *hex_symbs = 'A';
                break;
            }
            case 11:
            {
                *hex_symbs = 'B';
                break;
            }
            case 12:
            {
                *hex_symbs = 'C';
                break;
            }
            case 13:
            {
                *hex_symbs = 'D';
                break;
            }
            case 14:
            {
                *hex_symbs = 'E';
                break;
            }
            case 15:
            {
                *hex_symbs = 'F';
                break;
            }
            default:
                break;
        }

        dec_symbs++;
        hex_symbs--;
    }
}

void addition_of_two(unsigned int *num1, unsigned int *num2, unsigned int *res, unsigned int length)
{
    unsigned int iterator = 0, carry = 0;
    for (iterator = 0; iterator < (length + 1); iterator++)
    {
        if (iterator == length)
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

void subtraction_of_two(unsigned int *num1, unsigned int *num2, unsigned int *res, unsigned int length)
{
    unsigned int iterator = 0;
    int borrow = 0, temp;
    for (iterator = 0; iterator < length; iterator++)
    {
        if (iterator == length)      
                break;
        else
        {
            temp = (*num1 - *num2 - borrow);
            if (temp >= 0)
            {
               *res = temp;
               borrow = 0;

            }
            else
            {
                *res = temp + 16;
                borrow = 1;
            }
        }
        num1++;
        num2++;
        res++;
    }
}

int comparison_of_two(unsigned int *num1, unsigned int *num2, unsigned int length)
{
    unsigned int iterator = length - 1;
    while (*num1 == *num2)
    {
        iterator = iterator--;

        if (iterator == -1) //numbers are equal
            return 0;
        else if (*num1 > *num2)
            return 1;
        else
            return -1;
    }
}