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
        } else {
            temp[curr] = arr[left];
            left += 1;
        }

        curr += 1;
    }


    vector<int>::iterator itTemp 
        = temp.begin() + curr;
    vector<int>::iterator itArr 
        = arr.begin() + right;

    if (right < (end + 1)){
        copy(itArr, arr.begin()+end+1, itTemp);
    }

    itArr = arr.begin() + left;

    if (left < (mid + 1)){
        copy(itArr, arr.begin()+mid+1, itTemp);
    }

    itArr = arr.begin() + start;
    copy(temp.begin(), temp.end(), itArr);


    return inv;
}

int getInversionsMergeSort(int start, int end, vector<int>& arr){

    int mid = 0, inv = 0;

    if( start < end){
        mid = (start + end)/2;
        inv = getInversionsMergeSort(start, mid, arr)
                 + getInversionsMergeSort(mid + 1, end, arr) +
                     merge(start, end, arr);      
    }

    return inv;
}


int main(int argc, const char** argv) {
 
    srand(time(NULL));
    int numTests = 20000;

    for (int test = 0; test < numTests; test++) {
    
        // initialize array
        int size = rand()%5000+ 1;
        int range = 50;
        vector<int> arr(size, 0);
    
        // populate array
        for (vector<int>::iterator i = arr.begin(); i < arr.end(); i++) {
            *i = rand()%range-(range/2);
        } 

        // test cases
        int invBF = getInversionsBruteForce(size, arr);
        int invMS = getInversionsMergeSort(0, size-1, arr);

        if ((invBF - invMS) != 0){
            cout << endl << endl  << "[ " ;
            for (vector<int>::iterator i = arr.begin(); i < arr.end(); i++) {
                cout << *i << " ";
            } cout << "]" << endl ;
            cout << invBF << " " << invMS ;
            break;
        }
        cout << test  << endl;
    }

    return 0;
}