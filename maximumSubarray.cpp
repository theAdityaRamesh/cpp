#include<iostream>
#include<vector>
#include<time.h>

using namespace std;


vector<int> getMaxSubArray(const vector<int>& arr ){

    int maxSum=0;
    int startIndx=0;
    int endIndx=0;
    int tempSum=0;

    for(int i = 0; i < arr.size(); i++){
    
        tempSum += arr[i];

        if ( tempSum > 0 && tempSum > maxSum) {
            maxSum = tempSum;
            endIndx = i;
        }
        if ( tempSum < 0 && maxSum == 0) {
            tempSum = 0;
            startIndx = i+1;
            endIndx = i+1;
        }
    }

    vector<int> maxSubArr;
    for(int i = startIndx; i <endIndx+1 ; i++){
        maxSubArr.push_back(arr[i]);
    }

    return maxSubArr;
}


int main(int argc, const char** argv) {
 
    srand(time(0));
    
    vector<int> arr;

    cout << "[ ";
    for (int i = 0; i < (rand()%10+1); i++){
        arr.push_back(rand()%100-50);
        cout << arr[i] << " "; 
    }
    cout << " ]" << endl;

    vector<int> maxSubArray;
    maxSubArray = getMaxSubArray(arr);
    
    
    cout << endl << endl;
    cout << "[ ";
    for (int i=0; i < maxSubArray.size(); i++) {
        cout << maxSubArray[i] << " ";
    } cout << " ]" << endl;

    return 0;
}