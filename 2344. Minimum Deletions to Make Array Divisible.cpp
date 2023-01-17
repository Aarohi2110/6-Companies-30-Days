class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        int ans=numsDivide[0],count=0,min=1e9,p=0;
        for(auto n: numsDivide){
            ans = __gcd(n,ans);
        }
        for(auto n: nums){
            if(ans%n==0 && n<min)
                min=n;
        }
        cout<<ans;
        if(min!=1e9){
        for(auto n: nums){
            if(n<min && nums.size()>1)
             count++;
            if(n==min)
                p++; 
        }
        }
        else{
            for(auto n: nums){
            if(n<ans && nums.size()>1)
             count++;
            if(n==ans)
                p++; 
        }
            }
        
        if(count>0 || p>0)
            return count;
        return -1;    
    }
};
