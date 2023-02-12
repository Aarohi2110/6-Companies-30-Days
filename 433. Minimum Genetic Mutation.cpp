//BFS traversal
class Solution {
 public:
  int minMutation(string start, string end, vector<string>& bank) {
    unordered_set<string> bankSet{bank.begin(), bank.end()};
    if (!bankSet.count(end))
      return -1;

    queue<pair<string,int>> q{{make_pair(start,0)}};
    vector<string> visited={start};
    while (!q.empty()) {
        string word = q.front().first;
        int level=q.front().second;
        //cout<<word<<level;
            q.pop();
        if (word == end)
             return level; 
        for (int j = 0; j < word.length(); ++j) {
          string cache = word;
          for (const char c : {'A', 'C', 'G', 'T'}) {
            cache[j] = c;
    if (bankSet.find(cache)!=bankSet.end() && find(visited.begin(),visited.end(),cache)==visited.end()){
              q.push(make_pair(cache,level+1));
              visited.push_back(cache);
            }
          }
          
    }
     }

    return -1;
  }
};

    
