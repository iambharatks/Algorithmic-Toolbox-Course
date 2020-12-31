#include <iostream>
#include <string>
#include <vector>
using std::string;
using namespace std;
int n, m;
int edit_distance(const string &str1, const string &str2)
{
  //write your code here
  int n = str1.size();
  int m = str2.size();
  vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

  for (int i = 1; i <= n; i++)
    dp[i][0] = i;
  for (int j = 1; j <= m; ++j)
    dp[0][j] = j;
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= m; j++)
    {
      dp[i][j] = min(min(dp[i - 1][j] + 1, dp[i][j - 1] + 1), dp[i - 1][j - 1] + (str1[i - 1] != str2[j - 1]));
    }
  }
  return dp[n][m];
}

int main()
{
  string str1;
  string str2;
  std::cin >> str1 >> str2;
  n = str1.size();
  m = str2.size();
  std::cout << edit_distance(str1, str2) << std::endl;
  return 0;
}
