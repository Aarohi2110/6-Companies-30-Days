class Solution {
public:
    bool isPossible(vector<int>& nums) {
        map<int,int> mp,hp;
        for(auto n:nums){
            mp[n]++;
        }
        for(auto n:nums){
            if(mp[n]>0){
                cout<<n;
                if(hp[n]>0){
                    cout<<n;
                    hp[n]--;mp[n]--;
                    hp[n+1]++;
                }
                else if(mp[n+1] && mp[n+2]){
                    mp[n]--;mp[n+1]--;mp[n+2]--;
                    hp[n+3]++;
                }
                else
                    return false;    
            }
        }
        return true;
    }
};
