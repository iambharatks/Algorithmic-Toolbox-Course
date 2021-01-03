#include <iostream>
#include <vector>

using std::vector;

int partition3(vector<int> &A)
{
  //write your code here
  int sum = 0;
  int n = A.size();
  for (int i : A)
    sum += i;
  if (sum % 3)
    return false;
  vector<vector<bool>> dp(sum / 3 + 1, vector<bool>(n, 0));
  for (int i = 0; i <= n; i++)
    dp[0][i] = true;
  for (int i = 0; i <= sum / 3; i++)
    dp[i][0] = false;
  for (int i = 1; i <= sum / 3; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      if (i >= A[j - 1])
        dp[i][j] = dp[i][j - 1] || dp[i - A[j - 1]][j - 1];
      else
        dp[i][j] = dp[i][j - 1];
    }
  }
  // for (int i = 1; i <= sum / 3; i++)
  // {
  //   for (int j = 1; j <= n; j++)
  //     if (dp[i][j])
  //       std::cout << i << " " << j << "\n";
  // }
  return dp[sum / 3][n];
}

int main()
{
  int n;
  std::cin >> n;
  vector<int> A(n);
  for (size_t i = 0; i < A.size(); ++i)
  {
    std::cin >> A[i];
  }
  std::cout << partition3(A) << '\n';
}
