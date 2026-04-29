class Solution {
public:
    int compress(vector<char>& chars) {
        int ans=0;
        int previdx=chars.size()-1;
        for(int i=chars.size()-1;i>=0;i--)
        {
            int streak=1;
            int j=i;
            while(j>0 && chars[j]==chars[j-1])
            {
                streak++;
                j--;
            }
            string temp;
            char c= chars[j];
            if(streak!=1) temp=to_string(streak);
            ans+=1+temp.size();
            chars.erase(chars.begin()+j,chars.begin()+previdx+1);
            string seg;
            seg.push_back(c); seg+=temp;
            chars.insert(chars.begin()+j,seg.begin(), seg.end());
            previdx=j-1;
            i=j;
        }
        return ans;
    }
};