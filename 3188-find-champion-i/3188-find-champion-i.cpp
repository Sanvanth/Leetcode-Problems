class Solution {
public:
    int findChampion(vector<vector<int>>& grid) {
        int n=grid.size();
        int max=0,ans=0;
        for(int i=0;i<n;i++){
            int currMax=0;
            for(int j=0;j<n;j++){
                if(grid[i][j]==1) currMax++;
            }
            if(currMax>max){
                max=currMax;;
                ans=i;
            }
        }
        return ans;
    }
};