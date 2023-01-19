class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        map<int,vector<int>> mp;
        int n=cards.size(),dif,min=1e9;
        for(int i=0;i<n;i++){
            mp[cards[i]].push_back(i);
        }
        for(auto it: mp){
            if(it.second.size()>=2){
                for(int i=1;i< it.second.size();i++){
                    dif=it.second[i]-it.second[i-1];
                    if(dif<min)
                        min=dif;
                }  
            }  
        }
        if(min==1e9)
           return -1;
        return min+1;   
    }
};
