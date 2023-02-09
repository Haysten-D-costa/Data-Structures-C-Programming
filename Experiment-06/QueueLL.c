#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *link;
};
void peek();
void enqueue();
void dequeue();
void display();

struct node *tmp, *front = NULL, *rear = NULL;
int main() {
    printf("1 -> Insert Element \n");
    printf("2 -> Delete Element \n");
    printf("3 -> Display Element \n");
    printf("4 -> Peek Element \n");
    printf("0 -> Exit Program\n");
    int choice;
    do {
        printf("\nEnter a choice of operation : ");
        scanf("%d", &choice);
        switch(choice) {
            case 1 :enqueue();
                    break;
            case 2 :dequeue();
                    break;
            case 3 :display();
                    break;
            case 4 :peek();
                    break;
            case 0 :printf("\nProgram Exited !\n");
                    break;
            default:printf("\nWrong choice code inputed !\n");
        }
    }while(choice != 0);
    return(0);
}
void enqueue() {
    int data;
    printf("Enter the element to be inserted : ");
    scanf("%d", &data);
    tmp = (struct node *)malloc(sizeof(struct node));
    tmp->info = data;
    tmp->link = NULL;
    if(front == NULL) {
        front = tmp;
    }else {
        rear->link = tmp;
    }
    rear = tmp;
}
void dequeue() {
    int data;
    if(front == NULL) { printf("\nQUEUE UNDERFLOW\n"); }
    else {
        tmp = front;
        data = tmp->info;
        printf("\nElement %d deleted", data);
        front = tmp->link;
        free(tmp);
    }
}
void display() {
    struct node *p;
    if(front == NULL) { printf("\nQUEUE IS EMPTY\n"); }
    else {
        p = front;
        printf("\nQUEUE IS :\t");
        while(p != NULL) {
            printf("%d\t", p->info);
            p = p->link;
        }
        printf("\n");
    }
}
void peek() {
    printf("Element at top of Queue : %d\n", front->info);
}
