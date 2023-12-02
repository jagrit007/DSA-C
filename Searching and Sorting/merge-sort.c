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
    int i=lb, j=mid+1, k=lb, temp[MAXSIZE];
    while(i <=mid && j<=ub){
        if(arr[i] <= arr[j]){
            temp[k++] = arr[i];
            i++;
        }
        else{
            temp[k++] = arr[i];
            i++;
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
    // copy to original array
    for(k= lb; k<=ub; k++){
        arr[k] = temp[k];
    }
}


int main(){
    int arr[] = {3,6,2,46,64,363,64,763,215,93,385,83,92,65};
    mergeSort(arr, 0, 13);
    for(int i=0; i<=13; i++){
        printf("%d\t\t", arr[i]);
    }
    return 0;
}