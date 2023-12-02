#include<stdio.h>
#include<stdlib.h>

void Radixsort(int a[], int n)  {
    int bucket[10][10], buck[10];
    int div = 1, MaxNumOfDigits = 0;

    //find largest element
    int large = a[0];
    for(int i=0; i<=n; i++) {
        if( a[i] > large)
	    large = a[i];
    }


    // find Max Number Of Digits in largest number
    while ( large > 0 )   {
        MaxNumOfDigits++;
        large = large / 10; 
    }

    for(int pass=0; pass < MaxNumOfDigits; pass++) {

        // initialize buck with zeros
        for (int k=0; k <10; k++)
            buck[k] = 0;
        
        for(int i=0; i<=n; i++)  {
            int l= (a[i]/div) % 10;
            // printf("%d\n\n", l);
            bucket[l][buck[l]++] = a[i]; 
        }
        // collect back into original array for next pass
        int i=0;
        for(int k=0; k<10; k++)  {
            for(int j=0; j< buck[k]; j++) 	
                a[i++] = bucket[k][j];  
        }
        div=div*10;
        
    }
}


int main(){
    int arr[] = {3,6,2,46,64,93,83,92,73,65};
    int size = (sizeof(arr)/sizeof(arr[0]))-1;
    Radixsort(arr, size);
    for(int i=0; i<=size; i++){
        printf("%d\t\t", arr[i]);
    }
    return 0;
}