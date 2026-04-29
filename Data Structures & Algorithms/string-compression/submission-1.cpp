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
            char c= chars[j];
            chars.erase(chars.begin()+j,chars.begin()+previdx+1);
            string seg= streak!=1 ? string(1,c)+to_string(streak) : string(1,c);
            chars.insert(chars.begin()+j,seg.begin(), seg.end());
            previdx=j-1;
            i=j;
        }
        return chars.size();
    }
};