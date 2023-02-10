class Solution {
public:
  long long maxMatrixSum(vector<vector<int>>& matrix) {
    const int n = matrix.size();
    long long ans = 0;
    int count = 0;
    int lo = INT_MAX;
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j) {
        ans += abs(matrix[i][j]);
        lo = min(lo, abs(matrix[i][j]));
        count += matrix[i][j] < 0;          
      }    
    return ans - (count & 1) * 2 * lo;
  }
};
