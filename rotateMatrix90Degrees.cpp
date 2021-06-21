#include<iostream>
#include<vector>
#include<time.h>

using namespace std;


void rotateBy90M2(vector<vector<int>>& mat){

    int n = mat.size();

    for (int i = 0; i < mat.size()/2; i++){
        for(int j = i; j<n-1-i; j++ ){

            int temp = mat[i][j];
            mat[i][j] = mat[j][n-1-j] ;
            mat[j][n-1-j] = mat[n-1-i][n-1-j];
            mat[n-1-i][n-1-j] = mat[n-1-j][i];
            mat[n-1-j][i] = temp;

        }
    }
   
    return;
}

void rotateBy90M1(vector<vector<int>>& mat){

    int numRow = mat.size();

    for(int iterRow = 0; iterRow < mat.size(); iterRow++){
        for(int iterCol = iterRow+1; iterCol < mat[0].size(); iterCol++){
            int temp = mat[iterRow][iterCol];
            mat[iterRow][iterCol] = mat[iterCol][iterRow];
            mat[iterCol][iterRow] = temp;
        }
    }

    for (int iterRow = 0; iterRow < mat.size()/2; iterRow++){
        for (int iterCol = 0; iterCol < mat[0].size(); iterCol++){
            int temp = mat[iterRow][iterCol];
             mat[iterRow][iterCol] = mat[numRow-1-iterRow][iterCol];
             mat[numRow-1-iterRow][iterCol] = temp;
        }
    }

    return;

}

int main(int argc, const char** argv) {
    
    srand(time(0));
    int numRow = 20, numCol = 20;

    vector<vector<int>> mat(numRow, vector<int> (numCol));
    

    for(int iterRow = 0; iterRow < numRow; iterRow++){
        for(int iterCol = 0; iterCol < numCol; iterCol++){
            mat[iterRow][iterCol] = rand()%10;
            cout << mat[iterRow][iterCol] << " " ;
        }
        cout << endl;
    }

    rotateBy90M2(mat);
    cout << endl << endl << endl; 

    for(int iterRow = 0; iterRow < numRow; iterRow++){
        for(int iterCol = 0; iterCol < numCol; iterCol++){
            cout << mat[iterRow][iterCol] << " " ;
        }
        cout << endl;
    }

    return 0;
}