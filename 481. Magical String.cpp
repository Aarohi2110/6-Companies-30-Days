class Solution {
public:
    int magicalString(int n) {
        string s="122";
        int c=1,k=2,count=1;
        if(n<=3){
            return 1;
        }
        while(s.size()<n){
            //cout<<s<<" ";
            if(k%2==0){
                if(s[k]=='1'){
                    s+="1";
                    count+=1;
                }
                else{
                    s+="11";
                    if(s.size()>n)
                        return count+1;
                    count+=2;
                }   
            }
            else{
                if(s[k]=='1')
                    s+="2";
                else
                    s+="22" ;
            }
            k++;
        }
        //cout<<s;
        return count;
    }
};
