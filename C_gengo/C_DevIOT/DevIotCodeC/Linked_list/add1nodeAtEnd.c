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

//function push node at anywhere
void pushNodeAt(node_t **head, int val, int pos){
    if (*head == NULL && pos != 1){
        printf("Invalid position!\n");
        return;
    }

    if(pos == 1){
        node_t *new_node = createNode(val);
        new_node->next = *head;
        *head = new_node;
        return;
    }

    int k = 1;
    node_t *pt = *head;
    while(pt != NULL && k < pos-1){
        pt = pt->next;
        k++;
    } 

    if(pt == NULL){
        printf("Invalid position!\n");
        return;
    }

    node_t *new_node = createNode(val);
    new_node->next = pt->next;
    pt->next = new_node;
}


// Thêm một node vào cuối danh sách liên kết
void pushNodeEnd(node_t **head, int val){

    node_t *new_node = createNode(val);

    if(*head == NULL){
        *head = new_node;
        return; //stop function immediately
    }
    //if not use "return;" program will continue going to
    node_t *pt = *head;
    
    while(pt->next != NULL){
        pt = pt->next;
    }
    pt->next = new_node;
}
//function delete the first node
void deleteFirst(node_t **head){
    //to do
    if(*head == NULL){
        printf("List is already empty!\n");
        return;
    }
    node_t *new_head = (*head)->next;
    free(*head);
    *head = new_head;
}

//function detele node at anywhere
void deleteAt(node_t **head, int pos){
    //to do
    if(*head == NULL){
        printf("List is empty!\n");
        return;
    }
    if(pos == 0){
        printf("position invalid!\nchoice again, please!\n");
        return;
    }
    if(pos == 1){
        deleteFirst(head);
        return;
    }

    int k = 1;
    node_t *temp = *head;
    while(temp != NULL && k < pos - 1){
        temp = temp->next;
        k++;
    }

    if(temp == NULL || temp->next == NULL)
    {
        printf("invalid position!\n");
        return;
    }
   
    node_t *tempToDel = temp->next;
    temp->next = temp->next->next;
    free(tempToDel);
}

//function delete the end node
void deleteEnd(node_t **head){
    //to do
    node_t *temp = *head;
    while(temp->next->next != NULL){
        temp = temp->next; 
    }
    free(temp->next);
    temp->next =NULL;
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

//function free memory to avoid leaking 
void freeList(node_t **head){
    node_t *temp;
    while(*head != NULL){
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }
    *head = NULL;
    //make sure "head" pointer no longer points to invalid memory
}

int main() {
    node_t* head = NULL; // Ban đầu danh sách rỗng

    pushNodeEnd(&head, 1);
    pushNodeEnd(&head, 2);
    pushNodeEnd(&head, 3);
    pushNodeEnd(&head, 4);
    pushNodeEnd(&head, 5);
    pushNodeEnd(&head, 6);
    deleteAt(&head, 0);
    printList(head); 
    
    freeList(&head); //FREE MEMORY AVOID LEAKING;
    
    return 0;
}
