#include<stdio.h>
#include<stdlib.h>


void swap(int arr[], int a, int b){
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

int partition(int arr[], int lb, int ub){
    int pivot = arr[lb];
    int start = lb;
    int end = ub;

    while(start<end){
        while(arr[start] <= pivot){
            start++;
        }
        while(arr[end] > pivot){
            end--;
        }
        if(start<end){
            swap(arr, start, end);
        }
    }
    swap(arr, lb, end);
    return end;
}

void quickSort(int arr[], int lb, int ub){
    if(lb<ub){
        int end = partition(arr, lb, ub);
        quickSort(arr, lb, end-1);
        quickSort(arr, end+1, ub);
    }
}


int main(){
    int a[]= {5,8,1,7,3,4,9,3,8,31,10,13,2,6};
    quickSort(a, 0, 13);
    for(int i=0; i<=13; i++){
        printf("%d\t\t", a[i]);
    }
    return 0;
}