class Solution {
public:
    int maxArea(vector<int>& height) {
        int left=0;
        int right=height.size()-1;
        int maxiarea=INT_MIN;
        while(left<=right){
            int hight=min(height[left],height[right]);
            int length=abs(right-left);
             int area=hight*length;
             maxiarea=max(maxiarea,area);
             if(height[right]>height[left]){
                left++;
             }
             else{
                right--;
             }
        }
        return maxiarea;
    }
};