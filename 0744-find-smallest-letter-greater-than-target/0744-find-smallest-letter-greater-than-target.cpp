class Solution {
public:
    char nextGreatestLetter(vector<char>& arr, char x) {
  int l = 0, r = arr.size()-1;
    int ans = arr[0];
    while (l <= r) {
        int mid = (l+r)/2;
        if (arr[mid] >x) {
            ans = arr[mid];
         r=mid-1;
        } else {
            l=mid+1;
        }
    }
    return ans;
    }
};