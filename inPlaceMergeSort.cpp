#include<iostream>
#include<vector>
#include<time.h>

using namespace std;


void merge(vector<int>& arr, int start, int end) {

    int mid = (start+end)/2;
    
    for (int i = mid+1; i < end+1; i++) {
        int prev = i-1;
        int next = i;
        while( arr[prev] > arr[next] && prev >= 0) {
            int temp = arr[prev];
            arr[prev] = arr[next];
            arr[next] = temp;
            prev -= 1;
            next -= 1;
        }
    }

    return;
}


void mergeSort(vector<int>& arr, int start, int end){

    if (start < end) {
        int mid = (start+end)/2;
        mergeSort(arr, start, mid);
        mergeSort(arr, mid+1, end);
        merge(arr, start, end);
    }

    return;
}

int main() {
    
    srand(time(NULL));
    int numElements = rand()%30+10;
    vector<int> arr(numElements,0);
    cout << "[";
    for (int iter = 0; iter < numElements; iter++) {
        arr[iter] = (rand()%50-25); 
        cout << arr[iter] << " ";
    } cout << "]" << endl;

    mergeSort(arr,0,numElements-1);

    cout << endl << endl << "[";
    for (int iter = 0; iter < numElements; iter++) {
        cout << arr[iter] << " ";
    } cout << "]" << endl;
        
    return 0;
}   