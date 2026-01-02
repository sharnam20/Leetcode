class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int tar) {
        sort(nums.begin(),nums.end());
        int n= nums.size();
        vector<vector<int>>ans;
        for(int i=0;i<n;i++){
             if(i>0 && nums[i]==nums[i-1]) continue;
            for(int j=i+1;j<n; j++){
                   if(j>i+1 && nums[j]==nums[j-1]) continue;
                   int p=j+1;
                   int k=n-1;
                while(p<k){
                    long long  sum = (long long)nums[i]+ (long long)nums[j]+ (long long)nums[p]+ (long long)nums[k];

                    if(sum<tar) p++;
                    else if(sum>tar) k--;
                    else{
                        ans.push_back({nums[i],nums[j],nums[p],nums[k]});
                        p++;k--;
                        while(p<k && nums[p]==nums[p-1]) p++;
                        while(p < k && nums[k] == nums[k+1]) k--;
                    }
                }
                
                
            }
        }
        return ans;
    }
};