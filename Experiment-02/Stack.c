//C PROGRAM TO IMPLEMENT A STACK USING ARRAY
#include<stdio.h>
int isFull();  //FUNCTION DECLARATION
int isEmpty();
void push();
void pop();
void peek();
void display();
int n, top=-1, value, Stack[50];//DECLARATION AND INITIALIZATION (GLOBALLY)
int main() {  //MAIN FUNCTION

    int choice;
    printf("Enter no. of elements : ");  //INPUT OF MAX NO. OF ELEMENTS
    scanf("%d", &n);
    printf("\nOPERATION CHOICES : ");  //DISPLAYING OPERATION CODES
    printf("\n\t-> 1: PUSH Operation..");
    printf("\n\t-> 2: POP Operation..");
    printf("\n\t-> 3: PEEK Operation..");
    printf("\n\t-> 4: DISPLAY Operation..");
    printf("\n\t-> 5: EXIT..\n");
    do {  //TO REPEATIDLY PERFORM OPERATIONS ON THE STACK
        printf("\nEnter your choice : ");
        scanf("%d", &choice);
        switch(choice) {  //TO CHOOSE OPERATIONS TO BE PERFORMED
                    //FUNCTION CALLS
            case 1 :push();
                    break;
            case 2 :pop();
                    break;
            case 3 :peek();
                    break;
            case 4 :display();
                    break;
            case 5 :printf("-> *** PROGRAM EXITED ! ***\n");//TO EXIT PROGRAM
                    break;
            default:printf("\n-> *** Invalid choice entered !...Please check !! ***\n");
        }
    }
    while(choice != 5);
    return(0);
}  //FUNCTIONS DEFINITIONS TO PERFORM REQUIRED OPERATIONS
int isFull() {  //TO CHECK IF STACK IS FULL
    if(top == n-1) {
        return(1);
    }
    else {
        return(0);
    }
}
int isEmpty() {  //TO CHECK IF STACK IS EMPTY
    if(top == -1)
        return(1);
    else
        return(0);
}
void push() {  //TO INSERT[PUSH] ELEMENT TO STACK
    printf("Enter value to be entered : ");
    scanf("%d", &value);
    if(isFull()) {  //CHECKING IF FULL FIRST
        printf("\n-> *** STACK OVERFLOW ***\n");
   }
   top += 1;
   Stack[top] = value;
}
void pop() {  //TO DELETE[POP] ELEMENT FROM QUEUE
    if(isEmpty()) { //CHECKING IF EMPTY FIRST
        printf("\n-> *** STACK UNDERFLOW ***\n");
    }
    value = Stack[top];
    top -= 1;
}
void display() {  //TO DISPLAY THE CONTENTS OF STACK
    int i;
    if(top>=0) {
        printf("\n-> Elements in stack : \n");
        for( i=top; i>=0; i--) {
            printf("\n   %d",Stack[i]);
        }
    }
    else {
        printf("\n-> *** The STACK is empty !! ***\n");
    }
}
void peek() {  //TO CHECK [PEEK] THE TOPMOST ELEMENT IN THE STACK
    if(isEmpty()) {
        printf("\n-> *** STACK UNDERFLOW ***\n");
    }
    else {
        printf("\n-> Peek element(top) = %d\n", Stack[top]);
    }
}
