class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int row[]={0,1,-1,0};
        int col[]={1,0,0,-1};
        int count;
        int ans=0;
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    count=1;
                    q.push({i,j});  
                    grid[i][j]=0;                  
                }
                while(!q.empty()){
                    int a=q.front().first;
                    int b=q.front().second;
                    q.pop();
                    for(int k=0;k<4;k++){
                        int x=a+row[k];
                        int y=b+col[k];
                        if(x>=0&&x<n&&y>=0&&y<m && grid[x][y]==1){
                            q.push({x,y});
                            count++;
                            grid[x][y]=0;
                        }
                    }

                }
                ans=max(ans,count);
            }
        }
        return ans;
    }
};