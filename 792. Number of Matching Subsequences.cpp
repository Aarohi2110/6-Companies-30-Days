class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        map<char,vector<int>> mp;
        int count=0;

        for(int i=0;i<s.size();i++){
            mp[s[i]].push_back(i);
        }

       for(int i=0;i<words.size();i++){ 
           int lastindex=-1;
           bool is_substr=true;
            for(char w :words[i]){
                auto it = upper_bound(mp[w].begin(), mp[w].end(), lastindex);
                if(it== mp[w].end()){
                    is_substr=false;
                        break;
                }
                else{
                cout<<*it<<" ";
                lastindex=*it; 
                }  
            }
       if(is_substr)
            count++; 
       }
       return count;

    }
};
