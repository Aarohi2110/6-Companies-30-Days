class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
            vector<int> v=nums;
            int l=0,r=0;
        sort(v.begin(),v.end());
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=v[i]){
                l=i;
                break;
            }
        }  
        for(int i=nums.size()-1;i>=0;i--){
            if(nums[i]!=v[i]){
                r=i;
                break;
            }
        } 
        if(l==0 && r==0)
            return 0;

        return r-l+1;   
    }
};
