#include <stdio.h>

void swap(int arr[], int a, int b){
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

void ShellSort(int arr[], int size) {

    for(int gap = size/2; gap>=1; gap/=2) {

        for(int j = gap; j<size; j++) {

            for(int i=j-gap; i>=0; i=-gap){
                if(arr[i+gap] < arr[i]){
                    swap(arr, i+gap, i);
                }
            }
            }
        }
    }

int main() {

    int a[] = { 303, 11, 55, 80, 13, 18, 22, 22 };

    for(int i=0; i<8; i++) {
        printf("%d ", a[i]);
    }

    ShellSort(a, 8);
    printf("\n");

    for(int i=0; i<8; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}