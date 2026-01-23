class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int size = nums.size();
          int num =0;
        for(int i=0;i<size;i++){
          
            num=num^nums[i];
        }
        return num;
    }
        
    
};