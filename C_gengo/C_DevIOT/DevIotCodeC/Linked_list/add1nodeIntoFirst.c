#include <stdio.h>
#include <stdlib.h>

// Định nghĩa cấu trúc của một node trong danh sách liên kết
typedef struct node {
    int data;
    struct node* next;
} node_t;

// Khởi tạo một node mới
node_t* createNode(int val) {
    node_t *temp = (node_t*)malloc(sizeof(node_t));
    if (temp == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    temp->data = val;
    temp->next = NULL;
    return temp;
}

// Thêm một node vào đầu danh sách liên kết
void pushHead(node_t **head, int val) {
    node_t *new_node = createNode(val);
    if(*head == NULL){
        *head = new_node;
    }
    else{
        new_node->next = *head;
        *head = new_node;
    }
}
// Hàm in danh sách liên kết
void printList(node_t* head) {
    node_t* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    node_t* head = NULL; // Ban đầu danh sách rỗng

    pushHead(&head, 3);
    pushHead(&head, 5);
    pushHead(&head, 7);

    printList(head); // In danh sách: 7 -> 5 -> 3 -> NULL

    return 0;
}
