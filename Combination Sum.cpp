class Solution {
public:
vector<vector<int>> result;
   void Csum(int start, vector<int> &temp,int k,int n){
        if(temp.size()==k){
            if(n==0)
               result.push_back(temp);
                return;
            }    
            for(int i=start;i<=9;i++){
                temp.push_back(i);
                Csum(i+1,temp,k,n-i);
                temp.pop_back();
            }
        }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> temp;
        Csum(1,temp, k, n);
            return result;
    }
};
