class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.length();
        int index = 0;

        if (n == 0) {
            return true;
        }

        // Step 1: remove special characters and spaces
        for (int i = 0; i < n; i++) {
            if (isalnum(s[i])) {
                s[index] = tolower(s[i]);
                index++;
            }
        }

        // resize string after cleaning
        s.resize(index);

        // Step 2: palindrome check
        int i = 0;
        int j = s.length() - 1;

        while (i <= j) {
            if (s[i] != s[j]) {
                return false;
            }
            i++;
            j--;
        }

        return true;
    }
};
