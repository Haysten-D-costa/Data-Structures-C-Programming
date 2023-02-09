//C PROGRAM TO IMPLEMENT A LINEAR SEARCH
#include<stdio.h>
int main() {
    //DECLARATION AND  INITIALIZATION OF VARIABLES
    int A[100], n, i, search, count = 0;
    //INPUT OF VARIABLES AND ARRAY
    printf("Enter the number of elements : ");
    scanf("%d", &n);
    printf("\nEnter %d elements : \n", n);
    for(i=0; i<n; i++) {
        scanf("%d", &A[i]);
    }
    printf("\nEnter element to be searched : ");
    scanf("%d", &search);
    //OUTPUT OF ARRAY
    printf("\nArray entered : \n");
    for(i=0; i<n; i++) {
        printf("%d\t", A[i]);
    }
    //PROCESS OF ELEMENT SEARCH
    printf("\n\nSearching for element '%d' in above array...\n", search);
    //OUTPUT (POSITION + COUNT)
    for(i=0; i<n; i++) {
        if(A[i] == search) {
            count ++;
            printf("\nElement '%d' found %d time at position %d [index %d]", search, count, i+1, i);
        }
    }
    if(count == 0) {
        printf("\n\nElement not found !! ");
    }
    return(0);
}
