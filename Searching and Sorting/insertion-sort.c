#include <stdio.h>
#include <stdlib.h>

void insertionSort(int arr[], int size){
    int j=0, temp=0;
    for(int i=1; i<=size; i++){
        j = i-1;
        temp = arr[i];
        while(temp < arr[j] && j>=0){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
    
}

int main(){
    int arr[] = {3,2,91,55,5,4,7,9,34,92,0,-3};
    int size = (sizeof(arr)/sizeof(arr[0]))-1;
    printf("%d\n\n\n", size);
    insertionSort(arr, size);
    for(int i=0; i<=size; i++){
        printf("%d\t", arr[i]);
    }
    return 0;
}