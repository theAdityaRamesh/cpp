#include<iostream>
#include<math.h>
#include<vector>
#include<time.h>
#include<algorithm>
#include<string>

using namespace std;
        
template<typename T>
class Heap {

    private:
        int heapSize = 0;
        vector<T> maxHeap;


    public:
    Heap(vector<T>& arr){
        heapSize = arr.size();
        maxHeap = arr;
    }
    // getters 
    T getElement(int indx){
        return maxHeap[indx];
    }

    int getHeapSize(){
        return heapSize;
    }

    int getParent(int indx){
        return floor(indx/2);
    }

    int getLeftChild(int indx){
        return 2*(indx+1)-1;
    }

    int getRightChild(int indx){        
        return 2*(indx+1);
    }

    //methods

    void printHeap(){

        cout << endl << endl ;

        int height = floor(log2(heapSize));
        int level = 0;

        while(level  < height+1){
            int i = pow(2,level)-1;
            while(i < (pow(2,level+1)-1) && i < heapSize){
                cout << maxHeap[i] << " " ;
                i += 1; 
            } cout << endl;

            level += 1;
        }

        cout << endl << endl ;
    }

    void maxHeapify(int indx){
        int left = getLeftChild(indx);
        int right = getRightChild(indx);
        int maxIndx = indx;

        if(maxHeap[left] > maxHeap[indx] && left < heapSize){
            maxIndx = left;
        }
        if (maxHeap[right] > maxHeap[indx] && maxHeap[right] > maxHeap[left] && right < heapSize){
            maxIndx = right;
        } 

        if(maxIndx != indx){
            swap(maxHeap[indx],maxHeap[maxIndx]);
            maxHeapify(maxIndx);
        }
    }

    void buildMaxHeap(){
       
        for(int i = floor(heapSize/2)-1;i != -1;i--){ 
            maxHeapify(i);
        } 
    }

    T extractMax(){
        T max = maxHeap[0];
        T last = maxHeap[heapSize-1];
        maxHeap[0] = last;
        heapSize -= 1;
        maxHeapify(0);

        return max;
    }
    
    vector<T> heapSort() {
        vector<T> sortedArr(maxHeap.begin(), maxHeap.end()); 
                
        for(int i = heapSize-1; i != -1; i--){
            sortedArr[i] = extractMax();
        }  
        return sortedArr;    
    }


};


int main(int argc, char const *argv[])
{   
    // random generation 	
    srand(time(NULL));
    int numElements = rand()%1000+1;
    vector<float> arr(numElements);
    
    int numTest = pow(10,3);
    

    for(int testCase = 0;testCase < numTest; testCase++){

        cout << testCase << endl ;

        // populate array
        for (int iter = 0; iter < numElements; iter++){
            arr[iter] = rand()%500-250 + (rand()%500)/pow(10,4);  
        } 

        vector<float> test = arr;
        sort(test.begin(),test.end());

        // sort the array
        Heap<float> h(arr);
        h.buildMaxHeap();
        arr = h.heapSort();

        // compare results
        for (int iter = 0; iter < numElements; iter++){
                if(arr[iter] != test[iter] ){
                    cout << "Error" << endl;
                    break;
                } 
            }

     
    }
}
