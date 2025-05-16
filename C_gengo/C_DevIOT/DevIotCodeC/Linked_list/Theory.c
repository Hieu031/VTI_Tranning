#include <stdio.h>
#include <stdlib.h>
/*
Danh sách liên kết là một tập hợp các Node được phân bổ động,
mỗi Node chứa một giá trị và một con trỏ trỏ đến Node tiếp theo nó.
Nếu con trỏ là NULL, thì nó là Node cuối cùng.
Một linked list được giữ bằng cách sử dụng một biến con trỏ cục bộ trỏ đến
mục đầu tiên của list. 
Nếu con trỏ đó NULL, thì list là trống.
Về cơ bản, linked list giống một array tuy nhiên có thể phát triển và thu nhỏ
khi cần thiết từ bất kỳ một node nào.
*/

//Ini struct Node
typedef struct node{
    int data;//var data
    struct node *next;// node points to next Node in list
} node_t;

//function print all Nodes
void printList(node_t* head){
    node_t *pt = head;
    while (pt != NULL)
    {
        printf("%d ", pt->data);
        pt = pt->next;
    }
}

int main(){
    //Creat 3 ptr position
    node_t* head = NULL;
    node_t* second = NULL;
    node_t* third = NULL;

    //allocate 3 nodes in the heap
    head  =(node_t*)malloc(sizeof(node_t));
    second  =(node_t*)malloc(sizeof(node_t));
    third  =(node_t*)malloc(sizeof(node_t));

    //handle node 1
    head->data = 1; //assign data in first node
    head->next = second;//link first node with second node
    //node 2
    second->data = 2;
    second->next = third;
    //node 3
    third->data = 3;
    third->next = NULL;

    printList(third);

    return 0;
}
