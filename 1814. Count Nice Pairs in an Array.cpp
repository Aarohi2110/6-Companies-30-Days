class Solution {
public:
    int countNicePairs(vector<int>& nums) {
       map<int,int> mp;
       int mod=1e9 +7,diff,res=0;
       for(int i=nums.size()-1;i>=0;i--){
           diff=nums[i]-reverse(nums[i]);
           if(mp.count(diff)==true)
                res=(res+ mp[diff])%mod;
           mp[diff]++;     
       } 
       return res;
    }
private:
int reverse(int n){
    int ans=0;
while(n!=0){
    ans=(ans*10)+n%10;
    n=n/10;
}
return ans;
}

};
