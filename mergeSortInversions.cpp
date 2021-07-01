#include<iostream>
#include<vector>
#include<time.h>

using namespace std;


int getInversionsBruteForce(int size,const vector<int>& arr){

    int inv = 0;

    for(int i = 0; i < size; i++){
        for (int j = i; j < size; j++ ){
            if (arr[i] > arr [j]){
                inv += 1;
            }
        }
    }

    return inv;
}


int merge(int start, int end, vector<int>& arr) {

    vector<int> temp(end-start+1,0);
    int mid = (start + end)/2;
    int inv = 0;
    int left = start;
    int right = mid+1;
    int curr = 0;

    while (left < (mid + 1) && right < (end + 1) ) {

        if (arr[left] > arr[right]) {
            inv += (mid-left+1);
            temp[curr] = arr[right];
            right += 1;
            curr += 1;
        } else {
            temp[curr] = arr[left];
            left += 1;
            curr += 1;
        }
    }

    while (right < (end + 1)){
        temp[curr] = arr[right];
        right += 1;
        curr += 1;
    }

    while (left < (mid + 1)){
        temp[curr] = arr[left];
        left += 1;
        curr += 1;
    }

    int j = 0;
    for (int i = start; i < end+1; i++) {
        arr[i] = temp[j];
        j+=1;
    }

    return inv;


}

int getInversionsMergeSort(int start, int end, vector<int>& arr){

    int mid = 0, leftInversions = 0, rightInversions = 0, inv = 0;

    if( start < end){
        mid = (start + end)/2;
        leftInversions = getInversionsMergeSort(start, mid, arr);
        rightInversions = getInversionsMergeSort(mid + 1, end, arr);
        inv = merge(start, end, arr) + leftInversions + rightInversions; 
        
    }

    return inv;
}


int main(int argc, const char** argv) {
 
    srand(time(NULL));
    int numTests = 20000;

    for (int test = 0; test < numTests; test++) {
    
        // initialize array
        int size = rand()%5+ 1;
        int range = 50;
        vector<int> arr(size, 0);
    
        // populate array
        for (int i = 0; i < size; i++) {
            arr[i] = rand()%range-(range/2);
        } 

        // test cases
        int invBF = getInversionsBruteForce(size, arr);
        int invMS = getInversionsMergeSort(0, size-1, arr);

        if ((invBF - invMS) != 0){
            cout << endl << endl  << "[ " ;
            for (int i = 0; i < size; i++) {
                cout << arr[i] << " ";
            } cout << "]" << endl ;
            cout << invBF << " " << invMS ;
            break;
        }
        cout << test  << endl;
    }

    return 0;
}