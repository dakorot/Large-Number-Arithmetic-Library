#include <stdio.h>
#include <stdint.h>
#include <math.h>

#define MAX 256

unsigned int* hex_to_int_conversion(char *hex_symbs, unsigned int *dec_symbs, unsigned int length);
char* int_to_hex_conversion(unsigned int *dec_symbs, unsigned int length);
unsigned int* addition_of_two(unsigned int *num1, unsigned int *num2, unsigned int length);
int comparison_of_two(unsigned int *num1, unsigned int *num2, unsigned int length);
unsigned int* subtraction_of_two(unsigned int *num1, unsigned int *num2, unsigned int length);
unsigned int* multiplication_by_digit(unsigned int *num1, unsigned int *num3, unsigned int length);
unsigned int* long_shift_to_high(unsigned int *temp_num, unsigned int i);
unsigned int* multiplication_of_two(unsigned int *num1, unsigned int *num2, unsigned int length);
void division_of_two(unsigned int *num1, unsigned int *num2, unsigned int *res, unsigned int length);
void barrett_reduction(unsigned int *num, unsigned int *module, unsigned int length_of_num, unsigned int length_of_mod);

unsigned int* hex_to_int_conversion(char *hex_symbs, unsigned int *dec_symbs, unsigned int length)
{
    unsigned int iterator_1, iterator_2, *p_dec_symbs;
    p_dec_symbs = dec_symbs;

    for (iterator_1 = 0; iterator_1 < length; iterator_1++)
    {
        *p_dec_symbs = 0;
        for (iterator_2 = 0; iterator_2 < 8; iterator_2++)
        {
            switch (*hex_symbs)
            {
                case '0':
                {
                    *p_dec_symbs += 0 * pow(16, iterator_2);
                    break;                
                }
                case '1':
                {
                    *p_dec_symbs += 1 * pow(16, iterator_2);
                    break;                
                }
                case '2':
                {
                    *p_dec_symbs += 2 * pow(16, iterator_2);
                    break;                
                }
                case '3':
                {
                    *p_dec_symbs += 3 * pow(16, iterator_2);
                    break;                
                }
                case '4':
                {
                    *p_dec_symbs += 4 * pow(16, iterator_2);
                    break;                
                }
                case '5':
                {
                    *p_dec_symbs += 5 * pow(16, iterator_2);
                    break;                
                }
                case '6':
                {
                    *p_dec_symbs += 6 * pow(16, iterator_2);
                    break;                
                }
                case '7':
                {
                    *p_dec_symbs += 7 * pow(16, iterator_2);
                    break;                
                }
                case '8':
                {
                    *p_dec_symbs += 8 * pow(16, iterator_2);
                    break;                
                }
                case '9':
                {
                    *p_dec_symbs += 9 * pow(16, iterator_2);
                    break;                
                }
                case 'a':
                {
                    *p_dec_symbs += 10 * pow(16, iterator_2);
                    break;
                }
                case 'A':
                {
                    *p_dec_symbs += 10 * pow(16, iterator_2);
                    break;                
                }
                case 'b':
                {
                    *p_dec_symbs += 11 * pow(16, iterator_2);
                    break;
                }
                case 'B':
                {
                    *p_dec_symbs += 11 * pow(16, iterator_2);
                    break;                
                }
                case 'c':
                {
                    *p_dec_symbs += 12 * pow(16, iterator_2);
                    break;
                }
                case 'C':
                {
                    *p_dec_symbs += 12 * pow(16, iterator_2);
                    break;                
                }
                case 'd':
                {
                    *p_dec_symbs += 13 * pow(16, iterator_2);
                    break;
                }
                case 'D':
                {
                    *p_dec_symbs += 13 * pow(16, iterator_2);
                    break;                
                }
                case 'e':
                {
                    *p_dec_symbs += 14 * pow(16, iterator_2);
                    break;
                }
                case 'E':
                {
                    *p_dec_symbs += 14 * pow(16, iterator_2);
                    break;                
                }
                case 'f':
                {
                    *p_dec_symbs += 15 * pow(16, iterator_2);
                    break;
                }
                case 'F':
                {
                    *p_dec_symbs += 15 * pow(16, iterator_2);
                    break;                
                }
                default:
                    break;
            }

            hex_symbs--;
        }

        p_dec_symbs++;
    }

    return dec_symbs;
}

