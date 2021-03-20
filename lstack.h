#include "common.h"

typedef char StackEntry;
typedef struct node {
    StackEntry entry;
    struct node *next;
} Node;
typedef struct stack {
    Node *top;
} Stack;

Node *MakeNode(StackEntry item);
void CreateStack(Stack *s);
void Push(StackEntry item, Stack *s);
void Pop(Stack *s);
void TraverseStack(Stack *s, void (*Visit)(StackEntry));
void StackTop(StackEntry *item, Stack *s);
void ClearStack(Stack *s);
int StackSize(Stack *s);
Boolean StackEmpty(Stack *s);
/*
void PopNode(); // not sure what this is for but it was mentioned in the book
*/
Boolean StackFull(Stack *s);




void ClearStack(Stack *s) {
    if(StackEmpty(s))
        Error("Stack is empty");
    else {
        Node *tmp = s->top;
        while(tmp!=NULL) {
            tmp = tmp->next;
            free(s->top);
            s->top = tmp;
        }
    }
}

/* MakeNode: make a new node and insert item
 * Pre:     None.
 * Post:    Create a new node and insert item in it.
 * */
Node *MakeNode(StackEntry item) {
    Node *nodepointer;
    if((nodepointer = malloc(sizeof(Node))) == NULL)
        Error("Exhausted memory.");
    else {
        nodepointer->entry = item;
        nodepointer->next = NULL;
    }
    return nodepointer;
}

void Pop(Stack *s) {
    if(StackEmpty(s))
        Error("Stack is empty");
    else {
        Node *tmp = s->top;
        tmp = tmp->next;
        free(s->top);
        s->top = tmp;
    }
}

/* CreateStack
 * Pre:     None.
 * Post:    The stack has been created and is initialized to be empty.
 * */
void CreateStack(Stack *s) {
    s->top = NULL;
}

/* Push: make a new node with item and push it onto the stack.
 * Pre:     The stack exists and has been initialized.
 * Post:    The argument item has been stored at the top of the stack.
 * */
void Push(StackEntry item, Stack *s) {
    Node *np = MakeNode(item);
    if(np == NULL)
        Error("Attempted to push a non-existing node.");
    else {
        np->next = s->top;
        s->top = np;
    }
}

void TraverseStack(Stack *s, void (*Visit)(StackEntry)) {
    if(StackEmpty(s))
        Error("Stack is empty");
    else {
        Node *tmp = s->top;
        while(tmp!=NULL){
            (*Visit)(tmp->entry);
            tmp = tmp->next;
        }
    }
}

Boolean StackEmpty(Stack *s) {
   return s->top == NULL;
}

Boolean StackFull(Stack *s) {
    return malloc(sizeof(Node)) == NULL;
}

void StackTop(StackEntry *item, Stack *s) {
    if(StackEmpty(s))
        Error("Stack is empty");
    else {
        *item = s->top->entry;
    }
}


int StackSize(Stack *s) {
    int s_size = 0;
    if(StackEmpty(s))
        Error("Stack is empty");
    else {
        Node *tmp = s->top;
        while(tmp!=NULL){
            tmp = tmp->next;
            s_size++;
        }
    }
    return s_size;
}
