#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *link;
};
void peek();
void enqueue();
void dequeue();
void display();
struct node *front = NULL, *rear = NULL;

int main() {
    printf("\nOPERATION CHOICES : ");
    printf("\n\t-> 1: INSERT Operation..");
    printf("\n\t-> 2: DELETE Operation..");
    printf("\n\t-> 3: PEEK Operation..");
    printf("\n\t-> 4: DISPLAY Operation..");
    printf("\n\t-> 5: EXIT..\n");
    int choice;
    do {

        printf("\nEnter your choice : ");
        scanf("%d", &choice);
        switch(choice) {
            case 1 :enqueue();
                    break;
            case 2 :dequeue();
                    break;
            case 3 ://system("cls");
                    peek();
                    break;
            case 4 ://system("cls");
                    display();
                    break;
            case 5 :printf("\nPROGRAM EXITED !\n");
                    break;
            default:printf("\nInvalid choice entered !...Please check !!\n");
        }
    }
    while(choice != 5);
    return(0);
}
void peek() {
    if(front == NULL) {
        printf("\nList Empty !\n");
    }
    else {
        printf("\nThe peek element is : %d \n", front->data);
    }
}
void enqueue() {
    struct node *tmp;
    tmp = (struct node*)malloc(sizeof(struct node));
    printf("Enter the data to insert : ");
    scanf("%d", &tmp->data);
    //system("cls");
    if(front == NULL) {
        rear = front = tmp;
        tmp->link = tmp;
    }
    else {
        rear->link = tmp;
        tmp->link = front;
        rear = tmp;
    }
    //printf("\nSuccessfully pushed !!\n");
}
void dequeue() {
    struct node *tmp;
    if(front != NULL) {
        if(front->link == front) {
            tmp = front;
            front = NULL;
            free(tmp);
        }else {
            tmp = front;
            front = front->link;
            rear->link = front;
            free(tmp);
            //system("cls");
            //printf("\nSuccessfully popped the element !!\n");
        }
    }else {
        printf("\nUNDERFLOW\n");
    }
}
void display() {
    struct node *p;
    if(front == NULL) {
        printf("EMPTY LIST\n");
    }else {
        p = front;
        printf("QUEUE IS :");
        do {
            printf(" %d ", p->data);
            p = p->link;
        }while(p != front);
        printf("\n");
    }
}
