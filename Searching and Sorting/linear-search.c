#include<stdio.h>
#include<stdlib.h>



int linearSearch(int key, int arr[], int len){
    for(int i=0; i<len; i++){
        if(arr[i] == key){
            return i;
        }
    }
    return -1;
}

int main(){
    int arr[] = {4,7,9,12,15,17};
    int key = 15;
    printf("%d", linearSearch(key, arr, 6));
    return 0;
}