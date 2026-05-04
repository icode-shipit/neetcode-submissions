class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(), nums.end());
        
        int totalSum = 0;
        int left = 0;
        int maxFreq = 0;
        
        for (int right = 0; right < n; ++right) {
            totalSum += nums[right];

            while (nums[right] * (right - left + 1) > k + totalSum) {
                totalSum -= nums[left];
                left++;
            }
            
            maxFreq = max(maxFreq, right - left + 1);
        }
        
        return maxFreq;
    }
};