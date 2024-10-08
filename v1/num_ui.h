#ifndef NUM_UI_H
#define NUM_UI_H

    void print_menu();
    char get_choice(char* msg);
    int get_value_in_int(char from_choice, char value[]);
    void convert_int_to_string(char to_choice, int value_int, char value_str[]);
    void print_result(char to_choice, char *value_str);
#endif