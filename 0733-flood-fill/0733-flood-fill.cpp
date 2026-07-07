class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size();
        int m=image[0].size();
        int row[]={1,0,-1,0};
        int col[]={0,1,0,-1};
        int old=image[sr][sc];
        if(old==color){
            return image;
        }
        queue<pair<int,int>>q;
        q.push({sr,sc});
        image[sr][sc]=color;
        while(!q.empty()){
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            for(int k=0;k<4;k++){
                int a=x+row[k];
                int b=y+col[k];
                if(a>=0&&a<n&&b>=0&&b<m&&image[a][b]==old){
                    image[a][b]=color;
                    q.push({a,b});
                }
            }
        }
        return image;

    }
};