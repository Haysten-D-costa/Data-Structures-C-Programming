//C PROGRAM TO IMPLEMENT A BINARY SEARCH
#include<stdio.h>
int main() {
    //Declaration of variables and array
    int A[100], n, i, search, count = 0;
    int low, mid, up;
    //Input of variables and array
    printf("Enter the number of elements : "); //No. of entries
    scanf("%d", &n);
    printf("\nEnter %d elements : \n", n);
    for(i=0; i<n; i++) { //Accepting array elements
        scanf("%d", &A[i]);
    }
    printf("\nEnter element to be searched : ");
    scanf("%d", &search);
    //Output of entered array
    printf("\nArray entered : \n");
    for(i=0; i<n; i++) {
        printf("%d\t", A[i]);
    }
    printf("\nSearching for element '%d' in above array...\n", search);
    low = 0;
    up = n-1;
    mid = (low + up)/2;
    //Process of element search(BINARY)
    while(low <= up)
    {
        mid = (low + up)/2;
        if(A[mid] == search)//Successful search
        {
            count ++;
            printf("\nElement '%d' found %d time at position %d [index %d]\n", search,         count, mid+1, mid);
        } //Search methods(Left & Right)
        if(A[mid] > search)
            up = mid - 1;
        else
            low = mid + 1;
    }
    if(count == 0)
    { //Unsuccessful search
        printf("\n\nElement not found !! \n");
    }
    return(0);
}
