class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n+1,1);
        int max=1;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-1;i++) {
            for(int j=i+1;j<n;j++){
                if(nums[j]%nums[i]==0 && 1+dp[i]>dp[j]){
                    dp[j]= 1+dp[i];
                    if(max<dp[j])
                        max=dp[j];
                }
             }
        }
        cout<<max;
        int prev=-1;
        vector<int> ans;
        for(int i=n-1;i>=0;i--){
            if(dp[i]==max && (prev%nums[i]==0||prev==-1)){
                ans.push_back(nums[i]);
                max--;
                prev=nums[i];
            }    
        }
        return ans;
    }
};
