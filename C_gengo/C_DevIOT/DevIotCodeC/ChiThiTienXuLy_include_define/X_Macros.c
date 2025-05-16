/*
X-Marcros là một phương pháp sử dụng #define để tạo danh sách các macro có thể mở rộng và tái sử dụng 
trong nhiều ngữ cảnh khác nhau.
Ưu điểm:
    1. Dễ bảo trì: Chỉ cần sửa đổi một danh sách duy nhất, tất cả các phần còn lại sẽ tự động cập nhật.
    2. Hạn chế lỗi: Tránh việc quên cập nhật các switch-case hoặc bảng ánh xạ.
    3. Tái sử dụng dễ dàng: Dùng một danh sách cho nhiều mục đích khác nhau.

Nhược điểm:
    1. Khó hiểu với người mới khi chưa quen các macro
    2. Không thể debug dễ dàng vì mã được mở rộng bởi prrprocessor
    3. Không linh hoạt với dữ liệu phức tạp: Khó quản lý hơn struct khi có nhiều trường dữ liệu.
*/

#define COMMAND_LIST \
    X(CMD_START, 1, "Start Command") \ 
    X(CMD_STOP,  2, "Stop Command" ) \
    X(CMD_RESET, 3, "Reset Command") 

//Create Enum
typedef enum{
    #define X(name, id, desc) name = id,
    COMMAND_LIST
    #undef X
} CommandID;

//Create an array containing the description of each command
const char *command_desc[] = {
    #define X(name, id, desc) [id] = desc,
    COMMAND_LIST
    #undef X
};

//Function to print command information
#include<stdio.h>

void print_command_info(CommandID cmd){
    printf("Command %d: %s\n", cmd, command_desc[cmd]);
}

int main(){
    print_command_info(CMD_START);
    print_command_info(CMD_STOP);

    return 0;
}