#include <iostream>
#include <vector>

using std::vector;

int optimal_weight(int W, const vector<int> &w)
{
  //write your code here
  int current_weight = 0;
  int n = w.size();
  vector<vector<int>> dp(W + 1, vector<int>(n + 1, 0));
  for (int j = 1; j <= W; j++)
  {
    for (int i = 1; i <= n; i++)
    {
      dp[j][i] = dp[j][i - 1];
      if (w[i - 1] <= j)
        dp[j][i] = std::max(dp[j - w[i - 1]][i - 1] + w[i - 1], dp[j][i]);
    }
  }
  return dp[W][n];
}

int main()
{
  int n, W;
  std::cin >> W >> n;
  vector<int> w(n);
  for (int i = 0; i < n; i++)
  {
    std::cin >> w[i];
  }
  std::cout << optimal_weight(W, w) << '\n';
}
