
class Solution {
    private:
    class Transaction{
    public:
        string name, city;
        int time, amount;

        Transaction(vector<string> result):
            name(result[0]), time(stoi(result[1])), amount(stoi(result[2])), city(result[3]){}
    };

    vector<Transaction> vec;
public:
    vector<string> invalidTransactions(vector<string>& transactions) {
       map<string,vector<int>> mp;
        vector<string> ans;
        for(const string& s: transactions)
            vec.push_back(getTransaction(s));

        for(int i = 0; i < vec.size(); i ++)
            if(vec[i].amount > 1000 || suspicious(i))
                ans.push_back(transactions[i]);    
        return ans; 
   }
   private:
    bool suspicious(int index){

        for(int i = 0; i < vec.size(); i ++)
            if(i != index &&
               vec[i].name == vec[index].name &&
               vec[i].city != vec[index].city &&
               abs(vec[i].time - vec[index].time) <= 60) return true;
        return false;
    }
   private:
   Transaction getTransaction(string s){
       vector<string> result;
            stringstream s_stream(s); //create string stream from the string
            while(s_stream.good()) {
                string substr;
                getline(s_stream, substr, ','); //get first string delimited by comma
                result.push_back(substr);
            }  
            return Transaction(result);
   }
};
