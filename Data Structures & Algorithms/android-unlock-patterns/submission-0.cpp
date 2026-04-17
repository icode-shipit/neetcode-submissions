class Solution {
public:
    bool visited[3][3]={false};
    vector<pair<int,int>> temp;
    int ans=0;
    void backtracking(int r,int c,int m,int n)
    {
        if(temp.size()>=m) ans++;
        if(temp.size()==n) return;

        //lets find all possib next nodes for (r,c)
        vector<pair<int,int>> possib;
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                if(!visited[i][j])
                {
                   int d= max(abs(i-r),abs(j-c)); // dist bw points
                   if(d==1) possib.push_back({i,j});
                   else
                   {
                     if(i==r && j!=c) // same row with d>1
                     {
                        if(visited[i][(j+c)/2])
                        {
                            possib.push_back({i,j});
                        }
                     }
                     else if(i!=r && j==c) // same col with d>1
                     {
                        if(visited[(i+r)/2][j])
                        {
                            possib.push_back({i,j});
                        }
                     }
                     else if(abs(i-r)==abs(j-c))
                     {
                        if(visited[(i+r)/2][(j+c)/2])
                        {
                            possib.push_back({i,j});
                        }
                     }
                     else
                     {
                        possib.push_back({i,j}); 
                     }
                   }
                }
            }
        }
        // now we have all possib next nodes in seq
        for(int i=0;i<possib.size();i++)
        {
            temp.push_back({possib[i].first,possib[i].second});
            visited[possib[i].first][possib[i].second]=true;
            backtracking(possib[i].first,possib[i].second,m,n);
            temp.pop_back();
            visited[possib[i].first][possib[i].second]=false;
        }
        return;
    }
    int numberOfPatterns(int m, int n) {
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                temp.push_back({i,j});
                visited[i][j]=true;
                backtracking(i,j,m,n);
                visited[i][j]=false;
                temp.pop_back();
            }
        }
        return ans;
    }
};
