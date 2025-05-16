#include<iostream>
#include<stdlib.h>
#include<string.h>

using namespace std;

typedef struct {
    int top; //position node top of stack
    int *node; //list element of stack
} Stack;

//declare function prototype
void initStack(Stack *st);
void push(Stack *st, int node);
int pop(Stack *st);
void release(Stack *st);

int main(){
    Stack *st = new Stack; // allocate memory for stack
    initStack(st); // initialize stack

    //push data to stack
    for(int i = 0; i < 5; i++){
        push(st, i + 1); // push data to stack
    }

    cout << "Pop data from stack: " << endl;
    while(st->top >= 0){
        cout << pop(st) << " "; // pop data from stack
    }
    cout << endl;

    release(st); // free memory for stack
    return 0;
}

void initStack(Stack *st){
    st = new Stack; // allocate memory for stack
    st->top = -1; // initialize stack empty
}

void push(Stack *st, int node){
    int *tmpNode = new int[st->top + 2]; // allocate memory for stack
    for(int i = 0; i <= st->top; i++){
        tmpNode[i] = st->node[i]; // copy data from old stack to new stack
    }
    tmpNode[st->top + 1] = node; // add new node to stack
    delete[] st->node; // free memory for old stack
    st->node = tmpNode; // assign new stack to old stack
    return;
}

int pop(Stack *st){
    //check stack empty
    if(st->top < 0){
        cout << "Stack is empt\n";
        return 0;
    }

    int result = st->node[st->top]; // get top node of stack
    int *tmpNodes = new int[st->top]; //allocate memory for stack
    for(int i = 0; i < st->top; i++){
        tmpNodes[i] = st->node[i]; // copy data from old stack to new stack
    }

    st->top--; // decrease top node of stack
    delete[] st->node; // free memory for old stack]
    st->node = tmpNodes; // assign new stack to old stack
    return result; // return top node of stack
}

void release(Stack *st){
    delete[] st->node; // free memory for stack
    delete st; // free memory for stack
    st = NULL; // set pointer to NULL to avoid dangling pointer
    return;
}


