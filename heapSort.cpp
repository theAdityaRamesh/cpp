#include<iostream>
#include<math.h>
#include<vector>
#include<time.h>
#include<algorithm>

using namespace std;

// max heap implementation

    //variables
        //heap size    

    //getters
        // get parent
        // get left child
        // get right child
        // get heap size
        // get node
        // get heap maximum
    
    // setters

    // methods
        // max heapify (i)
        // build max-heap
        // heap sort
        // insert into heap
        // remove from heap
        // heap extract max
        // heap increase key

        
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
        return ((indx+1)<<1)-1;
    }

    int getRightChild(int indx){        
        return (indx+1)<<1;
    }

    //methods

    void printMaxHeap(){
        
    }

    void maxHeapify(int indx){
        int left = getLeftChild(indx);
        int right = getRightChild(indx);
        int maxIndx = indx;

        if(maxHeap[left] > maxHeap[indx] && left < heapSize){
            maxIndx = left;
        } else if (maxHeap[right] > maxHeap[indx] && right < heapSize){
            maxIndx = right;
        } 

        if(maxIndx != indx){
            swap(maxHeap[indx],maxHeap[maxIndx]);
            maxHeapify(maxIndx);
        }
    }
    
};


int main(int argc, char const *argv[])
{   
    vector<int> arr;
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(-5);
    arr.push_back(10);

    Heap<int> maxHeap(arr);
    cout << maxHeap.getHeapSize() << endl;
    maxHeap.maxHeapify(0);
    return 0;
}
