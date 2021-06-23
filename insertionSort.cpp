#include<iostream>
#include<vector>
#include<time.h>

using namespace std;


int main() {
 
    srand(time(NULL));
    int numElements = rand()%10+1;
    vector<int> arr(numElements);

    cout << "[ " ;
    for (int iter = 0; iter < numElements; iter++){
        arr[iter] = rand()%50-25;
        cout << arr[iter] << " ";
    } cout << "] ";

    for (int iter = 1; iter < numElements; iter++) {
        int i = iter, j = iter-1;
        while (arr[i] < arr[j] && j >= 0) {
            int temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
            j -= 1;
            i -= 1;
        }
    }

    cout << endl << endl << "[ " ;
    for (int iter = 0; iter < numElements; iter++){
        cout << arr[iter] << " ";
    } cout << " ] ";

 
    return 0;
}