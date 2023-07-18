#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *link;
};
void pop();
void push();
void peek();
void display();

struct node *tmp, *top = NULL;

int main() {
    printf("1 -> Push Element \n");
    printf("2 -> Pop Element \n");
    printf("3 -> Display element \n");
    printf("4 -> Peek Element \n");
    printf("0 -> Exit Program\n");
    int choice;
    do {
        printf("\nEnter a choice of operation : ");
        scanf("%d", &choice);
        switch(choice) {
            case 1 :push();
                    break;
            case 2 :pop();
                    break;
            case 3 :display();
                    break;
            case 4 :peek();
                    break;
            case 0 :printf("\nProgram Exited !\n");
                    break;
            default :printf("\nWrong choice code inputed !\n");
        }
    }while(choice != 0);
    return(0);
}
void push() {
    int data;
    printf("Enter the data to be inserted : ");
    scanf("%d", &data);
    tmp = (struct node *)malloc(sizeof(struct node));
    tmp->info = data;
    tmp->link = top;
    top = tmp;
}
void pop() {
    int data;
    if(top == NULL) { printf("\nUNDERFLOW ! \n"); }
    else {
        tmp = top;
        data = tmp->info;
        printf("\nElement %d deleted ", data);
        top = top->link;
        free(tmp);
    }
}
void display() {
    struct node *p;
    if(top == NULL) { printf("\nEMPTY STACK\n"); }
    else {
        p = top;
        printf("\nSTACK IS : \n");
        while(p != NULL) {
            printf("%d\n", p->info);
            p = p->link;
        }
    }
}
void peek() {
    printf("\nElement at the top of Stack : %d\n", top->info);
}
