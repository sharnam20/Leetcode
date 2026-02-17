class Solution {
public:
    
    int findpalindrom(string &str, int st, int ed, vector<vector<int>> &dp) {
        if (st > ed) {
            return 0;
        }
        
        if (st == ed) {
            return 1;
        }
        
        if (dp[st][ed] != -1) {
            return dp[st][ed];
        }
        
        if (str[st] == str[ed]) {
            dp[st][ed] = 2 + findpalindrom(str, st + 1, ed - 1, dp);
        }
        else {
            dp[st][ed] = max(findpalindrom(str, st + 1, ed, dp),
                             findpalindrom(str, st, ed - 1, dp));
        }
        
        return dp[st][ed];
    }
    
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return findpalindrom(s, 0, n - 1, dp);
    }
};
