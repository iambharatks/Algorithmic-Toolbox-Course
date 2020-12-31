#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using std::make_pair;
using std::pair;
using std::unordered_map;
using std::vector;

unordered_map<int, int> fast_count_segments(vector<int> starts, vector<int> ends, vector<int> points)
{
  unordered_map<int, int> c;

  //write your code here
  vector<pair<int, int>> pairs;
  pairs.reserve(starts.size() * 2 + points.size());
  for (int i : starts)
  {
    pairs.push_back({i, 1});
  }
  for (int i : ends)
  {
    pairs.push_back({i, 3});
  }
  for (int i : points)
  {
    pairs.push_back({i, 2});
  }
  sort(pairs.begin(), pairs.end());
  int converge = 0;
  for (pair<int, int> i : pairs)
  {
    if (i.second == 1)
    {
      converge++;
    }
    else if (i.second == 3)
    {
      converge--;
    }
    else
    {
      c[i.first] = converge;
    }
  }
  return c;
}

vector<int> naive_count_segments(vector<int> starts, vector<int> ends, vector<int> points)
{
  vector<int> cnt(points.size());
  for (size_t i = 0; i < points.size(); i++)
  {
    for (size_t j = 0; j < starts.size(); j++)
    {
      cnt[i] += (starts[j] <= points[i] && points[i] <= ends[j]);
    }
  }
  return cnt;
}

int main()
{
  int n, m;  
  std::cin >> n >> m;
  vector<int> starts(n), ends(n);
  for (size_t i = 0; i < starts.size(); i++)
  {
    std::cin >> starts[i] >> ends[i];
  }
  vector<int> points(m);
  for (size_t i = 0; i < points.size(); i++)
  {
    std::cin >> points[i];
  }
  //use fast_count_segments
  unordered_map<int, int> cnt = fast_count_segments(starts, ends, points);
  for (int i : points)
  {
    std::cout << cnt[i] << " ";
  }
  std::cout << "\n";
}
