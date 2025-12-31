class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0;
        while(i < nums.size()-1){
            if(nums[i]==nums[i+1]){
                //cout<<"remove element is"<<i;
                nums.erase(nums.begin()+ i);
            }
            else{
                i++;
            }

        }
        int size=nums.size();
        // for(int i=0;i<size;i++){
        //     cout<<nums[i];
        // }
        return size;
    }
};