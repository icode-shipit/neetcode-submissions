class Solution {
public:
    int brightestPosition(vector<vector<int>>& lights) {
        map<int,int> m; //first->pos, second-> +1 or -1
        for(int i=0;i<lights.size();i++)
        {
            m[lights[i][0]-lights[i][1]]+=1;
            m[lights[i][0]+lights[i][1]+1]-=1;
        }
        int pos=0; int max_bright=0; int curr_bright=0;
        for(auto it=m.begin();it!=m.end();it++)
        {
            curr_bright+=it->second;
            if(curr_bright>max_bright) 
            {
                pos=it->first;
                max_bright=curr_bright;
            }
        }
        return pos;
    }
};
