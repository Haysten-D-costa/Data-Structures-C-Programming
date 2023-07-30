#include <stdio.h>
#include <stdlib.h>
#define MAX 20

typedef struct myArray {  // 'myArray' (ABSTRACT DATA TYPES) structure template....

    int maxSize;  // max size limit assigned to ages array....
    int usedSize; // used size limit of ages array....
    int* ptr;     // memory-pointer to the assigned block of array, in heap....

}myArray;

void createArray(myArray* array_ptr, int mSize, int uSize); // function to create -ie- initialize an array....
void displayArray(myArray* array_ptr); // function to display -ie- show entries in array....
void setArray(myArray* array_ptr); // function to set -ie- initialize values in array....

// Operations : Insertion and Deletion etc....
void insert(myArray* array_ptr, int key);
void insertAtPosition(myArray* array_ptr, int key, int position); // TODO //
void delete(myArray* array_ptr); // TODO // 
void searchArray(myArray* array_ptr, int key);
void clear(myArray* array_ptr); // function to clear the array -ie- free the dynamically allocated memory from heap....

int main() {

    int n; // no. of age entries....
    printf("Enter no. of entries to be added to array : ");
    scanf("%d", &n);

    myArray ages;  // created an instance of myArray, named ages (ages points to the start of dynamically allocated memory in the heap)....
    createArray(&ages, MAX, n); // created an array of max size 'MAX', and used size 'n'....
    setArray(&ages); // setting values in ages array....
    displayArray(&ages); // displaying values in the set ages array....

    // int search; 
    // printf("\nEnter element to be searched : ");
    // scanf("%d", &search);
    // searchArray(&ages, search);
    insert(&ages, 10);
    insert(&ages, 20);
    // clear(&ages);
    // displayArray(&ages);

    clear(&ages);

    return 0;
}
void createArray(myArray* array_ptr, int mSize, int uSize) {  

    array_ptr-> maxSize = mSize;  
    array_ptr-> usedSize = uSize;

    // creating an array pointer of type 'myArray', pointing to first location of the alloted memory in heap....
    array_ptr-> ptr = (int *)malloc(mSize * sizeof(int)); // typecasting void type to int*, and allocating size worth { size = maxSize * sizeof(int) }, from heap....
}
void displayArray(myArray* array_ptr) {

    printf("\nArray :\t");
    for(int i=0; i<array_ptr->usedSize; i++) {
        printf("%d\t", (array_ptr->ptr)[i]);
    }
}
void setArray(myArray* array_ptr) {

    printf("\nEnter '%d' elements in array : ", array_ptr->usedSize);
    for(int i=0; i<array_ptr->usedSize; i++) {
        scanf("%d", &(array_ptr->ptr)[i]);
    }
}
void searchArray(myArray* array_ptr, int key) {
    
    int flag = 0; // to check if element not found....
    for(int i=0; i<array_ptr->usedSize; i++) {
        if((array_ptr->ptr)[i] == key) 
        {
            printf("\nElement found at index %d (position %d)", i, i+1);
            flag = 1;
        }
    }
    if(!flag) { printf("\nNo such element found !"); }
}
void insert(myArray* array_ptr, int key) { // similar to push operation....
    
    if(array_ptr->usedSize >= array_ptr->maxSize) {
        printf("\nOVERFLOW !");
        return;
    }
    (array_ptr->ptr)[array_ptr->usedSize] = key;
    array_ptr->usedSize += 1; 
}
void insertAtPosition(myArray* array_ptr, int key, int position) {
    // TODO //
}
void clear(myArray* array_ptr) { 
    free(array_ptr);
}