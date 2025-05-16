/*
Variadic Function là một hàm mà có truyền vào đa dạng biến mà không bị cố định số lượng biến truyền vào.
How to use: declare library "stdarg.h"
Main method:
    va_list: include information related to va_start, va_arg, va_end.
    va_start, va_end: use to start and end process take paras in list input.
    va_arg: present for paras added in ...
syntax: 
int functionName(data_type variable_name, ...){
    
    int var_need_do;

    va_list var_input;
    
    va_start (var_input, variable_name);

    //to do

    va_end var_input;

    return var_need_do;
}
*/