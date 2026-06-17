class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=0;
        int maxisum=INT_MIN;
        int n=nums.size();
        for(int i=0;i<nums.size();i++){
            sum=sum+nums[i];
             maxisum=max(sum,maxisum);
            if(sum<0){
                sum=0;
            }
          
        }
        return maxisum;
    }
};