#include<stdio.h>
#include<stdlib.h>

struct node {  //NODE SPECIFICATIONS
    int info;  //DATA PART
    struct node *link;  //LINK PART
};
struct node *start = NULL;
int data, pos, search, choiceIns, choiceDel, i, n; //GLOBAL DECLARATION
void create();  //C-FUNCTIONS FOR REQUIRED (OPERATIONS)
void print01(), print02(), print03();
void insEmpty(int data);  //INSERION FUNCTIONS IN LINKED-LIST
void insBeginning(int data);
void insEnd(int data);
void insBeforeN( int pos, int data);
void insAfterN(int data, int pos);
void insGivenPos(int data, int pos);
void delFirstN();  //DELETION FUNCTIONS IN LINKED-LIST
void delonlyN();
void delInBetN();
void delAtEnd();
void reverseL();
void displayE();  //DISPLAYING THE LINKED-LIST
void countE(int data);  //COUNTING NO. OF ELEMENTS IN LINKED-LIST
void searchE(int search);  //SEARCHING FOR REQUIRED ELEMENT IN LINKED-LIST

int main() {
    int choice;
    create();
    do {
        print01();
        printf("\nEnter Required Choice of Operations : ");
        scanf("%d", &choice);
        //system("clear");
        switch(choice) {
            case 1 :printf("\nEnter the data to be inserted : ");
                    scanf("%d", &data);
                    print02();
                    printf("\nEnter Required choice of Insertion : ");
                    scanf("%d", &choiceIns);
                    //system("clear");
                    switch(choiceIns) {
                        case 1 :insBeginning(data);
                                break;
                        case 2 :insEnd(data);
                                break;
                        case 3 :printf("\nEnter the reference element : ");
                                scanf("%d", &pos);
                                insBeforeN(pos, data);
                                break;
                        case 4 :printf("\nEnter the reference element : ");
                                scanf("%d", &pos);
                                insAfterN(data, pos);
                                break;
                        case 5 :printf("\nEnter the position to be placed : ");
                                scanf("%d", &pos);
                                insGivenPos(data, pos);
                                break;
                        case 6 :insEmpty(data);
                                break;
                        default:printf("\nIncorrect choice of operation entered ! \n");
                    }
                    break;
            case 2 :print03();
                    printf("\nEnter required choice for deletion : ");
                    scanf("%d", &choiceDel);
                    //system("clear");
                    switch(choiceDel) {
                        case 1 :delFirstN();
                                break;
                        case 2 :delonlyN();
                                break;
                        case 3 :printf("\nEnter element to be deleted : ");
                                scanf("%d", &data);
                                delInBetN(data);
                                break;
                        case 4 :delAtEnd();
                                break;
                        default:printf("\nIncorrect choice of operation entered ! \n");
                    }
                    break;
            case 3 :displayE();
                    break;
            case 4 :countE(data);
                    break;
            case 5 :printf("\nEnter element to be searched : ");
                    scanf("%d", &search);
                    searchE(search);
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
    printf("\n\n1 -> Insert element in LinkedList\n");
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
    printf("5 -> Insertion at a given position in List\n");
    if(n == 0) {
        printf("6 -> Insertion in an Empty List\n");
    }
}
void print03() {
    printf("\n\n1 -> Deletion of First node\n");
    if(n == 1) {
        printf("2 -> Deletion of Only node\n");
    }
    printf("3 -> Deletion in between node\n");
    printf("4 -> Deletion of End node\n");
}
void create() {

    printf("\nEnter the no. of nodes to be created : ");
    scanf("%d", &n);
    if(n == 0) {
        return;
    }
    printf("\nEnter Element 1 to be inserted : ");
    scanf("%d", &data);
    insEmpty(data);
    for(i=2; i<=n; i++) {
        printf("Enter Element %d to be inserted : ",i);
        scanf("%d", &data);
        insEnd(data);
    }
}
void insEmpty(int data) {
    struct node *tmp;
    tmp = (struct node *)malloc(sizeof(struct node));
    tmp->info = data;
    tmp->link = NULL;
    start = tmp;
}
void insBeginning(int data) {
    struct node *tmp;
    tmp = (struct node *)malloc(sizeof(struct node));
    tmp->info = data;
    tmp->link = start;
    start = tmp;
}
void insBeforeN( int pos, int data) {
    struct node *tmp, *p;
    if(start == NULL) {
        printf("\nEMPTY LIST\n");
    }else {
        p = start;
        tmp = (struct node*)malloc(sizeof(struct node));
        tmp->info = data;
        while(p->link != NULL) {
            if(p -> link -> info == pos) {
                tmp->link = p->link;
                p->link = tmp;
                return;
            }
            p = p->link;
        }
        if(p->link == NULL) {
            printf("\nElement not found \n");
            return;
        }
    }
}
void insAfterN(int data, int pos) {
    struct node *tmp, *p;
    p = start;
    int count = 0;
    while(p != NULL) {
        if(p->info == pos) {
            count++;
            tmp = (struct node *)malloc(sizeof(struct node));
            tmp->info = data;
            tmp->link = p->link;
            p->link = tmp;
        }
        p = p->link;
    }
    if(count == 0) {
        printf("\nElement not found !\n");
    }
}
void insGivenPos(int data, int pos) {
    int i, count = 0;
    struct node *tmp, *p;
    tmp = (struct node *)malloc(sizeof(struct node));
    tmp->info = data;
    if(pos == 1) {
        count++;
        tmp->link =start;
        start = tmp;
    }
    p = start;
    for(i=1; i<pos-1 && p != NULL; i++) {
        p = p->link;
    }
    if(p == NULL) {
        printf("\nLess than %d elements present !\n", pos);
    }
    else {
        count++;
        tmp->link = p->link;
        p->link = tmp;
    }
}
void insEnd(int data) {
    struct node *p, *tmp;
    tmp = (struct node *)malloc(sizeof(struct node));
    tmp->info = data;
    if(start == NULL) {
        printf("\nEMPTY LIST\n");
    }
    else {
        p = start;
        while(p->link != NULL) {
            p = p->link;
        }
        p->link = tmp;
        tmp->link = NULL;
    }
}
void delFirstN() {
    struct node *tmp;
    tmp = start;
    start = start->link;
    free(tmp);
}
void delonlyN() {
    struct node *tmp;
    tmp = start;
    start = NULL;
    free(tmp);
}
void delInBetN(int data) {
    int c = 0;
    struct node *tmp, *p;
    if(start == NULL) {
        printf("\nEMPTY LIST\n");
    }
    p = start;
    while(p->link != NULL) {
        if(p->link->info == data) {
            c++;
            tmp = p->link;
            p->link = tmp->link;
            free(tmp);
        }
        p = p->link;
    }
    if(c == 0) {
        printf("\nElement not found \n");
    }
}
void delAtEnd() {
    struct node *tmp, *p;
    if(start == NULL) {
        printf("\nEMPTY LIST\n");
    }
    else {
        p = start;
        tmp = start->link;
        while(tmp->link != NULL) {
            p = p->link;
            tmp = tmp->link;
        }
        p->link = NULL;
        free(tmp);
    }
}
void displayE() {  //TO DISPLAY THE LINKED LIST
    struct node *p;
    if(start == NULL) {
        printf("\nEMPTY LIST\n");
    }
    else {
        p = start;
        printf("\nLIST IS :\t");
        while(p != NULL) {
            printf("%d\t", p->info);
            p = p->link;
        }
    }
}
void countE(int data) {  //To COUNT THE NO. OF ELEMENTS IN THE LINKED-LIST
    int count = 0;
    struct node *p;
    if(start == NULL) {
        printf("\nEMPTY LIST\n");
    }
    else {
        p = start;
        while(p != NULL) {
            p = p->link;
            count ++;
        }
        printf("\nThe List contains %d elements \n", count);
    }
}
void searchE(int search) {  //TO SEARCH FOR A PARTICULAR ELEMENT IN THE LINKED-LIST
    struct node *p;
    if(start == NULL) {
        printf("\nEMPTY LIST\n");
    }
    else {
        p = start;
        int pos = 1, count = 0;
        while(p != NULL) {
            if(p->info == search) {
                printf("Element found %d time at position %d(index %d)\n", count+1, pos, pos-1);
                count++;
            }
            p = p->link;
            pos++;
        }
        if(count == 0) {
            printf("\nElement not found ! \n");
        }
    }
}
void reverseL() {
    struct node *prev, *next, *ptr;
    prev = NULL;
    ptr = start;
    while(ptr != NULL) {
        next = ptr->link;
        ptr->link = prev;
        prev = ptr;
        ptr = next;
    }
    start = prev;
}
