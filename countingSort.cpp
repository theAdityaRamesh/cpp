#include<iostream>
#include<vector>
#include<algorithm>
#include<time.h>
#include<utility>
#include<math.h>

using namespace std;

// countingSort

vector<int> countingSort(const vector<int>& arr){

    int max = *(max_element(arr.begin(), arr.end()));
    int min = *(min_element(arr.begin(), arr.end()));
    int range = abs(max-min)+1;
    int offset = min<0 ? -min : 0;
    vector<int> count(range,0);
    vector<int> sortedArr(arr.size(),0);

    // count each element in original array
    for(vector<int>::const_iterator head = arr.begin(); head != arr.end(); head++){
        count[*(head)+offset] += 1;          
    }

    // find relative position
    for(vector<int>::iterator head = count.begin()+1; head!= count.end(); head++){
        *head += *(head-1);
    }

    // sort array;
    vector<int>::iterator count_head = count.begin();
    for(vector<int>::const_iterator head = arr.begin(); head != arr.end(); head++){
        // find realtive position
        int relPos = *(count_head + *head + offset);
        
        // put number in relPos and subtract the offset
        sortedArr[relPos-1] = *head ;

        // decrement relPos
        *(count_head + *head + offset) -= 1;
    }

    return sortedArr;

}


int main(int argc, char const *argv[])
{

    // repeat the process for random arrays
    for(int testCases = 0; testCases != pow(10,3); testCases++){
        // current test case #
        cout << testCases << endl;

        // generate and populate random array 
        srand(time(NULL));
        int numElements = rand()%100+2;
        vector<int> arr(numElements);
        for (int iter = 0; iter < numElements; iter++){
            arr[iter] = rand()%500-250;
        } 

        // sort using counting sort
        vector<int> count ;
        count =  countingSort(arr);
        
        // sort using inbuilt sort
        sort(arr.begin(),arr.end());

        for(pair<vector<int>::iterator, vector<int>::iterator> 
            key(arr.begin(), count.begin());
                key.first != arr.end(); key.first++, key.second++ ){
            if(*key.first != *key.second){
                cout << "Error" << endl;
                break;
            }
        }
        
    }

    return 0;
}
