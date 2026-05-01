class Solution {
public:
    vector<int> mergesort(vector<int>& nums,int l,int r)
    {
        if(l==r)
        {
            return {nums[l]};
        }
        int mid=(l+r)/2;
        vector<int> lefthalf= mergesort(nums,l,mid);
        vector<int> righthalf= mergesort(nums,mid+1,r);
        // lets write comp each halves and building new arr logic 
        vector<int> res;
        int i=0; // points to lefthalf
        int j=0; //points to righthalf
        while(i<lefthalf.size() || j<righthalf.size())
        {
            if(i>=lefthalf.size()) 
            {
                res.push_back(righthalf[j]); j++;
            }
            else if(j>=righthalf.size())
            {
                res.push_back(lefthalf[i]); i++;
            }
            else
            {
                if(lefthalf[i]<righthalf[j])
                {
                   res.push_back(lefthalf[i]); i++;
                }
                else 
                {
                    res.push_back(righthalf[j]); j++;
                }
            }
        }
        return res;
    }
    vector<int> sortArray(vector<int>& nums) {
        return mergesort(nums,0,nums.size()-1);
    }
};