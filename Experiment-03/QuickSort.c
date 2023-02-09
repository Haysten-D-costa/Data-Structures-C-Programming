#include <stdio.h>

void quicksort(int A[], int low, int up);

int main() {
    int i, count, A[10];
    printf("Enter the number of elements in array : ");
    scanf("%d", &count);
    printf("\nEnter the elements in array : \n");
    for(i=0; i<count; i++)
        scanf("%d", &A[i]);
    printf("\nUnsorted array  : \n");
    for(i=0; i<count; i++)
        printf("%d ", A[i]);
    quicksort(A, 0, count-1);
    printf("\n\nSorted array : \n");
    for(i=0; i<count; i++)
        printf(" %d", A[i]);

    return(0);
}
void quicksort(int A[], int low, int up) {
    int start, end, pivot, temp;
    if(low < up) {
        pivot = low;
        start = low;
        end = up;
        while(start < end) {
            while((A[start] <= A[pivot])/* && (start < up)*/)
                start++;
            while(A[end] > A[pivot])
                end--;
            if(start < end) {
                temp = A[start];
                A[start] = A[end];
                A[end] = temp;
            }
        }
        temp = A[pivot];
        A[pivot] = A[end];
        A[end] = temp;
        quicksort(A, low, end-1);
        quicksort(A, end+1, up);
   }
}