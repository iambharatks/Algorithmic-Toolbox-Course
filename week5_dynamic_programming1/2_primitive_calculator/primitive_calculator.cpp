#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> optimal(int n)
{
  vector<int> sequence;
  int i = 1, cnt = 0;
  ;
  sequence.push_back(i);
  while (i != n)
  {
    if (i * 3 <= n)
    {
      i *= 3;
      sequence.push_back(i);
    }
    else if (i * 2 <= n)
    {
      i *= 2;
      sequence.push_back(i);
    }
    else
    {
      i += 1;
      sequence.push_back(i);
    }
  }
  return sequence;
}
int dp[1000001];
vector<int> optimal_sequence(int n)
{
  dp[2] = dp[3] = 1;
  for (int i = 4; i <= n; i++)
  {
    int _1, _2, _3;
    _1 = _2 = _3 = INT8_MAX;
    if (i % 3 == 0)
      _3 = dp[i / 3] + 1;

    if (i % 2 == 0)
      _2 = dp[i / 2] + 1;
    _1 = dp[i - 1] + 1;
    dp[i] = min(min(_1, _2), _3);
  }
  // cout << dp[n] << " ";
  vector<int> sequence;
  sequence.push_back(n);
  for (int i = n; i >= 2;)
  {
    int _1, _2, _3;
    _1 = _2 = _3 = INT8_MAX;
    if (i % 3 == 0)
      _3 = dp[i / 3];

    if (i % 2 == 0)
      _2 = dp[i / 2];
    _1 = dp[i - 1];
    if (_3 <= _2 && _1 >= _3)
      i /= 3;
    else if (_1 >= _2 && _2 <= _3)
      i /= 2;
    else
      i--;
    sequence.push_back(i);
  }
  reverse(sequence.begin(), sequence.end());
  return sequence;
}

int main()
{
  int n;
  std::cin >> n;
  vector<int> sequence = optimal_sequence(n);
  std::cout << sequence.size() - 1 << std::endl;
  for (size_t i = 0; i < sequence.size(); ++i)
  {
    std::cout << sequence[i] << " ";
  }
}
