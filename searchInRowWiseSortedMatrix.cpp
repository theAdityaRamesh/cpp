#include<iostream>
#include<time.h>
#include<algorithm>
#include<vector>

using namespace std;

bool binarySearchInRow(const vector<int>& mat, int query){

    int head = 0;
    int tail = mat.size() - 1;
    int mid ;
    int numCol = tail+1;
    

    while ( head <= tail) {

        mid = (head+tail)/2;

        if (query == mat[mid]){
            return true;
            
        } else if (query > mat[mid]) {

            head = mid + 1;

        } else {
            tail = mid - 1;
        }


    }

    return false;
}

bool binarySearch(const vector<vector<int>>& mat, int query){

    int head = 0;
    int tail = mat.size() - 1;
    int mid ;
    int numRow = mat.size();
    int numCol = mat[0].size();

    while ( head <= tail) {

        mid = (head+tail)/2;

        if (query >= mat[mid][0] && query <= mat[mid][numCol-1]){
            return binarySearchInRow(mat[mid],query);
        } else if (query > mat[mid][numCol-1]) {
            head = mid + 1;
        } else {
            tail = mid - 1;
        }

    }

    return false;
}



int main(int argc, const char** argv) {

    srand(time(0));

    int numRow = 5, numCol = 4;
    vector<vector<int>> mat(numRow, vector<int> (numCol));
    int cnt = 0;

    for (int i = 0; i < numRow; i++){
        for (int j = 0; j < numCol; j++){
            mat[i][j] = (rand()%20 + cnt);
        }
        sort (mat[i].begin(),mat[i].end());
        cnt = cnt + 40;
        cout << endl;
    }

    for (int i = 0; i < numRow; i++){
        for (int j = 0; j < numCol; j++){
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }

    int query;
    cin >> query ;
    cout << endl << endl;
    cout << binarySearch(mat,query) << endl;
    
    return 0;
}
