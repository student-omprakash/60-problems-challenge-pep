class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        
        int fresh=0,minute=0;
        queue<pair<int,int>>q;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
                else if(grid[i][j]==1){
                    fresh++;
                }
            }
        }
                // int arr[];
                while(!q.empty()&&fresh>0){
                    int s=q.size();
                    minute++;
                    while(s--){
                       
                   // arr[0]=q.front();
                    
                    int i=q.front().first;
                    int j=q.front().second;
                    q.pop();
                    if(j-1>=0&&grid[i][j-1]==1){
                        grid[i][j-1]=2;
                        fresh--;
                        q.push({i,j-1});
                    }
                    if(j+1<m&&grid[i][j+1]==1){
                        grid[i][j+1]=2;
                        fresh--;
                        q.push({i,j+1});
                    }
                    if(i-1>=0&&grid[i-1][j]==1){
                        grid[i-1][j]=2;
                        fresh--;
                        q.push({i-1,j});
                    }
                    if(i+1<n&&grid[i+1][j]==1){
                        grid[i+1][j]=2;
                        fresh--;
                        q.push({i+1,j});
                    }
                    }

                }

             
        return fresh>0 ? -1:minute;
    }
};