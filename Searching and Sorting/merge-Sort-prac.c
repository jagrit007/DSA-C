#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 20

void mergeSort(int arr[], int lb, int ub){
    if(lb<ub){
        int mid = (lb+ub)/2;
        mergeSort(arr, lb, mid);
        mergeSort(arr, mid+1, ub);
        merge(arr, lb, mid, ub);
    }
}

void merge(int arr[], int lb, int mid, int ub){
    int i = lb;
    int j = mid+1;
    int k = 0; // temp array index
    int temp[MAXSIZE];

    while(i<=mid && j<=ub){
        if(arr[i] <= arr[j]){
            temp[k++] = arr[i++];
        }
        else{
            temp[k++] = arr[j++];
        }
    }
    if(i>mid){
        while(j<=ub){
            temp[k++] = arr[j++];
        }
    }
    else if(j>ub){
        while(i<=mid){
            temp[k++] = arr[i++];
        }
    }

    for(int z=lb; z<=ub; z++){
        arr[z] = temp[z];
    }
}



int main(){
    int arr[] = {3,6,2,46,64,93,83,92,65};
    int size = (sizeof(arr)/sizeof(arr[0]))-1;
    // printf("%d\t\t\t", size);
    mergeSort(arr, 0, size);
    for(int i=0; i<=size; i++){
        printf("%d\t\t", arr[i]);
    }
    return 0;
}