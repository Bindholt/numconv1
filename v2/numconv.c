#include <stdio.h>
#include "numconv.h"

void int_to_bin(int num, char str[]) {
    int position = 0;
    int bits = sizeof(int) * 8; 

    for (int i = bits - 1; i >= 0; i--) {
        str[position++] = (num & (1 << i)) ? '1' : '0';  
    }

    str[position] = '\0';  
}

void int_to_hex(int num, char str[]) {
    int position = 0;
    int bits = sizeof(int) * 8; 
    const char hex_digits[] = "0123456789ABCDEF";

    for (int i = bits - 4; i >= 0; i -= 4) {
        int digit = (num >> i) & 0xF;
        str[position++] = hex_digits[digit];
    }

    str[position] = '\0';  
}

void int_to_oct(int num, char str[]) {
    int position = 0;
    int bits = sizeof(int) * 8; 

    for (int i = bits - 3; i >= 0; i -= 3) {
        int digit = (num >> i) & 0x7;
        str[position++] = '0' + digit;
    }

    str[position] = '\0';  
}


void int_to_dec(int num, char str[]) {
    int position = 0;
    int is_negative = 0;

    if (num < 0) {
        is_negative = 1;
        num = -num;
    }

    do {
        str[position++] = '0' + num % 10;
        num /= 10;
    } while (num > 0);

    if (is_negative) {
        str[position++] = '-';
    }

    str[position] = '\0';
    reverse_string(str);
}


int is_digit(int digit) {
    return digit >= '0' && digit <= '9';
}

int is_hex_digit(int digit) {
    return (digit >= '0' && digit <= '9') || (digit >= 'A' && digit <= 'F');
}

int is_bin_digit(int digit) {
    return digit == '0' || digit == '1';
}

int is_oct_digit(int digit) {
    return digit >= '0' && digit <= '7';
}

int bin_to_int(char str[]) {
    int result = 0;
    int position = 0;

    while (str[position] != '\0') {
        if (!is_bin_digit(str[position])) {
            return -1;
        }

        result = result * 2 + (str[position] - '0');
        position++;
    }

    return result;
}

int hex_to_int(char str[]) {
    int result = 0;
    int position = 0;

    while (str[position] != '\0') {
        if (!is_hex_digit(str[position])) {
            return -1;
        }

        result = result * 16;
        if (is_digit(str[position])) {
            result += str[position] - '0';
        } else {
            result += str[position] - 'A' + 10;
        }

        position++;
    }

    return result;
}

int oct_to_int(char str[]) {
    int result = 0;
    int position = 0;

    while (str[position] != '\0') {
        if (!is_oct_digit(str[position])) {
            return -1;
        }

        result = result * 8 + (str[position] - '0');
        position++;
    }

    return result;
}

int dec_to_int(char str[]) {
    int result = 0;
    int position = 0;
    int is_negative = 0;

    if (str[position] == '-') {
        is_negative = 1;
        position++;
    }

    while (str[position] != '\0') {
        if (!is_digit(str[position])) {
            return -1;
        }

        result = result * 10 + (str[position] - '0');
        position++;
    }

    if (is_negative) {
        result = -result;
    }

    return result;
}


void reverse_string(char str[]) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }

    for (int i = 0; i < length / 2; i++) {
        char temp = str[i];
        str[i] = str[length - 1 - i];
        str[length - 1 - i] = temp;
    }
}

