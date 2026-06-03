class TrieNode {
public:
    bool isWord = false;
    TrieNode* children[26] = {nullptr};
};

class Solution {
public:
    // Helper function to insert a word into the Trie
    void insert(TrieNode* root, const string& word) {
        TrieNode* curr = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!curr->children[idx]) {
                curr->children[idx] = new TrieNode();
            }
            curr = curr->children[idx];
        }
        curr->isWord = true;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        TrieNode* root = new TrieNode();
        
        // 1. Build the prefix tree
        for (const string& word : wordDict) {
            insert(root, word);
        }

        // 2. dp[i] means s[0...i-1] can be successfully segmented
        vector<bool> dp(n + 1, false);
        dp[0] = true; // Base case: empty prefix is always valid

        // 3. Iterative DP matching using the Trie
        for (int i = 0; i < n; i++) {
            // If the prefix up to index 'i' cannot be segmented, 
            // we can't start a new word from here.
            if (!dp[i]) continue; 

            TrieNode* curr = root;
            // Look ahead from index 'i' to find all valid words matching s[i...j]
            for (int j = i; j < n; j++) {
                int idx = s[j] - 'a';
                
                // Early Break Optimization: 
                // If this path doesn't exist in the Trie, stop checking further!
                if (!curr->children[idx]) break; 

                curr = curr->children[idx];
                
                // If we found a valid dictionary word ending at index 'j'
                if (curr->isWord) {
                    dp[j + 1] = true;
                }
            }
        }

        return dp[n];
    }
};