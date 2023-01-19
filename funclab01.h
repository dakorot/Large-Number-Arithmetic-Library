#include <stdio.h>
#include <math.h>

#define MAX_int 1024
#define MAX_char 512

void hex_to_int_conversion(char *hex_symbs, unsigned int *dec_symbs, unsigned int length);
void int_to_hex_conversion(unsigned int *dec_symbs, char *hex_symbs, unsigned int length);
void addition_of_two(unsigned int *num1, unsigned int *num2, unsigned int *res, unsigned int length);
int comparison_of_two(unsigned int *num1, unsigned int *num2, unsigned int length);
void subtraction_of_two(unsigned int *num1, unsigned int *num2, unsigned int *res, unsigned int length);
void multiplication_by_digit(unsigned int *num1, int *num3, unsigned int *res, unsigned int length);
void multiplication_of_two(unsigned int *num1, unsigned int *num2, unsigned int *res, unsigned int length);

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

void multiplication_by_digit(unsigned int *num1, int *digit, unsigned int *res, unsigned int length)
{
    unsigned int iterator, carry = 0, temp;
    for (iterator = 0; iterator < length; iterator++)
    {
        if (iterator == length)
        {
            *res = carry;
            break;
        }
        else
        {
        temp = (*num1) * (*digit) + carry;
        printf("\n#%u: temp = %u * %u + %u = %u", iterator, *num1, *digit, carry, temp);
        *res = temp % 16;
        printf("\n#%u: *res = %u %% 16 = %u", iterator, temp, *res);
        carry = temp / 16;
        printf("\n#%u: carry = %u / 16 = %u", iterator, temp, carry);

        printf ("\nBy digit #%u: %u", iterator, *res);

        num1++;
        res++;
        }
    }
}

void multiplication_of_two(unsigned int *num1, unsigned int *num2, unsigned int *res, unsigned int length)
{
    unsigned int iterator, temp[MAX_int*2], *p_temp, carry = 0, *p_res_orig, *p_res_temp, *p_num1, *p_num2;
    p_temp = temp;
    p_res_orig = res;
    p_res_temp = res;
    p_num1 = num1;
    p_num2 = num2;

    for (iterator = 0; iterator < (length + 1); iterator++) //let every digital of the resulting number be zero for further addition of sub-results
    {
        *p_res_orig = 0;
        p_res_orig++;
    }
    
    p_res_orig = res;

    for (iterator = 0; iterator < length; iterator++)
    {
        multiplication_by_digit(p_num1, p_num2, p_temp, length);

        p_temp = temp;
        printf("\nResult of multiplication by digit #%u: ", iterator);
        for (int i = 0; i < (length + 1); i++)
            printf("%u", *p_temp++);

        p_temp = temp;

        addition_of_two(p_temp, p_res_temp, p_res_orig, length);

        p_temp = temp; 
        p_res_orig = res;
        p_res_temp = res + iterator + 1;
        p_num1 = num1;
        p_num2 = num2 + iterator + 1;                 
    }
       
}

/*
i = 0, carry = 0;
for (i = 0; i < length; i++)
{
     if ((*num1 == 0) || (*num2 == 0))
    {
        *res = 0;
        continue;
    }
    else
    {
        temp = (*num1) * (*num2) + carry;
        *res = temp % 16;
        carry = floor(temp / 16);
    }
    num1++;
    num2++;
    res++;
    }
}
*/