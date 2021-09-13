#include <iostream>
#include <vector>
#include <queue>
using namespace std;
//#542 01 Matrix
vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    size_t r=mat.size();
    size_t c=mat[0].size();
    if (r==0||c==0){
        return mat;
    }
    queue<std::pair<size_t,size_t>> q;
    for (size_t i = 0; i < r; ++i) {
        for (size_t j = 0; j < c; ++j) {
            if (mat[i][j]==0){
                q.push(std::make_pair(i,j));
            }
        }
    }
    if (q.size()==r*c){return mat;}
    vector<vector<int>>result(r,vector<int>(c,0));
    size_t dis=0;
    while (!q.empty()){
        dis++;
        size_t size=q.size();
        while (size>0){
            std::pair<size_t,size_t> point=q.front();
            q.pop();
            size_t y=point.first;
            size_t x=point.second;

            //left
            if (y>=0&&y<r&&x>=1&&x<c+1){
                if (mat[y][x-1]==1){
                    mat[y][x-1]=0;
                    result[y][x-1]=dis;
                    q.push(std::make_pair(y,x-1));
                }
            }
            //right
            if (y>=0&&y<r&&x+1>=0&&x+1<c){
                if (mat[y][x+1]==1){
                    mat[y][x+1]=0;
                    result[y][x+1]=dis;
                    q.push(std::make_pair(y,x+1));
                }
            }
            //top
            if (y+1>=0&&y+1<r&&x>=0&&x<c){
                if (mat[y+1][x]==1){
                    mat[y+1][x]=0;
                    result[y+1][x]=dis;
                    q.push(std::make_pair(y+1,x));
                }
            }
            //down
            if (y>=1&&y<r+1&&x>=0&&x<c){
                if (mat[y-1][x]==1){
                    mat[y-1][x]=0;
                    result[y-1][x]=dis;
                    q.push(std::make_pair(y-1,x));
                }

            }
            size--;
        }
    }
    return result;
}

//#994 Rotting Oranges
int orangesRotting(vector<vector<int>>& grid) {
    if (grid.empty()||grid[0].empty()){
        return -1;
    }
    size_t r=grid.size();
    size_t c=grid[0].size();
    queue<std::pair<size_t,size_t>> rotten_q;
    int fresh_num=0;
    for (size_t i = 0; i < r; ++i) {
        for (size_t j = 0; j < c; ++j) {
            if (grid[i][j]==2){
                rotten_q.push(std::make_pair(i,j));
            }
            if (grid[i][j]==1){
                fresh_num++;
            }
        }
    }
    if (fresh_num==0){return 0;}
    int minute=0;
    while (!rotten_q.empty()){
        minute++;
        size_t size=rotten_q.size();
        while (size>0){
            std::pair<size_t,size_t> rotten_src=rotten_q.front();
            rotten_q.pop();
            size_t x=rotten_src.second;
            size_t y=rotten_src.first;
            if (y>=0&&y<r&&x>=1&&x<c+1){
                if (grid[y][x-1]==1){
                    grid[y][x-1]=2;
                    fresh_num--;
                    rotten_q.push(std::make_pair(y,x-1));
                }
            }
            //right
            if (y>=0&&y<r&&x+1>=0&&x+1<c){
                if (grid[y][x+1]==1){
                    grid[y][x+1]=2;
                    fresh_num--;
                    rotten_q.push(std::make_pair(y,x+1));
                }
            }
            //top
            if (y+1>=0&&y+1<r&&x>=0&&x<c){
                if (grid[y+1][x]==1){
                    grid[y+1][x]=2;
                    fresh_num--;
                    rotten_q.push(std::make_pair(y+1,x));
                }
            }
            //down
            if (y>=1&&y<r+1&&x>=0&&x<c){
                if (grid[y-1][x]==1){
                    grid[y-1][x]=2;
                    fresh_num--;
                    rotten_q.push(std::make_pair(y-1,x));
                }

            }
            size--;
        }
        if (fresh_num==0){
            return minute;
        }
    }
    return -1;
}
int main() {

    vector<vector<int>> mat2{2,vector<int>(1)};
    mat2[0]={0};
    mat2[1]={1};
    vector<vector<int>> res;
    res=updateMatrix(mat2);
    vector<vector<int>> grid(3,vector<int>(3));
    grid[0]={2,1,1};
    grid[1]={0,1,1};
    grid[2]={1,0,1};
    cout<<orangesRotting(grid)<<endl;
    return 0;
}
