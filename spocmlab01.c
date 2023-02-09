#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funclab01.h"

#define MAX 256

int main(void)
{
    unsigned int number_1[MAX/8], number_2[MAX], number_3[MAX], result_add[MAX+1], result_sub[MAX], result_mul[MAX*2], *p_number_1, *p_number_2, *p_number_3, *p_result_add, *p_result_sub, *p_result_mul;
    char hex_num_3[MAX+1], hex_result_add[MAX+1], hex_result_sub[MAX], hex_result_mul[MAX*2], *p_hex_num_1, *p_hex_num_2, *p_hex_num_3, *p_hex_result_add, *p_hex_result_sub, *p_hex_result_mul;
    p_hex_num_3 = hex_num_3;
    p_number_1 = number_1;
    p_number_2 = number_2;
    p_number_3 = number_3;
    p_result_add = result_add;
    p_result_sub = result_sub;
    p_result_mul = result_mul;
    p_hex_result_add = hex_result_add;
  
    char hex_num_1[MAX] = "87D6D58D3991D536544389CEFA72FD0EBED75B2EBDC2C79BC3717793108F0952011E7E2D7040FFFB32F10BEB8ED0A485026B6860020B230128A8222B0525A6888942FB01C537800BF25D6F021D4B99D3CBD6DF9055FA22F91A6CFC4FDFC408AEF78F6418D3CE4E20EC7888B61BAE3D73C27C257CCA905DE0353C3A7CFFD9FE15";
    p_hex_num_1 = hex_num_1 + MAX - 1;
    char hex_num_2[MAX] = "791EDB102DA183759979CEF70E1405AF14B98CD44357EADF6A8E35E49F99BB56CBD3F68897D6E05502ED1DE14EC46D04F96992C2D129737987E84E62371648B37633794016852A8CBFFCFDE06B17EC216AE8914D59E677A15A90361A594F0D1524A41AE63C59D343D4E522646722B0292DD7C85571AC9A84FDA6CD2D8DE307F6";
    p_hex_num_2 = hex_num_2 + MAX - 1;

    clock_t start, end;
    double execution_time;
    start = clock();

    //Step 1: conversion
    p_number_1 = hex_to_int_conversion(p_hex_num_1, number_1, MAX/8);
    p_number_2 = hex_to_int_conversion(p_hex_num_2, number_2, MAX/8);
    printf("\np_number_1 after conversion: %u", p_number_1);
    printf("\np_number_2 after conversion: %u\n", p_number_2);

    int i;
    for(i = 0; i < MAX/8; i++)
        printf("%u ", *p_number_1++);
    puts("\n");
    for(i = 0; i < MAX/8; i++)
        printf("%u ", *p_number_2++);

    //Step 2: addition
    p_number_1 = number_1;
    p_number_2 = number_2;
    unsigned int *temp;
    temp = addition_of_two(p_number_1, p_number_2, MAX/8);
    p_result_add = temp;
    puts("");
    for (int i = 0; i < MAX; i++)
    {
        printf("%c", *p_result_add++);
    }
    p_result_add = temp;
    p_hex_result_add = int_to_hex_conversion(p_result_add, hex_result_add, MAX/8);

    //Step 3: Output
    puts("");
    for (int i = 0; i < MAX; i++)
    {
        printf("%c", *p_hex_result_add++);
    }

    end = clock();
    execution_time = ((double)(end - start))/CLOCKS_PER_SEC;
    printf("\nExecution time: %f s.\n", execution_time);
    system("PAUSE");
    return 0;
}