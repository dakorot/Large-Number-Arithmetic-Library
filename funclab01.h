#include <stdio.h>
#include <math.h>

#define MAX 256

void hex_to_int_conversion(char *hex_symbs, unsigned int *dec_symbs, unsigned int length);
void int_to_hex_conversion(unsigned int *dec_symbs, char *hex_symbs, unsigned int length);
unsigned int* addition_of_two(unsigned int *num1, unsigned int *num2, unsigned int length);
int comparison_of_two(unsigned int *num1, unsigned int *num2, unsigned int length);
unsigned int* subtraction_of_two(unsigned int *num1, unsigned int *num2, unsigned int length);
unsigned int* multiplication_by_digit(unsigned int *num1, int *num3, unsigned int length);
unsigned int* multiplication_of_two(unsigned int *num1, unsigned int *num2, unsigned int length);
void division_of_two(unsigned int *num1, unsigned int *num2, unsigned int *res, unsigned int length);
void barrett_reduction(unsigned int *num, unsigned int *module, unsigned int length_of_num, unsigned int length_of_mod);

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

unsigned int* addition_of_two(unsigned int *num1, unsigned int *num2, unsigned int length)
{
    unsigned int iterator = 0, carry = 0;
    static unsigned int res[MAX], *p_res;
    p_res = res;

    for (iterator = 0; iterator < (length + 1); iterator++)
    {
        if (iterator == length)
        {
            *p_res = carry;
            break;
        }
        else
        {
            *p_res = (*num1 + *num2 + carry) % 16;
            carry = ((*num1 + *num2 + carry) >= 16); 
        }

        num1++;
        num2++;
        p_res++;
    }

    return res;
}

unsigned int* subtraction_of_two(unsigned int *num1, unsigned int *num2, unsigned int length)
{
    unsigned int iterator = 0;
    static unsigned int res[MAX], *p_res;
    p_res = res;
    int borrow = 0, temp;

    for (iterator = 0; iterator < length; iterator++)
    {
        if (iterator == length)
        {
            //*p_res = temp; 
            break;
        }  
                
        else
        {
            temp = (*num1 - *num2 - borrow);
            if (temp >= 0)
            {
               *p_res = temp;
               borrow = 0;

            }
            else
            {
                *p_res = temp + 16;
                borrow = 1;
            }
        }
        num1++;
        num2++;
        p_res++;
    }

    return res;
}

int comparison_of_two(unsigned int *num1, unsigned int *num2, unsigned int length)
{
    unsigned int iterator;
    for (iterator = length; iterator > 0; iterator++)
    {
        if (iterator == -1) //numbers are equal
            return 0;
        else if (*num1 > *num2)
            return 1;
        else
            return -1;

        iterator--;
        num1--;
        num2--;
    }
}

unsigned int* multiplication_by_digit(unsigned int *num1, int *digit, unsigned int length)
{
    unsigned int iterator, carry = 0, temp;
    static unsigned int res[MAX*2], *p_res;
    p_res = res;
    for (iterator = 0; iterator < length; iterator++)
    {
        if (iterator == length)
        {
            *p_res = carry;
            break;
        }
        else
        {
        temp = (*num1) * (*digit) + carry;
        *p_res = temp % 16;
        printf("\n*p_res = %u", *p_res);
        carry = temp / 16;
        printf("\ncarry = %u", carry);

        num1++;
        p_res++;
        }

        return res;
    }

}

unsigned int* multiplication_of_two(unsigned int *num1, unsigned int *num2, unsigned int length)
{
    unsigned int iterator_1, iterator_2, temp, *p_num1, *p_num2;
    static unsigned int res[MAX*2], *p_res;
    p_res = res;

    for (iterator_1 = 0; iterator_1 < length*2; iterator_1++)
    {
        *p_res = 0;
        p_res++;
    }
    p_res = res;

    for (iterator_2 = 0; iterator_2 < length; iterator_2++)
    {
        for (iterator_1 = 0; iterator_1 < length; iterator_1++)
        {
            p_res = res + iterator_1 + iterator_2;
            p_num1 = num1 + iterator_1;
            p_num2 = num2 + iterator_2;
            *p_res = *p_res + (*p_num1) * (*p_num2);
        }
        
        p_res = res;
        for (iterator_1 = 0; iterator_1 < length*2; iterator_1++)
        {
            temp = *p_res / 16;
            *p_res = *p_res % 16;
            p_res = p_res + 1;
            *p_res = *p_res + temp;
        }
    }

    return res;
}

void division_of_two(unsigned int *num1, unsigned int *num2, unsigned int *res, unsigned int length)
{   
    unsigned int iterator_1, iterator_2, iterator_3, remainder[MAX], *p_remainder, quotient[MAX], *p_quotient, temp, remainder_length, b_length;
    p_remainder = remainder;
    for (iterator_1 = 0; iterator_1 < length; iterator_1++) // remainder = A (num1)
    {   *p_remainder = *num1;
        p_remainder++;
        num1++;
    }
    remainder_length = length;
    p_quotient = quotient;
    *p_quotient = 0;

    for (iterator_1 = 0; iterator_1 < length; iterator_1++)
    {
        if ((remainder_length = length && (comparison_of_two(p_remainder, num2, length) == 0 || comparison_of_two(p_remainder, num2, length) == 1)) || remainder_length > length)
        {
            temp = remainder_length;
            b_length = length - (temp - b_length);
            for (iterator_2 = 0; iterator_2 < b_length; iterator_2++) // shift of B (num2) to the left for (temp - length) positions
            {
                *res = *num2;
                res++;
                num2++;
            }
            res -= length;
            num2 -= length;

            if ((remainder_length = length && comparison_of_two(p_remainder, num2, length) == -1) || remainder_length > length )
            {
                temp = temp - 1;
                b_length = length - (temp - b_length);
                for (iterator_2 = 0; iterator_2 < b_length; iterator_2++) // shift of B (num2) to the left for (temp - length) positions
                {
                    *res = *num2;
                    res++;
                    num2++;
                }
            }

            //subtraction_of_two(p_remainder, res, p_remainder, remainder_length);
            *p_quotient = *p_quotient; //insert a bit - ?
        }
    }


}

void barrett_reduction(unsigned int *num, unsigned int *module, unsigned int length_of_num, unsigned int length_of_mod)
{
    unsigned int iterator, q, meow = 1, beta_power, *p_len_of_mod;
    //pre-calculation: 
    beta_power = (2*length_of_mod);
    meow = floor((pow(16, beta_power))/(*module));
    printf("\npow() meow = %u", meow);

    
}