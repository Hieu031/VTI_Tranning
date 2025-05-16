#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}node_t;

node_t* creatNode(int val){
    node_t *temp = (node_t*)malloc(sizeof(node_t));
    if(temp == NULL){
        printf("Allocation failed!\n");
        exit(1);
    }
    temp->data = val;
    temp->next = NULL;
}

void deleteFirst(node_t **head){
    //to do
    node_t *new_head = (*head)->next;
    free(*head);
    *head = new_head;
}

void deleteAt(node_t **head, int pos){
    //to do
    if(*head == NULL && pos != 1){
        printf("LinkedList empty or pos invalid!\n");
        return;
    }

    int k = 0;
    node_t *temp = *head;
    while(temp != NULL && k != pos - 1){
        temp = temp->next;
        k++;
    }

    if(k != pos - 1){
        printf("invalid position!\n");
        return;
    }
    else{
        node_t *tempToDel = temp->next;
        temp->next = temp->next->next;
        free(tempToDel);
    }
}

void deleteEnd(note_t **head){
    //to do
    node_t *temp = *head;
    while(temp->next->next != NULL){
        temp = temp->next; 
    }
    free(temp->next);
    temp-next =NULL;
}

void printList(node_t *head){
    node_t* temp = head;
    while(temp != NULL){
        printf("%d ->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}



