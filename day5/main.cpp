#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

bool isValidSudoku(vector<vector<char>>& board) {
    for (int i = 0; i < board.size(); ++i) {
        unordered_set<char> row_check;
        unordered_set<char> column_check;
        unordered_set<char> grid_check;
        for (int j = 0; j < board.size(); ++j) {
            if (board[i][j]!='.'&&row_check.count(board[i][j])==1){
                return false;
            }
            if (board[j][i]!='.'&&column_check.count(board[j][i])==1){
                return false;
            }
            int x=(i%3)*3+j%3;//(which level in the three left to right levels)+(which level in the three small levels in one big level)
            int y=(i/3)*3+j/3;//(which level in the three up to down levels)+(which level in the three small levels in one big level)
            if (board[x][y]!='.'&&grid_check.count(board[x][y])==1){
                return false;
            }
            row_check.insert(board[i][j]);
            column_check.insert(board[j][i]);
            grid_check.insert(board[x][y]);


        }

    }
    return true;
}
//O(M+N)
void setZeroes(vector<vector<int>>& matrix) {
    int m=matrix.size();
    int n=matrix[0].size();
    vector<int> signal(m+n,0);
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (matrix[i][j]==0){
                signal[i]=1;
                signal[m+j]=1;
            }
        }
    }

    for (int i = 0; i < signal.size(); ++i) {
        if (signal[i]==1&&i<m){
            for (int j = 0; j < n; ++j) {
                matrix[i][j]=0;
            }
        }
        if (signal[i]==1&&i>=m){
            for (int j = 0; j < m; ++j) {
                matrix[j][i-m]=0;
            }
        }
    }
}

//O(1)
void setZeroes2(vector<vector<int>>& matrix){
    bool first_row_clear= false,first_column_clear= false;
    int m=matrix.size();
    int n=matrix[0].size();
    for (int i = 0; i < m; ++i) {
        if (matrix[i][0]==0){
            first_column_clear=true;
            break;
        }
    }
    for (int i = 0; i < n; ++i) {
        if (matrix[0][i]==0){
            first_row_clear= true;
            break;
        }
    }
    for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
            if (matrix[i][j]==0){
                matrix[i][0]=0;
                matrix[0][j]=0;
            }
        }
    }
    //why no need to set start from 0? as the two flags before ensure that matrix[0][0] has been considered.
    for (int i = 1; i < m; ++i) {
        if (matrix[i][0]==0){
            for (int j = 0; j < n; ++j) {
                matrix[i][j]=0;
            }
        }
    }
    for (int i = 1; i <n ; ++i) {
        if (matrix[0][i]==0){
            for (int j = 0; j < m; ++j) {
                matrix[j][i]=0;
            }
        }
    }
    if (first_row_clear){
        for (int i = 0; i < n; ++i) {
            matrix[0][i]=0;
        }
    }

    if(first_column_clear){
        for (int i = 0; i < m; ++i) {
            matrix[i][0]=0;
        }
    }
}

int main() {

    return 0;
}
