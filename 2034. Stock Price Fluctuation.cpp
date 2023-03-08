class StockPrice {
public:
map<int,int> mp;
multiset<int> ms;
    StockPrice() {
        
    }
    
    void update(int timestamp, int price) {
        if(const auto it = mp.find(timestamp); it != mp.end()){
            ms.erase(ms.find(it->second));
        }
        mp[timestamp]=price;
        ms.insert(price);
    }
    
    int current() {
        auto it = mp.rbegin();
        return it->second;
    }
    
    int maximum() {
        return *rbegin(ms);
        
    }
    
    int minimum() {
        return *begin(ms);
        
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */
