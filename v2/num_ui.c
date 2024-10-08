#include <stdio.h>
#include "numconv.h"
#include "num_ui.h"

int main()
{
    char from_choice = ' ';
    char to_choice = ' ';

    while(from_choice != '0' && to_choice != '0') {
        print_menu();
        from_choice = get_choice("Choose what to convert from: ");
        if(from_choice == '0') {
            printf("Goodbye!\n");
            break;
        }
        to_choice = get_choice("Choose what to convert to: ");
        if(from_choice == '0') {
            printf("Goodbye!\n");
            break;
        }
        char value[100] = "";
        int value_int = get_value_in_int(from_choice, value);
        char value_str[100] = "";
        convert_int_to_string(to_choice, value_int, value_str);
        print_result(to_choice, value_str);
    }
    return 0;
}

void print_menu() {
    printf("Choose from which base you want to convert:\n");
    printf("1. Decimal\n");
    printf("2. Binary\n");
    printf("3. Hexadecimal\n");
    printf("4. Octal\n");
    printf("0. Exit\n");
    printf("Enter your choice: ");
}

char get_choice(char* msg) {
    char choice = ' ';
    printf("%s", msg);
    scanf(" %c", &choice);
    return choice;
}

int get_value_in_int(char from_choice, char value[]) {
    printf("Enter the value you want to convert: ");
    scanf("%s", value);
    int value_int = 0;
    switch(from_choice) {
        case '1':
            value_int = dec_to_int(value);
            break;
        case '2':
            value_int = bin_to_int(value);
            break;
        case '3':
            value_int = hex_to_int(value);
            break;
        case '4':
            value_int = oct_to_int(value);
            break;
        default:
            printf("Invalid choice\n");
            break;
    }
    return value_int;
}

void convert_int_to_string(char to_choice, int value_int, char value_str[]) {
    switch(to_choice) {
        case '1':
            int_to_dec(value_int, value_str);
            break;
        case '2':
            int_to_bin(value_int, value_str);
            break;
        case '3':
            int_to_hex(value_int, value_str);
            break;
        case '4':
            int_to_oct(value_int, value_str);
            break;
        default:
            printf("Invalid choice\n");
            break;
    }
}

void print_result(char to_choice, char *value_str) {
    printf("====================================\n");
    switch(to_choice) {
        case '1':
            printf("The value in decimal is: %s\n", value_str);
            break;
        case '2':
            printf("The value in binary is: %s\n", value_str);
            break;
        case '3':
            printf("The value in hexadecimal is: %s\n", value_str);
            break;
        case '4':
            printf("The value in octal is: %s\n", value_str);
            break;
        default:
            printf("Invalid choice\n");
            break;
    }
    printf("====================================\n");
}

