#include <stdio.h>
#include <stdlib.h>

struct node { //NODE SPECIFICATIONS
    int info;
    struct node *prev;
    struct node *next;
};
struct node *tmp, *start = NULL;
int data, pos, choiceIns, choiceDel, i, n; //GLOBAL DECLARATION
void getData(), getPos();
void create();  //C-FUNCTIONS FOR REQUIRED (OPERATIONS)
void print01(), print02(), print03();  //TO PRINT THE OPERATION TO BE PERFORMED

void searchE();  //SEARCHING FOR REQUIRED ELEMENT IN LINKED-LIST
void displayE();  //DISPLAYING THE LINKED-LIST
void countE();  //COUNTING NO. OF ELEMENTS IN LINKED-LIST
void reverseL();
void insEmpty();  //INSERION FUNCTIONS IN LINKED-LIST
void insBeginning();
void insEnd();
void insBeforeN();
void insAfterN();
void insGivenPos();
void delFirstN();  //DELETION FUNCTIONS IN LINKED-LIST
void delOnlyN();
void delInBetN();
void delAtEnd();

int main() {
    int choice;
    create();
    do {
        print01();
        printf("\nEnter Required Choice of Operations : ");
        scanf("%d", &choice);
        system("clear");
        switch(choice) {
            case 1 :print02();
                    printf("\nEnter Required choice  for Insertion : ");
                    scanf("%d", &choiceIns);
                    system("clear");
                    switch(choiceIns) {
                        case 1 :insBeginning();
                                break;
                        case 2 :insEnd();
                                break;
                        case 3 :insBeforeN();
                                 break;
                        case 4 :insAfterN();
                                break;
                        case 5:insEmpty();
                                break;
                        default:printf("\nIncorrect choice of operation entered ! \n");
                    }
                    break;
            case 2 :print03();
                    printf("\nEnter required choice for deletion : ");
                    scanf("%d", &choiceDel);
                    system("clear");
                    switch(choiceDel) {
                        case 1 :delFirstN();
                                break;
                        case 4 :delOnlyN();
                                break;
                        case 2 :delInBetN();
                                break;
                        case 3 :delAtEnd();
                                break;
                        default:printf("\nIncorrect choice of operation entered ! \n");
                    }
                    break;
            case 3 :displayE();
                    break;
            case 4 :countE();
                    break;
            case 5 :searchE();
                    break;
            case 6 :reverseL();
                    break;
            case 0 :printf("\nProgram Exited !!\n");
                    break;
            default:printf("\nIncorrect choice of operation entered !\n");
                    printf("Check and try again !");
        }
    }while(choice != 0);
    return(0);
}
void print01() {
    printf("\n1 -> Insert element in LinkedList\n");
    printf("2 -> Delete element in LinkedList\n");
    printf("3 -> Display LinkedList\n");
    printf("4 -> Count elements in LinkedList\n");
    printf("5 -> Search for elements in LinkedList\n");
    printf("6 -> Reverse the LinkedList\n");
    printf("0 -> Exit the program\n");
}
void print02() {
    printf("\n\n1 -> Insertion at Beginning of List\n");
    printf("2 -> Insertion at End of List\n");
    printf("3 -> Insertion before a node in List\n");
    printf("4 -> Insertion after a node in List\n");
    if(n == 0) {
        printf("5 -> Insertion in an Empty List\n");
    }
}
void print03() {
    printf("\n\n1 -> Deletion of First node\n");
    if(n == 1) {
        printf("4 -> Deletion of Only node\n");
    }
    printf("2 -> Deletion in between node\n");
    printf("3 -> Deletion of End node\n");
}
void getData() {
    printf("Enter the data to be inserted : ");
    scanf("%d", &data);
}
void getPos() {
    printf("\nEnter the reference element : ");
    scanf("%d", &pos);
}
void posDel() {
    printf("\nEnter element to be deleted : ");
    scanf("%d", &pos);
}
void create() {
    printf("\nEnter the no. of nodes to be created : ");
    scanf("%d", &n);
    if(n == 0) {
        return;
    }
    insEmpty();
    for(i=2; i<=n; i++) {
        insEnd();
    }
}
void displayE() {
    struct node *p;
    if(start == NULL) { printf("\nEMPTY LIST !\n"); }
    else {
        p = start;
        printf("LIST IS :\t");
        while(p != NULL) {
            printf("%d\t", p->info);
            p = p->next;
        }
    }
}
void insEmpty() {
    getData();
    tmp = (struct node *)malloc(sizeof(struct node));
    tmp->info = data;
    tmp->prev = NULL;
    tmp->next = NULL;
    start = tmp;
}
void insBeginning() {
    getData();
    tmp = (struct node *)malloc(sizeof(struct node));
    tmp->info = data;
    tmp->prev = NULL;
    tmp->next = start;
    start->prev = tmp;
    start = tmp;
}
void insEnd() {
    getData();
    struct node *p;
    tmp = (struct node *)malloc(sizeof(struct node));
    tmp->info = data;
    p = start;
    while(p->next != NULL) {
        p = p->next;
    }
    p->next = tmp;
    tmp->next = NULL;
    tmp->prev = p;
}
void insBeforeN() {
    int count = 0;
    getData(); getPos();
    tmp= (struct node *)malloc(sizeof(struct node));
    struct node *p;
    p = start;
    while(p != NULL) {
        if(p->info == pos) {
            count ++;
            tmp->info = data;
            tmp->prev = p->prev;
            tmp->next = p;
            p->prev->next = tmp;
            p->prev = tmp;
        }
        p = p->next;
    }
    if(count == 0) {
        printf("\nElement %d not found !\n", data);
    }
       
}
void insAfterN() {
    int count = 0;
    getData(); getPos();
    tmp= (struct node *)malloc(sizeof(struct node));
    struct node *p;
    tmp->info = data;
    p = start;
    while(p != NULL) {
        if(p->info == pos) {
            count ++;
            tmp->prev = p;
            tmp->next = p->next;
            if(p->next != NULL) {
                p->next->prev = tmp;
            }
            p->next = tmp;
        }
        p = p->next;
    }
    if(count == 0) {
        printf("\nElement %d not found !\n", data);
    }
}
void delOnlyN() {
    if(start == NULL) { printf("\nUNDERFLOW \n"); }
    else {
        tmp = start;
        start = NULL;
        free(tmp);
    }
}
void delFirstN() {
    if(start == NULL) { printf("\nUNDERFLOW !\n"); }
    else {
        tmp = start;
        start = start->next;
        start->prev = NULL;
        free(tmp);
    }
}
void delInBetN() {
    posDel();
    tmp = start;
    while(tmp != NULL) {
        if(tmp->info == pos) {
            tmp->prev->next = tmp->next;
            tmp->next->prev = tmp->prev;
            free(tmp);
        }
        tmp = tmp->next;
    }
}
void delAtEnd() {
    tmp = start;
    while(tmp-> next != NULL) {
        tmp = tmp->next;
    }
    tmp->prev->next = NULL;
    free(tmp);
}
void countE() {
    int count = 0;
    struct node *p;
    if(start == NULL) { printf("\nLIST EMPTY\n"); }
    else {
        p = start;
        while(p != NULL) {
            count++;
            p = p->next;
        }
    }
    printf("\nList contains %d elements !\n", count);
}
void searchE() {
    int count = 0, search, pos = 0;
    printf("\nEnter element to be searched\n");
    scanf("%d", &search);
    struct node *p;
    if(start == NULL) { printf("\nLIST EMPTY\n"); }
    else {
        p = start;
        while(p != NULL) {
            if(p->info == search) {
                printf("\nElement found at position %d (index %d)\n", pos+1, pos);
                count++;
            }
            pos++, 
            p = p->next;
        }
    }
    if(count == 0) {
        printf("\nElement %d doesnt exists\n", search);
    }
}
void reverseL(){
    struct node *p1, *p2;
    p1 = start;
    p2 = p1->next;
    p1->next = NULL;
    p1->prev = p2;
    while(p2 != NULL) {
        p2->prev = p2->next;
        p2->next = p1;
        p1 = p2;
        p2 = p2->prev;
    }
    start = p1;
    printf("\nList reversed :\n");

}