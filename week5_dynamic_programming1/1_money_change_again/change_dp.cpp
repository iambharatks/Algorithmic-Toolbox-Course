#include <iostream>
#include <math.h>
using namespace std;
const int N = 10000;
int dp[N];

int get_change(int m)
{
  //write your code here
  dp[0] = 0;
  dp[1] = 1;
  dp[2] = 2;
  dp[3] = 1;
  dp[4] = 1;

  for (int i = 5; i <= m; i++)
  {
    dp[i] = min(min(dp[i - 1] + 1, dp[i - 3] + 1), dp[i - 4] + 1);
  }
  return dp[m];
}

int main()
{
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
