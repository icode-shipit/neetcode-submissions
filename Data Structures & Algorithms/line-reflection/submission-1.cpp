class Solution {
public:
    bool isReflected(vector<vector<int>>& points) {
        set<pair<int,int>> s;
        int min_x=INT_MAX;
        int max_x=INT_MIN;
        for(auto& p: points)
        {
            min_x=min(min_x,p[0]);
            max_x=max(max_x,p[0]);
            s.insert({p[0],p[1]});
        }
        double target=(min_x+max_x);
        for(auto& p : points)
        {
            double ref=target-p[0];
            if(!s.contains({ref,p[1]})) return false;
        }
        return true;
    }
};
