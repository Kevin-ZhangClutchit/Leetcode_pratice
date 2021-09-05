#include <iostream>
#include <vector>
using namespace std;
//#733 Flood Fill
//DFS 1
vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
    int current_color=image[sr][sc];
    if (current_color==newColor){
        return image;
    }
    image[sr][sc]=newColor;
    //left
    if (sr>=1&&image[sr-1][sc]==current_color){
        floodFill(image,sr-1,sc,newColor);
    }
    //right
    if (sr<=image.size()-2&&image[sr+1][sc]==current_color){
        floodFill(image,sr+1,sc,newColor);
    }
    //top
    if (sc<=image[0].size()-2&&image[sr][sc+1]==current_color){
        floodFill(image,sr,sc+1,newColor);
    }
    //down
    if (sc>=1&&image[sr][sc-1]==current_color){
        floodFill(image,sr,sc-1,newColor);
    }
    return image;
}
//DFS 2
void floodFill_DFS(vector<vector<int>>& image, int sr, int sc, int newColor,int curr_col) {
    if (curr_col==newColor){
        return;
    }
    if (sr<0||sc<0||sr>=image.size()-1||sc>=image[0].size()-1||image[sr][sc]==newColor||image[sr][sc]!=curr_col){
        return;
    }else{
        image[sr][sc]=newColor;
        floodFill_DFS(image,sr-1,sc,newColor,curr_col);
        floodFill_DFS(image,sr+1,sc,newColor,curr_col);
        floodFill_DFS(image,sr,sc+1,newColor,curr_col);
        floodFill_DFS(image,sr,sc-1,newColor,curr_col);

    }
}


//695 Max Area of Island
//DFS 1
int AreaCal_DFS(vector<vector<int>>& grid,int sr,int sc){
    if (sr<0||sc<0||sr>=grid.size()||sc>=grid[0].size()||grid[sr][sc]==0){
        return 0;
    }else {
        grid[sr][sc]=0;
        int answer=1;
        answer+=AreaCal_DFS(grid,sr-1,sc);
        answer+=AreaCal_DFS(grid,sr+1,sc);
        answer+=AreaCal_DFS(grid,sr,sc-1);
        answer+=AreaCal_DFS(grid,sr,sc+1);
        return answer;
    }
}
//DFS 2
int AreaCal_DFS2(vector<vector<int>>& grid,int sr,int sc){
    grid[sr][sc]=0;
    int answer=1;
    //left
    if (sr>=1&&grid[sr-1][sc]==1){
        answer+=AreaCal_DFS2(grid,sr-1,sc);
    }
    //right
    if (sr<=(int)grid.size()-2&&grid[sr+1][sc]==1){
        answer+=AreaCal_DFS2(grid,sr+1,sc);
    }
    //top
    if (sc<=(int)grid[0].size()-2&&grid[sr][sc+1]==1){
        answer+=AreaCal_DFS2(grid,sr,sc+1);
    }
    //down
    if (sc>=1&&grid[sr][sc-1]==1){
        answer+=AreaCal_DFS2(grid,sr,sc-1);
    }
    return answer;
}
int maxAreaOfIsland(vector<vector<int>>& grid) {
    int result=0;
    if (grid.empty()){return result;}
    else{
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j]==1){
                    result=max(result,AreaCal_DFS2(grid,i,j));
                }
            }
        }
    }
    return result;
}
int main() {
    vector<vector<int>> image;
    vector<int> v1={1,1,1};
    vector<int> v2={1,1,0};
    vector<int> v3={1,0,1};

    image.emplace_back(v1);
    image.emplace_back(v2);
    image.emplace_back(v3);
    floodFill(image,1,1,2);

    vector<vector<int>> grid;
    vector<int> g1={1};
    grid.emplace_back(g1);
    maxAreaOfIsland(grid);
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
