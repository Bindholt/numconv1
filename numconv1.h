#ifndef NUMCONV1_H
#define NUMCONV1_H

    int dec_to_int(char str[]);
    int is_digit(int digit);
    int bin_to_int(char str[]);
    int hex_to_int(char str[]);
    int oct_to_int(char str[]);
    void int_to_dec(int num, char str[]);
    void int_to_bin(int num, char str[]);
    void int_to_hex(int num, char str[]);
    void int_to_oct(int num, char str[]);
    int is_digit(int digit);
    int is_bin_digit(int digit);
    int is_hex_digit(int digit);
    int is_oct_digit(int digit);

#endif