char* int_to_hex_conversion(unsigned int *dec_symbs, unsigned int length)
{
    unsigned int iterator_1, iterator_2, remainder;
    static char hex_symbs[MAX+1], *p_hex_symbs;
    p_hex_symbs = hex_symbs;
    
    for (iterator_1 = 0; iterator_1 < length; iterator_1++)
    {
        for (iterator_2 = 0; iterator_2 < 8; iterator_2++)
        {
            remainder = *dec_symbs & 15;
            sprintf(p_hex_symbs, "%X", remainder);
            *dec_symbs = (*dec_symbs) >> 4;
            p_hex_symbs++;
        }
        
        dec_symbs++;
    }

    return hex_symbs;
}

unsigned int* addition_of_two(unsigned int *num1, unsigned int *num2, unsigned int length)
{
    unsigned int iterator, carry = 0;
    unsigned long long int temp;
    static unsigned int res[MAX/8+1], *p_res;
    p_res = res;

    for (iterator = 0; iterator < length; iterator++)
    {
        uint64_t temp = (uint64_t) *num1 + (uint64_t) *num2 + carry;
        *p_res = (uint64_t) temp & 0xffffffff;
        carry = (uint64_t) temp >> 32;
        p_res++;
        num1++;
        num2++;
    }
    *p_res = carry;

    return res;
}

unsigned int* subtraction_of_two(unsigned int *num1, unsigned int *num2, unsigned int length)
{
    unsigned int iterator = 0, borrow = 0;
    int temp;
    static unsigned int res[MAX/8], *p_res;
    p_res = res;

    for (iterator = 0; iterator < length; iterator++)
    {
        temp = *num1 - *num2 - borrow;
        if (temp >= 0)
        {
            *p_res = temp;
            borrow = 0;
        }
        else
        {
            *p_res = 0x100000000 + temp;
            borrow = 1;
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
    for (iterator = length; iterator > 0; iterator--)
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

unsigned int* multiplication_by_digit(unsigned int *num1, unsigned int *digit, unsigned int length)
{
    unsigned int iterator, carry = 0;
    unsigned long long int temp;
    static unsigned int res[MAX/4], *p_res;
    p_res = res;

    for (iterator = 0; iterator < length; iterator++)
    {
        uint64_t temp = (uint64_t) (*num1) * (*digit) + carry;
        *p_res = (uint64_t) temp & 0xffffffff;
        carry = (uint64_t) temp >> 32;
        num1++;
        p_res++;
    }
    *p_res = carry;

    return res;
}

unsigned int* long_shift_to_high(unsigned int *temp_num, unsigned int i)
{
    unsigned int iterator, *p_temp_num;
    p_temp_num = temp_num;

    for (iterator = 0; iterator <= i; iterator++)
    {
        *p_temp_num = 0;
        p_temp_num++;
    }
    
    return p_temp_num;
}

unsigned int* multiplication_of_two(unsigned int *num1, unsigned int *num2, unsigned int length)
{
    unsigned int iterator, temp[MAX/4], *p_temp;
    static unsigned int res[MAX/4], *p_res;
    p_res = res;
    p_temp = temp;

    for (iterator = 0; iterator < MAX/4; iterator++)
    {
        *p_res = 0;
        p_res++;
    }
    p_res = res;

    for (iterator = 0; iterator < length; iterator++)
    {
        p_temp = multiplication_by_digit(num1, num2, length); 
        printf("\nMultiplication by digit #%u:\n", iterator);
        for (unsigned int i = 0; i < MAX/4; i++)
        {
            printf("%u ", *p_temp);
            p_temp++;
        }
        p_temp = temp;
        puts("");

        p_res = addition_of_two(p_temp + iterator, p_res + iterator, MAX/4);
        printf("\nAddition of temp and res #%u:\n", iterator);
        for (unsigned int i = 0; i < MAX/4; i++)
        {
            printf("%u ", *p_temp);
            p_temp++;
        }
        p_temp = temp;
        puts("");

        num2++;
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

