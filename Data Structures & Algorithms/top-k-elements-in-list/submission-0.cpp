class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        vector<vector<int>> bucket(nums.size()+1); // idx of bucket maps to freq of elements in bucket[idx] in nums
        for(int i=0;i<nums.size();i++) m[nums[i]]++;
        for(auto it=m.begin();it!=m.end();it++)
        {
           bucket[it->second].push_back(it->first);
        }
        vector<int> ans;
        for(int i=bucket.size()-1;i>=0;i--)
        {
            vector<int>& ref=bucket[i];
            int j=0;
            while(j<ref.size() && ans.size()<k)
            {
                ans.push_back(ref[j]);
                j++;
            }
            if(ans.size()==k) return ans;
        }
        return ans;
    }
};