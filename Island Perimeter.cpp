//You are given a map in form of a two-dimensional integer grid where 1 represents land and 0 represents water.

//Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells).

//The island doesn't have "lakes" (water inside that isn't connected to the water around the island). One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.

 

//Example:

//Input:
//[[0,1,0,0],
// [1,1,1,0],
// [0,1,0,0],
// [1,1,0,0]]

//Output: 16


class Solution {
public:
    
    int surround(vector<vector<int>>& grid,int n,int m,int x,int y){
        if(x<0 or x>=n or y<0 or y>=m or grid[x][y]!=1) return 0;
        else return 1;
    }
    
    int islandPerimeter(vector<vector<int>>& grid) {
        int peri = 0;
        int n = grid.size();
        if(n==0) return 0;
        int m = grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    int k = surround(grid,n,m,i-1,j) + surround(grid,n,m,i+1,j) + surround(grid,n,m,i,j-1) + surround(grid,n,m,i,j+1); 
        
                    if(k == 1 ) peri+=3;
                    else if(k==2) peri+=2;
                    else if(k==3) peri+=1;
                    else if(k==0) peri+=4;
                
                }
            }
        }
        return peri;
    }
};