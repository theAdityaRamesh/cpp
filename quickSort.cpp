#include<iostream>
#include<vector>
#include<time.h>
#include<math.h>
#include<algorithm>

using namespace std;


template<class T>
int partition(vector<T>& arr,int head, int tail){

    T pivot = arr[tail];
    int indxPivot = head-1;

    for(int it = head; it < tail; it++ ){
        if(arr[it] < pivot){
            swap(arr[++indxPivot], arr[it]);
        } 
    } swap(arr[tail], arr[++indxPivot]);

    return indxPivot;
}


template <class T>
void quickSort(vector<T>& arr, int head, int tail){

    if(head < tail){
        int pivot = partition(arr, head, tail); 
        quickSort(arr, head, pivot-1);
        quickSort(arr, pivot+1, tail);
    }

}



int main(int argc, char const *argv[])
{
    


    // random generation 	
    srand(time(NULL));
    int numElements = rand()%100+1;
    vector<float> arr(numElements);
    vector<float> test = arr;
    int numTest = 2*pow(10,5);
    
    for(int testCase = 0;testCase < numTest; testCase++){

        cout << testCase << endl ;

        // cout << "[ " ;
        for (int iter = 0; iter < numElements; iter++){
            arr[iter] = rand()%500-250 + (rand()%500)/pow(10,4);
            // cout << arr[iter] << " ";
        }
        // cout << "] ";
        test = arr;
        sort(test.begin(), test.end());
        quickSort(arr,0,numElements-1);

    

        // cout << endl << endl << "[ " ;
        // for (int iter = 0; iter < numElements; iter++){
        //     cout << arr[iter] << " ";
        // } cout << " ] ";

        if(test != arr){
            cout << "Error";
            break;
        }
    }

    return 0;
}
