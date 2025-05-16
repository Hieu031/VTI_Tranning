#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}node_t;

node_t* creatNode(int val){
    node_t *temp =  (node_t*)malloc(sizeof(node_t));
    if(temp == NULL){
        printf("Memory allocation failed!\n");
        exit(1);
    }  
    temp->data = val;
    temp->next = NULL;
}

void pushNodeAt(node_t **head, int val, int pos){
    if (*head == NULL && pos != 1){
        printf("Invalid position!\n");
        return;
    }

    if(pos == 1){
        node_t *new_node = creatNode(val);
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

    node_t *new_node = creatNode(val);
    new_node->next = pt->next;
    pt->next = new_node;
}

void printList(node_t* head){
    node_t* temp = head;
    while(temp != NULL){
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main(){
    node_t* head = NULL;//Init node head

    pushNodeAt(&head, 7, 1);
    pushNodeAt(&head, 8, 1);
    pushNodeAt(&head, 10, 2);
    pushNodeAt(&head, 12, 4);

    printList(head);

    return 0;
}

