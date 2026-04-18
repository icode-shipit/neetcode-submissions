class Solution {
public:
    set<pair<int,int>> collectall(vector<vector<int>>& board)
    {
        set<pair<int,int>> s;
        int j=0;
        while(j<board[0].size()) // for each column check consecutive rows streak>=3
        {
            int i=0;
            while(i<board.size())
            {
                int streak=1;
                while(i<board.size()-1 && board[i][j] != 0 && board[i][j]==board[i+1][j]) 
                {
                i++;
                streak++;
                }
                int temp=i;
                if(streak>=3)
                { 
                    while(streak>0)
                    {
                        if(!s.contains({temp,j})) s.insert({temp,j});
                        streak--;
                        temp--;
                    }
                }
                i++;
            }
            j++;
        }
        int i=0;
        j=0;
        while(i<board.size()) // for each column check consecutive rows streak>=3
        {
            j=0;
            while(j<board[0].size())
            {
                int streak=1;
                while(j<board[0].size()-1 && board[i][j] != 0 && board[i][j]==board[i][j+1]) 
                {
                j++;
                streak++;
                }
                int temp=j;
                if(streak>=3)
                { 
                    while(streak>0)
                    {
                        if(!s.contains({i,temp})) s.insert({i,temp});
                        streak--;
                        temp--;
                    }
                }
                j++;
            }
            i++;
        }
        return s;
    }
    void clearreq(vector<vector<int>>& board,auto& s)
    {
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if(s.contains({i,j})) board[i][j]=0;
            }
        }
    }
    void settle(vector<vector<int>>& board) {
    int m = board.size();
    int n = board[0].size();
    
    // Process each column
    for (int c = 0; c < n; c++) {
        int lowestZero = -1;
        
        // Scan from bottom to top
        for (int r = m - 1; r >= 0; r--) {
            if (board[r][c] == 0) {
                lowestZero = max(lowestZero, r);
            } else if (lowestZero >= 0) {
                // Swap candy with the lowest zero
                swap(board[r][c], board[lowestZero][c]);
                lowestZero--;  // Next candy goes one row up
            }
        }
    }
}
    vector<vector<int>> candyCrush(vector<vector<int>>& board) {
        bool change=true;
        while(change)
        {
            change =false;
            auto s= collectall(board);
            if(!s.empty())
            {
               change=true;
               clearreq(board,s);
               settle(board);
            }
        }
        return board;
    }
};
