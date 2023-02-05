#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funclab01.h"

#define MAX 256

int main(void)
{
    unsigned int number_1[MAX/8], number_2[MAX], number_3[MAX], result_add[MAX+1], result_sub[MAX], result_mul[MAX*2], *p_number_1, *p_number_2, *p_number_3, *p_result_add, *p_result_sub, *p_result_mul;
    char hex_num_3[MAX], hex_result_add[MAX+1], hex_result_sub[MAX], hex_result_mul[MAX*2], *p_hex_num_1, *p_hex_num_2, *p_hex_num_3, *p_hex_result_add, *p_hex_result_sub, *p_hex_result_mul;
    p_hex_num_3 = hex_num_3;
    p_number_1 = number_1;
    p_number_2 = number_2;
    p_number_3 = number_3;
    p_result_add = result_add;
    p_result_sub = result_sub;
    p_result_mul = result_mul;
  
    char hex_num_1[MAX] = "D4D2110984907B5625309D956521BAB4157B8B1ECE04043249A3D379AC112E5B9AF44E721E148D88A942744CF56A06B92D28A0DB950FE4CED2B41A0BD38BCE7D0BE1055CF5DE38F2A588C2C9A79A75011058C320A7B661C6CE1C36C7D870758307E5D2CF07D9B6E8D529779B6B2910DD17B6766A7EFEE215A98CAC300F2827DB";
    p_hex_num_1 = hex_num_1 + MAX - 1;
    char hex_num_2[MAX] = "3A7EF2554E8940FA9B93B2A5E822CC7BB262F4A14159E4318CAE3ABF5AEB1022EC6D01DEFAB48B528868679D649B445A753684C13F6C3ADBAB059D635A2882090FC166EA9F0AAACD16A062149E4A0952F7FAAB14A0E9D3CB0BE9200DBD3B0342496421826919148E617AF1DB66978B1FCD28F8408506B79979CCBCC7F7E5FDE7";
    p_hex_num_2 = hex_num_2 + MAX - 1;

    clock_t start, end;
    double execution_time;
    start = clock();
    p_number_1 = hex_to_int_conversion(p_hex_num_1, MAX/8);
    puts("");
    for (int i = 0; i < MAX/8; i++)
    {
        printf("%u ", *p_number_1++);
    }
    //hex_to_int_conversion(p_hex_num_2, p_number_2, MAX);


    end = clock();
    execution_time = ((double)(end - start))/CLOCKS_PER_SEC;
    printf("\nExecution time: %f s.\n", execution_time);
    system("PAUSE");
    return 0;
}