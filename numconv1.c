#include <stdio.h>
#include "numconv1.h"

int dec_to_int(char str[]) {
    int value = 0;
    int position = 0;

    int is_negative = 0;
    if(str[0] == '-') {
        is_negative = 1;
        position++;
    }

    while(str[position] != '\0' && is_digit(str[position]) == 1)
    {
        value *= 10;
        int digit = str[position++] - '0';
        value += digit;
    }

    if(is_negative) value = -value;

    return value;
}

int bin_to_int(char str[]) {
    int value = 0;
    int position = 0;

    while(str[position] != '\0' && is_bin_digit(str[position]) == 1)
    {
        value *= 2;
        int digit = str[position++] - '0';
        value += digit;
    }

    return value;
}

int hex_to_int(char str[]) {
    int value = 0;
    int position = 0;

    while(str[position] != '\0' && is_hex_digit(str[position]) == 1)
    {
        value *= 16;
        int digit = str[position++] - '0';
        if (digit >= 17 && digit <= 22) digit -= 7;
        value += digit;
    }

    return value;
}

int oct_to_int(char str[]) {
    int value = 0;
    int position = 0;

    while(str[position] != '\0' && is_oct_digit(str[position]) == 1)
    {
        value *= 8;
        int digit = str[position++] - '0';
        value += digit;
    }

    return value;
}

void int_to_dec(int num, char str[]) {
    int remain = num;
    int position = 0;
    if(remain < 0) {
        str[position++] = '-';
        remain = -remain;
    }

    do 
    {
        str[position++] = '0' + remain%10;
        remain /= 10;
    } while (remain > 0);
    str[position] = '\0';       
}   

void int_to_bin(int num, char str[]) {
    int remain = num;
    int position = 0;

    do 
    {
        str[position++] = '0' + remain%2;
        remain /= 2;
    } while (remain > 0);
    str[position] = '\0';       
}

void int_to_hex(int num, char str[]) {
    const char hex_digits[] = "0123456789ABCDEF";
    char temp[9]; 
    int position = 0;
    unsigned int unum = (unsigned int)num; 

    do {
        temp[position++] = hex_digits[unum % 16];
        unum /= 16;
    } while (unum > 0);

    for (int i = 0; i < position; i++) {
        str[i] = temp[position - 1 - i];
    }

    str[position] = '\0';
}



void int_to_oct(int num, char str[]) {
    char temp[12];
    int position = 0;
    unsigned int unum = (unsigned int)num;

    do 
    {
        temp[position++] = '0' + unum%8;
        unum /= 8;
    } while (unum > 0); 
    
    for (int i = 0; i < position; i++) {
        str[i] = temp[position - 1 - i];
    }  

    
    str[position] = '\0';
}

int is_digit(int digit) {
    int is_digit = 0;

    if (digit >= 48 && digit <= 57) is_digit = 1;

    return is_digit;
}

int is_bin_digit(int digit) {
    int is_digit = 0;

    if (digit >= 48 && digit <= 49) is_digit = 1;

    return is_digit;
}

int is_hex_digit(int digit) {
    int is_digit = 0;

    if (digit >= 48 && digit <= 57) is_digit = 1;
    if (digit >= 65 && digit <= 70) is_digit = 1;
    if (digit >= 97 && digit <= 102) is_digit = 1;

    return is_digit;
}

int is_oct_digit(int digit) {
    int is_digit = 0;

    if (digit >= 48 && digit <= 55) is_digit = 1;

    return is_digit;
}