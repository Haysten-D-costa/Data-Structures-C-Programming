//C PROGRAM TO IMPLEMENT A QUEUE USING ARRAY
#include <stdio.h>

int isFull();  //FUNCTION DECLARATIONS
int isEmpty();
void enqueue();
void dequeue();
void peek();
void display();

int n, R=-1, F=-1, value, Queue[50];  //DECLARATION AND INITIALIZATION (GLOBALLY)
int main() {  //MAIN FUNCTION
    int choice;
    printf("Enter no. of elements : ");  //INPUT OF MAX NO. OF ELEMENTS IN OUEUE
    scanf("%d", &n);
    printf("\n\nOPERATION CHOICES : ");
    printf("\n\t-> 1: INSERT Operation..");
    printf("\n\t-> 2: DELETE Operation..");
    printf("\n\t-> 3: PEEK Operation..");
    printf("\n\t-> 4: DISPLAY Operation..");
    printf("\n\t-> 5: EXIT..\n");
    do {
        printf("\nEnter your choice : ");  //INPUT OF OPERATION CODE
        scanf("%d", &choice);
        switch(choice) {
                    //FUNCTION CALLS
            case 1 :enqueue();
                    break;
            case 2 :dequeue();
                    break;
            case 3 :peek();
                    break;
            case 4 :display();
                    break;
            case 5 :printf("*** PROGRAM EXITED ! ***\n");  //TO STOP AND EXIT PROGRAM
                    break;
            default:printf("\n*** Invalid choice entered !...Please check !! ***\n");
        }
    }
    while(choice != 5);
    return(0);
}  //FUNCTION DEFINITIONS
int isFull() {  //TO CHECCK IF OUEUE IS FULL
    if(R == n-1) {
        return(1);
    }
    else {
        return(0);
    }
}
int isEmpty() {  //TO CHECK IF QUEUE IS EMPTY
    if((F == -1)||(F>R)) {
        return(1);
    }
    else {
        return(0);
    }
}
void enqueue() {  //TO ADD ELEMENT TO QUEUE
    printf("Enter value to be entered : ");
    scanf("%d", &value);
    if(isFull()) {
        printf("\n*** OVERFLOW ***\n");
   }else {
    if(F == -1) {
        F=0;
    }
    R = R + 1;
    Queue[R] = value;
   }
}
void dequeue() {  //TO DELETE ELEMENTS FROM QUEUE
    if(isEmpty()) {
        printf("\n*** UNDERFLOW ***\n");
    }
    else {
        value = Queue[F];
        Queue[F]=0;
        F = F + 1;
    }
}
void display() {  //TO DISPLAY CONTENT OF QUEUE
    int i;
    if(isEmpty()) {
        printf("\n*** QUEUE IS EMPTY ***\n");
    }else{
        printf("\n*** Elements in queue : \n   ");
        for( i=0; i<=R; i++) {
            printf("%d\t",Queue[i]);
        }
        printf("\n");
    }
}
void peek() {  //TO CHECK THE TOPMOST ELEMENT OF QUEUE
    if(isEmpty()) {
        printf("\n*** QUEUE UNDERFLOW ***\n");
    }else {
        printf("\n*** Peek element(top) = %d ***\n", Queue[F]);
    }
}
