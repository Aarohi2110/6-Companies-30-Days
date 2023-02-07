class Solution {
private:
     int dir[8][2]={{2,-1},{2,1},{-2,-1},{-2,1},{-1,2},{1,2},{-1,-2},{1,-2}}; 
     map<string,double> mp;
public:
    double knightProbability(int n, int k, int row, int column) {
        return find(n,k,row,column);
 }
 private:
    double find(int n, int k, int r, int c){
        if(!isValid(r,c,n))
            return 0;
        if(k==0)
            return 1;    
        string key=to_string(r)+"_"+to_string(c)+"_"+to_string(k);
        double prob=0;
        if(mp.find(key)!=mp.end())
            return mp[key];
        for(int i=0;i<8;i++){
            prob+=find(n,k-1,r+dir[i][0],c+dir[i][1])/8.0;
        }
        mp.insert({key,prob});
        return prob;
    }
    bool isValid(int r,int c,int n){
        if(r>=n || r<0 || c>=n || c<0)
            return false;
        return true;    
    }
};
