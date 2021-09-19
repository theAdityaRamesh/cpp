#include<iostream>
#include<unordered_map>
#include<string>
#include<vector>

using std::vector;
using std::cout;
using std::string;
using std::endl;

class palindromeSeed
{
private:
    string palin = "";
    int size = 0;
    int start = -1;
public:
    palindromeSeed(string p, int st, int si) {
        palin = p;
        size = si;
        start = st;
    }
    ~palindromeSeed() {}

    string getPalin(){
        return palin;
    }

    int getSize() {
        return size;
    }

    int getStart() {
        return start;
    }
};

string getLargestPalindrome(const string& arr, palindromeSeed* seed){

    string largestPalindrome = seed->getPalin();
    int startIndx = seed->getStart();
    int endIndx = startIndx + seed->getSize()-1;

    if(startIndx == 0 || endIndx == (arr.size()-1)){
        return largestPalindrome;
    } else{
        startIndx -= 1;
        endIndx += 1;
        
        while (arr[startIndx] == arr[endIndx] && startIndx > -1 && endIndx < arr.size()){ 
            largestPalindrome = (arr[startIndx] + largestPalindrome + arr[endIndx]);
            startIndx -= 1;
            endIndx += 1;
        }
    
        return largestPalindrome;
    }

    return NULL;
}


int main(int argc, char const *argv[])
{
    string test = "aabbccddeedd";
    vector<palindromeSeed*> seedArray;
    palindromeSeed* seedPointer = nullptr;
    

    for(int it = 0; it != (test.size()-1); it++ ){

            if(test[it] == test[it+1] ){
                seedPointer = new palindromeSeed(test.substr(it,2), it, 2);
                seedArray.push_back(seedPointer);
            } 

            if(it < (test.size()-2) && test[it] == test[it+2]){
                seedPointer = new palindromeSeed(test.substr(it,3), it, 3);
                seedArray.push_back(seedPointer);
            } 
    }

    string largestPalindrome = "";
    int maxSize = 0;

    for(vector<palindromeSeed*>::iterator it = seedArray.begin(); it != seedArray.end(); it++){
        
        string temp = getLargestPalindrome(test, (*it));
        if(temp.size() > maxSize){
            largestPalindrome = temp; 
            maxSize = largestPalindrome.size();
        } 
    }

    cout << largestPalindrome << endl;
    



    return 0;
}
