//C PROGRAM TO IMPLEMENTATION MERGE-SORT
#include<stdio.h>

void sort(int A[],int low,int high);
void merge(int A[],int L1,int H1,int L2,int H2);

int main() {
    int A[30],n,i;
    printf("Enter no of elements : ");
    scanf("%d", &n);
    printf("Enter %d array elements : ", n);
    for(i=0; i<n; i++) {
        scanf("%d", &A[i]);
    }
    sort(A,0,n-1);
    printf("\nSorted array : ");
    for(i=0; i<n; i++) {
        printf("%d ", A[i]);
    }
    return(0);
}
void sort(int A[],int low,int high) {
    int mid;
    if(low < high) {
        mid=(low+high)/2;
        sort(A,low,mid); //LEFT RECURSION
        sort(A,mid+1,high); //RIGHT RECURSION
        merge(A, low, mid, mid+1, high); //MERGING OF TWO SORTED SUB ARRAYS
    }
}
void merge(int A[],int L1,int H1,int L2,int H2) {
    int temp[50]; //ARRAY USED FOR MERGING
    int i,j,k;
    i=L1; //BEGINNING OF THE FIRST LIST
    j=L2; //BEGINNING OF SECOND LIST
    k=0;
    while(i<=H1 && j<=H2) {
        if(A[i]<A[j]) {
            temp[k++]=A[i++];
        }
        else {
            temp[k++]=A[j++];
        }
    }
    while(i<=H1) { //COPY REMAINING ELEMENTS OF 1ST LIST
        temp[k++]=A[i++];
    }
    while(j<=H2) { //COPY REMEINING ELEMENTS OF SECOND LIST
        temp[k++]=A[j++];
    }
    //TRANSFERING SORTED ARRAY FROM TEMP, BACK TO ORIGINAL
    for(i=L1,j=0;i<=H2;i++,j++) {
        A[i]=temp[j];
    }
}
