class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {

        int n = heights.size();

        vector<int> left(n);
        vector<int> right(n);

        // Nearest Smaller to Left
        stack<pair<int,int>> st1;

        for(int i = 0; i < n; i++) {

            if(st1.size() == 0) {
                left[i] = -1;
            }
            else if(st1.size() > 0 && st1.top().first < heights[i]) {
                left[i] = st1.top().second;
            }
            else if(st1.size() > 0 && st1.top().first >= heights[i]) {

                while(st1.size() > 0 && st1.top().first >= heights[i]) {
                    st1.pop();
                }

                if(st1.size() == 0) {
                    left[i] = -1;
                }
                else {
                    left[i] = st1.top().second;
                }
            }

            st1.push({heights[i], i});
        }

        // Nearest Smaller to Right
        stack<pair<int,int>> st2;

        for(int i = n - 1; i >= 0; i--) {

            if(st2.size() == 0) {
                right[i] = n;
            }
            else if(st2.size() > 0 && st2.top().first < heights[i]) {
                right[i] = st2.top().second;
            }
            else if(st2.size() > 0 && st2.top().first >= heights[i]) {

                while(st2.size() > 0 && st2.top().first >= heights[i]) {
                    st2.pop();
                }

                if(st2.size() == 0) {
                    right[i] = n;
                }
                else {
                    right[i] = st2.top().second;
                }
            }

            st2.push({heights[i], i});
        }

        int maxi = 0;

        for(int i = 0; i < n; i++) {

            int width = right[i] - left[i] - 1;

            int area = heights[i] * width;

            maxi = max(maxi, area);
        }

        return maxi;
    }
};