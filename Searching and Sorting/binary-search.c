#include<stdio.h>
#include<stdlib.h>

int binarySearch(int key, int arr[], int len){
       int l=0, r=len-1, mid=0;
       while(l<=r){
        mid = (l+r)/2;
        if(arr[mid] == key){
            return mid;
        }
        if(arr[mid] > key){
            r = mid - 1;
        }
        if(arr[mid] < key){
            l = mid + 1;
        }
       }
       return -1;
}


int main(){
    int arr[] = {3,5,7,10,13,15,17,19,24,28,29,45,53};
    int len = 13;
    int key = 10;
    printf("%d", binarySearch(key, arr, len));
    return 0;
}