class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        vector<vector<char>> ans(boxGrid[0].size(),vector<char>(boxGrid.size()));
        for(int i=0;i<boxGrid.size();i++)
        {
            int fallable_pos=-1;
            for(int j=boxGrid[0].size()-1;j>=0;j--)
            {
                if(boxGrid[i][j]=='.') fallable_pos=max(j,fallable_pos);
                else if(boxGrid[i][j]=='*') fallable_pos=-1;
                else
                {
                    if(fallable_pos!=-1) 
                    {
                        swap(boxGrid[i][j],boxGrid[i][fallable_pos]);
                        j=fallable_pos;
                        fallable_pos=-1;
                    }
                }
            }
        }
        for(int i=0;i<boxGrid.size();i++)
        {
            for(int j=0;j<boxGrid[i].size();j++)
            {
                ans[j][boxGrid.size()-i-1]=boxGrid[i][j];
            }
        }
        return ans;
    }
};