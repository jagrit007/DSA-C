#include<iostream>
using namespace std;

// void towerOfHanoi(int n, char src, char aux, char dest){
//     if(n>1){
//         towerOfHanoi(n-1, src, dest, aux);
//     }
//     cout<<src << " -> " << dest;
//     towerOfHanoi()
// }

void towerOfHanoi(int n, char src, char aux, char dest){
    if(n>0){
        towerOfHanoi(n-1, src, dest, aux);
        cout<<src << " -> " << dest << endl;
        towerOfHanoi(n-1, aux, src, dest);
    }
}

int main(){
    towerOfHanoi(4, 'A', 'B', 'C');
}