class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int i=0;
        int j=0;
        double sum=0;
        double maxi =-1e18;
        while(j<nums.size()){
            sum=sum+nums[j];
            if(j-i+1 < k){// make a window of length k
                j++;
            }
            else if(j-i+1==k){
                 maxi=max(sum,maxi);
                 sum=sum-nums[i];
                 i++;j++;
            }
        }
        return maxi/k;
    }
};